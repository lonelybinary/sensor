/*
   DHT-22 Temperature and humidity sensor

   Install Library
      >> Open Manage Libaraies in Arduine IDE by press Ctrl + Shift + I
      >> Search “DHT22”
      >> Install DHT Sensor Library by Adafruist

   Wiring
   DHT22 +    ---> UNO R3 5V
   DHT22 -    ---> UNO R3 GND
   DHT22 OUT  ---> UNO R3 7

*/

#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

}

