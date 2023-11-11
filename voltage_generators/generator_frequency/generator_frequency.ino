#include <util/delay.h>

int OscilationPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(OscilationPin, OUTPUT);
}

void loop() {

  for(int f=0; f<256; f++)
  {
    analogWrite(OscilationPin, f);
    _delay_ms(0.1);
  }

  for(int f=256; f>0; f--)
  {
    analogWrite(OscilationPin, f);
    _delay_ms(0.1);
  } 
}
