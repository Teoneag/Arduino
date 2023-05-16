void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3000; i++)
  {
    tone(10, i);
    delay(10);
  }
  for (int i = 3000; i > 0; i--)
  {
    tone(10, i);
    delay(10);
  }
}
