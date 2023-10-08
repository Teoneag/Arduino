#include "gamepad.h"
#include "motor.h"
#include "servo.h"

Gamepad gamepad = Gamepad(); 
Motor motor = Motor();
my_servo servo = my_servo();

const int MAX_SPEED = 255;
const int NORMAL_SPEED = 60;
const int MIN_SPEED = 40;

void setup() {
    Serial.begin(115200);
    motor.init();
    servo.init();
}

void loop() {
  gamepad.update();
  
  int speed = NORMAL_SPEED;
  if (gamepad.isPressed(b) || gamepad.isPressed(right_trigger)) speed = MAX_SPEED;
  else if (gamepad.isPressed(a) || gamepad.isPressed(left_trigger)) speed = MIN_SPEED;

  if (gamepad.isPressed(dpad_up))
    {
    motor.setLeft(speed);
    motor.setRight(speed);
    }
  else if (gamepad.isPressed(dpad_down))
    {
    motor.setLeft(-speed);
    motor.setRight(-speed);
    }
  else if (gamepad.isPressed(dpad_left))
    {
    motor.setLeft(-MIN_SPEED);
    motor.setRight(+MIN_SPEED);
    }
  else if (gamepad.isPressed(dpad_right))
    {
    motor.setLeft(+MIN_SPEED);
    motor.setRight(-MIN_SPEED);
    }
  else {
    speed = -speed;
  motor.setLeft(gamepad.getLeftY()*speed/MAX_SPEED);
  motor.setRight(gamepad.getRightY()*speed/MAX_SPEED);
  }
  
  if (gamepad.isPressed(left_bumper) || gamepad.isPressed(y) ) {
    servo.rotate_up();
    Serial.print(servo.angle);
  }
  else if (gamepad.isPressed(right_bumper) || gamepad.isPressed(x)) {
    servo.rotate_down();
    Serial.print(servo.angle);
  }

}

