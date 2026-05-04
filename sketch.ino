#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// Configurações de Wi-Fi do Wokwi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Configurações do Broker MQTT
const char* mqtt_server = "broker.hivemq.com";

// Pinos dos Sensores
#define DHTPIN 15
#define DHTTYPE DHT22
#define LDRPIN 34

DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  // Conectando ao Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado ao Wi-Fi!");

  client.setServer(mqtt_server, 1883);
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    if (client.connect("ESP32_Anthony_Project")) {
      Serial.println("conectado!");
    } else {
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  // Leitura dos sensores
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int ldrValue = analogRead(LDRPIN);

  if (isnan(t) || isnan(h)) {
    Serial.println("Erro ao ler o DHT!");
  } else {
    // Publicando no MQTT
    char msg[50];
    sprintf(msg, "{\"temp\": %.2f, \"umid\": %.2f, \"luz\": %d}", t, h, ldrValue);
    Serial.print("Enviando: ");
    Serial.println(msg);
    
    client.publish("fiap/anthony/sensores", msg);
  }

  delay(5000); // Envia a cada 5 segundos
}