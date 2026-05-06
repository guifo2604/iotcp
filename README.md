## Anthony de Souza Henriques, RM 566188; Guilherme Santos Fonseca, RM 564232; Gustavo Araujo da Silva, RM 566526

---
---


# 📡 Monitoramento Inteligente com IoT

## 📌 Descrição
Este projeto consiste em um sistema de monitoramento utilizando Internet das Coisas (IoT), capaz de coletar, transmitir, processar, armazenar e visualizar dados em tempo real.

---

## 🎯 Objetivo
Monitorar variáveis ambientais como temperatura, umidade e luminosidade, integrando também dados externos de uma API de clima.

---

## 🏗️ Arquitetura do Sistema

ESP32 → MQTT → Node-RED → Dashboard + MySQL + API externa

---

## ⚙️ Tecnologias Utilizadas

- ESP32
- MQTT (HiveMQ)
- Node-RED
- MySQL
- OpenWeather API
- Wokwi (simulação)

---

## 🔌 Sensores Utilizados

### DHT22
- Mede temperatura (°C)
- Mede umidade (%)

### LDR
- Mede luminosidade (valor analógico)

---

## 🔄 Funcionamento

1. O ESP32 realiza a leitura dos sensores
2. Os dados são enviados via MQTT no formato JSON:

```json
{
  "temp": 25.5,
  "umid": 60.2,
  "luz": 300
}
```
## 🔬 Simulação no Wokwi

A simulação do circuito pode ser acessada no link abaixo:

👉 https://wokwi.com/projects/462746973223356417

O ambiente simula o ESP32 com os sensores DHT22 e LDR, permitindo visualizar o funcionamento do sistema sem necessidade de hardware físico.

## Link do vídeo no youtube
👉 https://youtu.be/RUf0nqWZp1E
