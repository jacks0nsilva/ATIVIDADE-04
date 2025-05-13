# 🌱 Residência Inteligente com BitDogLab

Este projeto é um sistema de automação residencial focado no controle inteligente da iluminação de um jardim. Utilizando a placa BitDogLab e conectividade Wi-Fi, o sistema acende ou apaga as luzes automaticamente com base na luminosidade e envia alertas em caso de presença detectada nas entradas da residência. O controle e monitoramento podem ser realizados remotamente por meio de uma interface web.

## 🎯 Objetivo

Desenvolver um sistema de automação com funcionalidades de:

- Controle automático por luminosidade.
- Modo manual acessível via página web.
- Alerta visual por presença em até duas entradas.
- Monitoramento em tempo real.

## ⚙️ Como Funciona

O projeto possui dois modos principais de operação:

### 🔁 Modo Automático

- Um fotorresistor (simulado pelo eixo X do joystick) monitora a luminosidade do ambiente.
- As luzes do jardim são acesas se a luminosidade for inferior a 30% e apagadas quando a luminosidade é maior.
- Esse modo economiza energia e garante iluminação noturna eficiente.

### 🧭 Modo Manual

- O usuário pode ativar ou desativar as luzes manualmente via página web.
- Também é possível ativar ou desativar o modo automático.

### 🚨 Alerta por Presença

- Os botões A e B simulam sensores de presença HC-SR501.
- Ao detectar presença (botão pressionado), o sistema aciona um alerta visual com o LED vermelho piscando.
- A interface web é atualizada em tempo real com o status do alerta.

## 🔌 Periféricos Utilizados

- **Joystick (eixo X):** Simula sensor de luminosidade.
- **Botões A e B:** Simulam sensores de presença.
- **LED RGB:**
  - LED azul: luz do jardim.
  - LED vermelho: alerta de presença.
- **Display OLED:** Pode exibir informações de estado.
- **Interrupções:** Usadas para detectar o acionamento dos sensores (botões).
- **Conectividade Wi-Fi:** Permite controle e monitoramento via servidor web local.

## 🧩 Estrutura do Código

### Principais Funções

- `init_gpio_bitdog()`: Inicializa GPIOs da BitDogLab para LEDs e botões.
- `gpio_irq_handler(uint gpio, uint32_t events)`: Função de interrupção para detectar presença.
- `alert_lights()`: Acende e pisca o LED vermelho quando há alerta de presença.
- `verify_luminosity()`: Lê o valor de luminosidade ambiente simulado.
- `control_lights(uint16_t luminosity_value)`: Acende ou apaga a luz do jardim com base na luminosidade.
- `init_display()`: Inicializa o display OLED.
- `tcp_server_accept()`: Aceita conexões TCP para o servidor web.
- `tcp_server_recv()`: Processa as requisições HTTP dos usuários.
- `user_request(char **request)`: Analisa e trata os comandos enviados pela interface web.

## 🌐 Interface Web

A página HTML permite:

- Visualizar o estado da luminosidade e do alerta.
- Alternar entre modo automático e manual.
- Acender ou apagar as luzes manualmente.
