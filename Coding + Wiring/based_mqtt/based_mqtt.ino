#include <WiFi.h>
#include <PubSubClient.h>  

// Konfigurasi WiFi  
const char* ssid = "SSID WIFI";  
const char* password = "PASSWORD"; 

// Konfigurasi MQTT  
const char* mqtt_server = "broker.emqx.io"; // Ganti dengan IP lokal jika pakai Mosquitto  
const int mqtt_port = 1883;  

WiFiClient espClient;  
PubSubClient client(espClient);  

void setup_wifi() {  
  delay(10);  
  Serial.println("Menghubungkan ke WiFi...");  
  WiFi.begin(ssid, password);  

  while (WiFi.status() != WL_CONNECTED) {  
    delay(500);  
    Serial.print(".");  
  }  
  Serial.println("\nTerhubung ke WiFi!");  
}  

void reconnect() {  
  while (!client.connected()) {  
    Serial.println("Menghubungkan ke Broker MQTT...");  
    if (client.connect("ESP32Client")) {  
      Serial.println("Terhubung ke Broker!");  
    } else {  
      Serial.print("Gagal, error: ");  
      Serial.print(client.state());  
      Serial.println(" Coba lagi dalam 5 detik...");  
      delay(5000);  
    }  
  }  
}  

void setup() {  
  Serial.begin(115200);
  setup_wifi();  
  client.setServer(mqtt_server, mqtt_port);  
 
}  

void loop() {  
  if (!client.connected()) {  
    reconnect();  
  }  
  client.loop();  


}
