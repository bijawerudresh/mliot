#define BLYNK_TEMPLATE_ID "TMPL3s1EOQprJ"
#define BLYNK_TEMPLATE_NAME "sahil"
#define BLYNK_AUTH_TOKEN "1P7pnESvaQR6WCOOdMe0KICnLVnkIj28"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"


#define DHTPIN 4    
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

char auth[] = "1P7pnESvaQR6WCOOdMe0KICnLVnkIj28";   
char ssid[] = "Sahil";       
char pass[] = "1234567890";  


BlynkTimer timer;

void sendSensorData()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("⚠️ Failed to read from DHT sensor!");
    return;
  }

 
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" °C | Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  
  Blynk.virtualWrite(V0, t);  
  Blynk.virtualWrite(V1, h);  
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  dht.begin();
  Blynk.begin(auth, ssid, pass);

 
  timer.setInterval(2000L, sendSensorData);

  Serial.println("✅ Blynk DHT11 ESP32 Project Started!");
}

void loop()
{
  Blynk.run();
  timer.run();
}