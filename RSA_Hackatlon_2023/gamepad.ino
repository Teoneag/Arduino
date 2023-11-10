bool Gamepad::isPressed(Buttons b) {
  return buttonState[b];
}

bool Gamepad::onPress(Buttons b) {
  return buttonState[b] && !lastButtonState[b];
}

int8_t Gamepad::getLeftX() {
  return joystickState[0];
}
int8_t Gamepad::getLeftY() {
  return joystickState[1];
}
int8_t Gamepad::getRightX() {
  return joystickState[2];
}
int8_t Gamepad::getRightY() {
  return joystickState[3];
}

Gamepad::Gamepad() {
  currentController = 0;

  softSerial.begin(115200);
}

void Gamepad::update()  {
  memcpy(lastButtonState, buttonState, 12);
  uint32_t time_stop = millis() + 20;
  do{
  if (softSerial.available()) {
    int8_t c = softSerial.read();
    //Serial.print(c);
    if (c == 127) { // 127 is flag byte for command. If we encounter flag byte, process everything in command buffer
      //Serial.println();

      if (pos != 16) { // If we happen to be offset (shouldn't happen, unless bluetooth fcks up)
        Serial.print("ERROR : command was not of length 16, instead was ");
        Serial.println(pos);
        pos = 0;
        return;
      }

      for (int i = 0; i < 12; i++) {
        buttonState[i] = command[i]; // Bytes from 0 to 11 are button states
      }
      for (int i = 0; i < 4; i++) {
        joystickState[i] = command[12+i]; // Bytes from 12 to 15 are joystick values
      }

      pos = 0;

    } else { // Else append to command buffer
      if (pos < 16) command[pos] = c;
      pos++;
    }
  }
  }while(millis() < time_stop);
    
  // Serial.print("Button state : ");
  // for (int8_t s : buttonState) {
  //   Serial.print(s);
  // }
  // Serial.println();

}