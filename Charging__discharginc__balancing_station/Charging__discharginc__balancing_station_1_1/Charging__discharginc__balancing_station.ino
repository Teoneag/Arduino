#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int NrOfCells;
float CellVoltage[6];
float DischargeVoltage = 3.85;

String MenuFunctions[6] = {"Charge", "Discharge", "Balance", "Help", "About", "Nothing"};
int IMenuFunctions;

unsigned long long TimeOkPressed;

String ReadCells()
{
  CellVoltage[0] = analogRead(A0) * 5.0 / 1023;
  CellVoltage[1] = analogRead(A1) * 5.0 / 1023 * 1.89 - CellVoltage[0];
  CellVoltage[2] = analogRead(A2) * 5.0 / 1023 * 3 - CellVoltage[1] - CellVoltage[0];
  CellVoltage[3] = analogRead(A3) * 5.0 / 1023 * 4 - CellVoltage[2]- CellVoltage[1]- CellVoltage[0];
  NrOfCells = 0; //This needs improvement: to check nr of cells, u have 2 cases, and I've checked just the first case: Reading of a non-cell is I. 0 (so it's connected to ground), II. fluctuateing (so it's not connected to ground)
  for (int j = 0; j < 6 && analogRead(14 + j) > 50; j++)
    NrOfCells = j + 1;
  String allCells = "Cells not connected";
  if (NrOfCells > 0) allCells = "C0: " + (String)CellVoltage[0];
  for (int i = 1; i < NrOfCells; i++)
    allCells += ", C" + (String)i + ": " + (String)CellVoltage[i];
  Serial.println(allCells);
  return allCells;
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  pinMode(7, OUTPUT);

  lcd.blink();
  String hiMessage = "Hi...";
  for (int i = 0; i < hiMessage.length(); i++)
  {
    lcd.print(hiMessage[i]);
    while(millis() < i * 1000 + 1000)
      if(digitalRead(8)) break;
  }
  lcd.noBlink();
  
  lcd.setCursor(0, 1);
  lcd.print("   (Press ok)");
  while(!digitalRead(8) && millis() < 8000) {}
  delay(200);
  
  lcd.clear();
  String introMessage = "This is Teon's accumulator charger, discharger and balancer!                ";
  int poz = 0;
  lcd.setCursor(0, 1);
  lcd.print("   (Press ok)");
  for(int i = 0; i < (introMessage.length() - 15) * 2; i++)
  {
    lcd.setCursor(0, 0);
    lcd.print(introMessage.substring(poz, poz + 15));
    poz = ++poz % (introMessage.length() - 15);
    for (int j = 0; j < 300; j++)
    {
      if (digitalRead(8) == HIGH) {i = (introMessage.length() - 15) * 2; break;}
      delay(1); 
    }
  }
}

void loop(){
  lcd.clear();
  lcd.print("Menu");
  lcd.setCursor(0, 1);
  lcd.print(MenuFunctions[IMenuFunctions]);
  lcd.blink();
  delay(150); //variable + settings - for future
  if (digitalRead(10) == HIGH) IMenuFunctions = ++IMenuFunctions % 6;
  if (digitalRead(9) == HIGH) IMenuFunctions = (IMenuFunctions <= 0) ? 5 : --IMenuFunctions ;
  if (digitalRead(8) == HIGH)
  {
    delay(150);
    switch(IMenuFunctions)
    {
      case 0:
      {
        lcd.clear();
        lcd.print("Charge");
        lcd.setCursor(0, 1);
        lcd.print("Error");
        while(!digitalRead(8)){}
        lcd.noBlink();
        delay(150);
        lcd.clear();
        lcd.print("Error");
        String errorMessage = "Sorry, an error occurred, please contact a specialist!                ";
        int poz = 0;
        while(poz != -1)
        {
          lcd.setCursor(0, 1);
          lcd.print(errorMessage.substring(poz, poz + 15));
          poz = ++poz % (errorMessage.length() - 15);
          for (int j = 0; j < 300; j++)
          {
            if (digitalRead(8) == HIGH) {poz = -1; break;}
            delay(1); 
          }
        }
        break;
      }
      case 1:
      {
        while(digitalRead(8) == LOW)
        {
          lcd.clear();
          lcd.print("Discharge");
          lcd.setCursor(0, 1);
          lcd.print("Voltage: ");
          lcd.print(DischargeVoltage);
          lcd.print("V");
          ReadCells();
          if (digitalRead(9) == HIGH) DischargeVoltage = (DischargeVoltage - 0.05 < 0) ? 3.85: DischargeVoltage - 0.05; //A precisioun variable and setting menu would be a future ideea
          if (digitalRead(10) == HIGH) DischargeVoltage = (min(min(CellVoltage[0], CellVoltage[1]), min(CellVoltage[2], CellVoltage[3]))) < DischargeVoltage + 0.05 ? 0: DischargeVoltage + 0.05;
          delay(150);
        }
        while(min(min(CellVoltage[0], CellVoltage[1]), min(CellVoltage[2], CellVoltage[3])) > DischargeVoltage)
        {
          lcd.clear();
          lcd.print("Discharge: ");
          lcd.print(DischargeVoltage);
          lcd.print("V");
          ReadCells();
        }
        break;
      }
      case 5:
      {
        TimeOkPressed = 0;
        while(TimeOkPressed != -1)
        {
          lcd.clear();
          lcd.print("Nothing :))");
          ReadCells();
          for (int j = 0; j < 300; j++)
          {
            Serial.println(TimeOkPressed);
            if (TimeOkPressed && (millis() - TimeOkPressed > 1500)) {TimeOkPressed = -1; break;} //LOOK: Probably millis() takes a values taht's too big, so ya, I have to find another way :((
            if (digitalRead(8) == HIGH)
            {
               if (!TimeOkPressed) TimeOkPressed = millis();
            }
            else TimeOkPressed = 0;
            delay(1);
          }
        }
        break;
      }
    }
  }
}
