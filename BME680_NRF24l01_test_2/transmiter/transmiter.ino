/*
Combination between this
https://theorycircuit.com/bme680-arduino/
and this
https://www.circuits-diy.com/nrf24l01-wireless-rf-transceiver-module-working-interface-with-arduino-uno/
+ my onw code
SOmetimes it works, when u thouch the rx stops working 
How?
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"

Adafruit_BME680 bme(2, 3, 4, 5);  // CS, MOSI, MISO, SCK

RF24 radio(9, 10);  // CE, CSN; 11: MOSI; 12: MISO; 13: SCK

const byte address[6] = "00001";

struct data {
  int nr = 0;
  double t;
} data;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening();
  Serial.println("Start transmiting!");
}

void loop() {
  if (!bme.begin()) {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    data.t = -69.69;
  } else {
    if (!bme.performReading()) {
      Serial.println("Failed to read data from BME680 :(");
      data.t = -69.69;
    } else {
      data.t = bme.temperature;
    }
  }
  Serial.println("Sending: t = " + String(data.nr) + ", " + String(data.t) + " *C");
  radio.write(&data, sizeof(data));
  data.nr++;
  delay(1000);
}