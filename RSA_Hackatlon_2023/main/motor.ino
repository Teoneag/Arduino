void Motor::init() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
}

void Motor::setLeft(int speed) {
  if(speed > 5){
    digitalWrite(5, LOW);
    // digitalWrite(3, HIGH);
    analogWrite(3, speed);
  }else if(speed < -5){
    digitalWrite(3, LOW);
    // digitalWrite(5, HIGH);

    analogWrite(5, -speed);
  }else{
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
  }
}

void Motor::setRight(int speed) {
  if(speed > 5){
    digitalWrite(11, LOW);
    analogWrite(6, speed);
    // digitalWrite(6, HIGH);
  }else if(speed < -5){
    digitalWrite(6, LOW);
    // digitalWrite(9, HIGH);
    analogWrite(11, -speed);
  }else{
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
  }
}