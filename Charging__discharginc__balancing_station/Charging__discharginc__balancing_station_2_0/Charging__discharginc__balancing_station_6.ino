#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int Poz1, Poz2;

unsigned long long StartTimePrint, LastTimeButtonPressed, LastTimePrint;

String HiMessage = "Hi...", IntroMessage = "This is Teon's accumulator charger, discharger and balancer!                ";;

/*
lcd.print(str.substring(poz, poz + 15));
poz = ++poz % (str.length() - 15);
*/

void PowerSave()
{
  if (digitalRead(8) == HIGH || digitalRead(9) == HIGH || digitalRead(10) == HIGH) LastTimeButtonPressed = millis();
  if (millis() - LastTimeButtonPressed > 10000) lcd.noDisplay();
  else lcd.display();
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(7, OUTPUT);
  lcd.blink();

  Poz1 = 0, StartTimePrint = millis();
  while (millis() - StartTimePrint < 500 * (HiMessage.length() + 1))
  {
    if (millis() - LastTimePrint > 500)
      lcd.setCursor(0, 0), lcd.print(HiMessage.substring(0, Poz1++)), LastTimePrint = millis();
    if (digitalRead(8) == HIGH) {
      break;
      LastTimeButtonPressed = millis();
    }
    PowerSave();
  }
  while(millis() - LastTimePrint < 200){}
  lcd.setCursor(0, 1), lcd.print("   (Press ok)");

  delay(5000);
  Poz1 = 0, StartTimePrint = millis();
  while (millis() - StartTimePrint < 2 * 200 * (IntroMessage.length() + 1))
  {
    if (millis() - LastTimePrint > 200)
      lcd.setCursor(0, 0), lcd.print(IntroMessage.substring(Poz1, Poz1 + 15)),  Poz1 = ++Poz1 % (IntroMessage.length() - 15), LastTimePrint = millis();
    if (digitalRead(8) == HIGH) {
      break;
      LastTimeButtonPressed = millis();
    }
    PowerSave();
  }
}

void loop() {

}
