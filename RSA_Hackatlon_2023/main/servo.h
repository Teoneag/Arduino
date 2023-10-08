#include <Servo.h>

class my_servo {
  public:
    void init();
    void rotate_up();
    void rotate_down();
    float angle;

  private:
    Servo servo;
};