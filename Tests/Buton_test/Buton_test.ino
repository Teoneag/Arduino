const int buton1 = 13;
int a1 = 0;

void setup() {
  pinMode(buton1, INPUT);
  Serial.begin(9600);
}
void loop() {
  if (digitalRead(buton1) == LOW) {
    a1++;
    Serial.print("Butonul 1 s-a apasat butonul de ");
    Serial.print(a1, DEC);
    Serial.print(" ori.");
    Serial.println();
    delay(200); //debouncing software
  }

}
