void setup()
{
  pinMode(11, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 100; i++)
  {
    analogWrite(11, i);
    delay (3);
  }
  for (int i = 100; i > 0; i--)
  {
    analogWrite(11, i);
    delay(3);
  }
  pinMode(11, LOW);
  delay(100);
}
