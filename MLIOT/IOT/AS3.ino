#define BLYNK_TEMPLATE_ID "TMPL3soilID"      
#define BLYNK_TEMPLATE_NAME "Soil Monitoring"
#define BLYNK_AUTH_TOKEN "YourAuthTokenHere"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define SOIL_PIN 34 


char auth[] = "YourAuthTokenHere";
char ssid[] = "YourWiFiName";
char pass[] = "YourWiFiPassword";

BlynkTimer timer;

void sendSoilData()
{
  int sensorValue = analogRead(SOIL_PIN);
  float moisturePercent = map(sensorValue, 0, 4095, 100, 0);

  Serial.print("Analog Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  
  Blynk.virtualWrite(V0, moisturePercent);
}

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("🌱 Soil Moisture Monitoring Started...");

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2000L, sendSoilData);
}

void loop()
{
  Blynk.run();
  timer.run();
}
