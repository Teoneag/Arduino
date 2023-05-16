/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

char incomingByte = 0;
int choice = 0;

void loop() {
  // for (int i = 1; i <= 180; i++) {
  //   myservo.write(i);  // sets the servo position according to the scaled value
  //   delay(10);
  // }
  // for (int i = 179; i >= 0; i--) {
  //   myservo.write(i);
  //   delay(10);
  // }
  // myservo.write(90);
  // delay(1000);
  // myservo.write(180);
  // delay(1000);
  // myservo.write(0);
  // delay(1000);
  
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    choice = (incomingByte - '0') * 180 / 9;
    if (choice >= 0 && choice <= 180) {
      Serial.println(choice);
      myservo.write(choice);
    }
  }
}
