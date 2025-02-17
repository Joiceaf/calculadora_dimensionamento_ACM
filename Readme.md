# Cálculo de ACM com Raspberry Pi Pico W

## Descrição do Projeto
Este projeto utiliza a Raspberry Pi Pico W e um joystick analógico para calcular a quantidade de ACM necessária para o revestimento de uma fachada. O usuário pode selecionar entre um modelo 2D ou 3D, inserir valores utilizando o joystick e visualizar o resultado no monitor serial. LEDs indicam o processamento do cálculo e a finalização do processo.

## Modelagem Matemática
A modelação matemática envolve a determinação da quantidade exata de ACM necessária para cobrir uma fachada com 4 dobras no ACM, considerando a espessura da chapa e da fita adesiva. A função de cálculo é baseada nos parâmetros fornecidos pelo usuário, garantindo que a medição seja precisa e considerando uma margem de sobra para fixação.

### Etapas da Modelagem Matemática
Baseado na perspectiva de Biembengut (1990), a modelagem matemática segue três etapas:
1. **Interação** – Reconhecimento da situação-problema e familiarização com o assunto a ser modelado.
2. **Matematização** – Definição das variáveis relevantes e construção da equação.
3. **Modelo Matemático** – Interpretação da solução e validação do modelo.

### Modelagem no cálculo do perímetro do ACM
1. **Interação:** Identificação do problema e estudo sobre a necessidade de cálculo do ACM.
2. **Matematização:** Definição das variáveis (dimensões da fachada, espessuras e margem de fixação) e construção da equação.
3. **Modelo Matemático:** Construção e validação da função a partir de testes e cálculos aplicáveis.

O cálculo segue as fórmulas matemáticas:
- **Modelo 2D:** (cm) *(definir a fórmula específica)*
- **Modelo 3D:** (cm) *(definir a fórmula específica)*

Essas funções foram definidas a partir de análises geométricas da fachada e das necessidades de material.

## Desenvolvimento

### Definição dos Dados de Entrada
Os valores são inseridos pelo usuário através do joystick analógico (todos os valores devem ser fornecidos em centímetros):
- **Botão A e B:** Seleção do modelo (2D ou 3D)
- **Botão do Joystick:** Confirmação do valor

### Definição dos Dados de Saída
Após a entrada dos valores, o sistema:
1. Exibe os valores confirmados no monitor serial.
2. Indica o processamento através do LED de status.
3. Após o cálculo, exibe o resultado final no monitor serial e ativa um LED verde por 10 segundos.

### Definição dos Dados de Processamento
O sistema realiza as seguintes etapas:
1. Captura os valores inseridos pelo joystick.
2. Converte os valores analógicos para o formato desejado.
3. Aplica a fórmula matemática correspondente (2D ou 3D).
4. Exibe um indicador de processamento enquanto os cálculos são realizados.
5. Exibe o resultado final e reinicia o sistema para nova entrada de dados.

## Tecnologias Utilizadas
- **Hardware:** Raspberry Pi Pico W, Joystick analógico, LEDs
- **Linguagem de Programação:** C/C++
- **Ambiente de Desenvolvimento:** Arduino IDE ou VS Code + PlatformIO

## Como Executar o Projeto
1. Clone este repositório:
   ```sh
   git clone https://github.com/seu-usuario/calculo-acm-pico
   ```
2. Abra o projeto no ambiente de desenvolvimento.
3. Compile e faça o upload do código para a Raspberry Pi Pico W.
4. Conecte o monitor serial para visualizar os resultados.
5. Utilize o joystick para inserir os valores e acompanhar os cálculos em tempo real.

## Contribuição
Se deseja contribuir com melhorias, sinta-se à vontade para abrir uma *issue* ou enviar um *pull request*.

## Licença
Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

---

*Desenvolvido por [Joice Araujo Fontenele](https://github.com/Joiceaf)*
*Link do vídeo (https://youtu.be/fDFD0ou51qo?feature=shared)*
