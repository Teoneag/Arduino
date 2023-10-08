#include <Servo.h>

Servo servo = Servo();

float angle = 0;

int direction = 1;

void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  servo.write(0);
}

void loop() {
  if (angle > 70 || angle < 0) direction *= -1;
  angle += direction * 0.01;
  servo.write(angle);

}
