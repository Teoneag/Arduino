#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"

#define BME_SCK 5
#define BME_MISO 4
#define BME_MOSI 3
#define BME_CS 2

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK);

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println(F("BME680 test"));
}

void loop() {
  if (!bme.begin()) {
    Serial.println("Could not find a valid BME 68- sensor, check wiring!");
  }
  if (! bme.performReading()) {
    Serial.println("Failed to perform reading :(");
  }
  else {
    Serial.print("Temperature = "); 
    Serial.print(bme.temperature);
    Serial.println(" *C");
  }
  
  delay(1000);
}
