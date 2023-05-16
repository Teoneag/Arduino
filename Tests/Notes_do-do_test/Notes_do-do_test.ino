void setup() {
  pinMode(3,OUTPUT);
}
 
void loop() {
  tone (3,294);
  delay (1000);
  tone(3,330);
  delay(1000);
  tone (3,349);
  delay (1000);
  tone(3,392);
  delay(1000);
  tone (3,440);
  delay (1000);
  tone(3,494);
  delay(1000);
  tone (3,523);
  delay (1000);
  tone(3,587);
  delay(1000);
  pinMode(3,LOW);
  delay(2000);
}
