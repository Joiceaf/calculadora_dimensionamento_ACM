#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

// Definição dos pinos
#define BOTAO_A 5          // Botão para modelo 2D
#define BOTAO_B 6          // Botão para modelo 3D
#define JOYSTICK_X 26      // Eixo X do joystick (parte inteira)
#define JOYSTICK_Y 27      // Eixo Y do joystick (parte decimal)
#define BOTAO_JOYSTICK 22  // Botão do joystick (confirmação)
#define LED_PROCESSANDO 13 // LED indicador de cálculo
#define LED_CONCLUIDO 11   // LED verde de conclusão

// Função para cálculo do perímetro do painel (2D)
double calcular_painel(double x, double y)
{
    return (120 * x) + (200 * y) + 3.68;
}

// Função para cálculo do perímetro da fachada (3D)
double calcular_fachada(double x, double y, double z)
{
    return (1040 * x) + (1040 * y) + (800 * z) + 33.12;
}

// Função para ler valor do joystick
double ler_valor(int adc_pin, double min_val, double max_val)
{
    adc_select_input(adc_pin - 26);
    uint16_t raw = adc_read();
    return min_val + ((double)raw / 4095.0) * (max_val - min_val);
}

// Função para capturar entrada do usuário
double capturar_entrada(const char *variavel, int adc_int, int adc_dec)
{
    double inteiro = 1, decimal = 0.01;
    printf("Ajuste %s com o joystick e pressione o botão para confirmar.\n", variavel);

    while (1)
    {
        inteiro = (int)ler_valor(adc_int, 1, 10000);
        decimal = ler_valor(adc_dec, 0.01, 0.99);
        double valor = inteiro + decimal;

        printf("%s: %.2f\n", variavel, valor);
        sleep_ms(500);

        if (!gpio_get(BOTAO_JOYSTICK))
        {
            printf("Confirmado: %s = %.2f\n", variavel, valor);
            sleep_ms(500);
            return valor;
        }
    }
}

int main()
{
    stdio_init_all();

    // Inicializa GPIOs
    gpio_init(BOTAO_A);
    gpio_set_dir(BOTAO_A, GPIO_IN);
    gpio_pull_up(BOTAO_A);

    gpio_init(BOTAO_B);
    gpio_set_dir(BOTAO_B, GPIO_IN);
    gpio_pull_up(BOTAO_B);

    gpio_init(BOTAO_JOYSTICK);
    gpio_set_dir(BOTAO_JOYSTICK, GPIO_IN);
    gpio_pull_up(BOTAO_JOYSTICK);

    gpio_init(LED_PROCESSANDO);
    gpio_set_dir(LED_PROCESSANDO, GPIO_OUT);

    gpio_init(LED_CONCLUIDO);
    gpio_set_dir(LED_CONCLUIDO, GPIO_OUT);

    adc_init();
    adc_gpio_init(JOYSTICK_X);
    adc_gpio_init(JOYSTICK_Y);

    while (1)
    {
        printf("\nPressione A para calcular o painel (2D) ou B para a fachada (3D)\n");

        while (gpio_get(BOTAO_A) && gpio_get(BOTAO_B))
            ; // Aguarda escolha

        if (!gpio_get(BOTAO_A))
        {
            printf("\nSelecionado: Modelo 2D\n");

            double x = capturar_entrada("X", JOYSTICK_X, JOYSTICK_Y);
            double y = capturar_entrada("Y", JOYSTICK_X, JOYSTICK_Y);

            gpio_put(LED_PROCESSANDO, 1);
            printf("Calculando...\n");
            sleep_ms(3000);

            double resultado = calcular_painel(x, y);
            gpio_put(LED_PROCESSANDO, 0);
            gpio_put(LED_CONCLUIDO, 1);

            printf("\n➡ Resultado: %.2f cm\n", resultado);
            sleep_ms(10000);
            gpio_put(LED_CONCLUIDO, 0);
        }

        if (!gpio_get(BOTAO_B))
        {
            printf("\nSelecionado: Modelo 3D\n");

            double x = capturar_entrada("X", JOYSTICK_X, JOYSTICK_Y);
            double y = capturar_entrada("Y", JOYSTICK_X, JOYSTICK_Y);
            double z = capturar_entrada("Z", JOYSTICK_X, JOYSTICK_Y);

            gpio_put(LED_PROCESSANDO, 1);
            printf("Calculando...\n");
            sleep_ms(3000);

            double resultado = calcular_fachada(x, y, z);
            gpio_put(LED_PROCESSANDO, 0);
            gpio_put(LED_CONCLUIDO, 1);

            printf("\n➡ Resultado: %.2f cm\n", resultado);
            sleep_ms(10000);
            gpio_put(LED_CONCLUIDO, 0);
        }
    }

    return 0;
}
