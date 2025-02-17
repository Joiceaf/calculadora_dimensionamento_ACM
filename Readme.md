# Documentação do Projeto

## Visão Geral
Este projeto utiliza um Raspberry Pi Pico para calcular o perímetro de um painel (modelo 2D) ou de uma fachada (modelo 3D) com base nos valores fornecidos pelo usuário através de um joystick. O cálculo é acionado por botões e o progresso é indicado por LEDs.

## Hardware Utilizado
- **Raspberry Pi Pico**
- **Botões**:
  - Botão A (Pino 5): Seleciona o modelo 2D
  - Botão B (Pino 6): Seleciona o modelo 3D
  - Botão do Joystick (Pino 22): Confirma a seleção
- **Joystick**:
  - Eixo X (Pino 26): Parte inteira do valor
  - Eixo Y (Pino 27): Parte decimal do valor
- **LEDs**:
  - LED de processamento (Pino 13): Indica cálculo em andamento
  - LED de concluído (Pino 11): Indica que o cálculo foi finalizado

## Funcionalidades
1. **Seleção de modelo**: O usuário escolhe entre cálculo 2D ou 3D pressionando os botões correspondentes.
2. **Captura de valores**: O joystick é usado para ajustar os valores X, Y e, no caso 3D, Z.
3. **Confirmação**: O botão do joystick é pressionado para confirmar os valores.
4. **Cálculo do perímetro**:
   - **Painel 2D**: `120 * x + 200 * y + 3.68`
   - **Fachada 3D**: `1040 * x + 1040 * y + 800 * z + 33.12`
5. **Indicação do status**:
   - LED de processamento acende durante o cálculo.
   - LED de concluído acende quando o resultado é exibido.

## Fluxo de Execução
1. O programa aguarda o usuário pressionar o botão A (2D) ou B (3D).
2. O joystick é utilizado para definir os valores necessários.
3. O botão do joystick confirma cada valor.
4. O LED de processamento acende e o cálculo é realizado.
5. O LED de concluído acende e o resultado é exibido.
