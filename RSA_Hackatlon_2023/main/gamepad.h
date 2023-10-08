#include <SoftwareSerial.h>

enum Buttons {
  a = 0,
  b = 1,
  x = 2,
  y = 3,
  dpad_up = 4,
  dpad_down = 5,
  dpad_left = 6,
  dpad_right = 7,
  right_trigger = 8,
  left_trigger = 9,
  right_bumper = 10,
  left_bumper = 11
};

class Gamepad {
  public:
    // For users
    bool isPressed(Buttons b);

    bool onPress(Buttons b);

    int8_t getLeftX();
    int8_t getLeftY();

    int8_t getRightX();
    int8_t getRightY();

    // Internal stuff
    Gamepad();

    void update();
  

  private:
    SoftwareSerial softSerial = SoftwareSerial(10, 11);
    uint8_t currentController;

    // Commands
    int8_t command[16] = {0, 0, 0};
    uint8_t pos = 0;
    
    // Buttons
    bool buttonState[12];
    bool lastButtonState[12];

    // Joysticks
    int8_t joystickState[4];
};

/*
Bluetooth communication :
The controller sends out commands like this one (without spaces) :
gamepadid;buttonid;value;
1        ;
Buttons 0-11 correspond to the respective buttons in the Buttons enum
Buttons 12-15 correspond to the left and right joystick x and y, and have a double value
*/