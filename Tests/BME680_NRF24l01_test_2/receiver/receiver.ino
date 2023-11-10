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

RF24 radio(9, 10);  // CE, CSN; 11: MOSI; 12: MISO; 13: SCK

const byte address[6] = "00001";

struct data {
  int nr;
  double t;
} data;

unsigned long startTime = millis();

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.startListening();
  Serial.println("Start receiving!");
}

void loop() {
  if (radio.available()) {
    data.t = -69;
    radio.read(&data, sizeof(data));
    if (data.t != 0) {
      Serial.println("Receving: t = " + String(data.nr) + ", " + String(data.t) + " *C");
      startTime = millis();
    } else {
      if (millis() - startTime > 2000) {
        Serial.println("Not receving data or receving t = 0 *C :(( (usually when power not connected to RX");
        startTime = millis();
      }
    }
  } else {
    if (millis() - startTime > 2000) {
      Serial.println("Radio is not available :(( (usually pb with TX or RX not connected)");
      startTime = millis();
    }
  }
}