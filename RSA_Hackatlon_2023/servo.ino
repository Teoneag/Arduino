#include <Servo.h>
const int PIN = 9;
const int SPEED = 0.5;
const int OFFSET = 35;

void my_servo::init() {
  this->servo.attach(PIN);
  this->angle=0;-
  this->servo.write(OFFSET);
}

void my_servo::rotate_up() {
  this->angle = 70;
  this->servo.write(this->angle);
  // if (this->angle > OFFSET + 30) return;
  // this->angle += SPEED;
}

void my_servo::rotate_down() {
  
  this->angle = 0;
  this->servo.write(this->angle);
  // if (this->angle < OFFSET - 30) return;
  // this->angle -= SPEED;
}