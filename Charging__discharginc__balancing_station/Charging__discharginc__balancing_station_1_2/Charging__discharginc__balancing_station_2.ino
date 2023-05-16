#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int Poz = 0;

int NrOfCells;
float CellVoltage[4];
float DischargeVoltage = 3.85;

String MenuFunctions[6] = {"Charge", "Discharge", "Balance", "Help", "About", "Nothing"};
int IMenuFunctions;

String AllCells;

String ReadCells()
{
  CellVoltage[0] = analogRead(A0) * 5.0 / 1023;
  CellVoltage[1] = analogRead(A1) * 5.0 / 1023 * 1.998 - CellVoltage[0];
  CellVoltage[2] = analogRead(A2) * 5.0 / 1023 * 3.204 - CellVoltage[1] - CellVoltage[0];
  CellVoltage[3] = analogRead(A3) * 5.0 / 1023 * 4.3 - CellVoltage[2]- CellVoltage[1]- CellVoltage[0];
  NrOfCells = 0; //This needs improvement: to check nr of cells, u have 2 cases, and I've checked just the first case: Reading of a non-cell is I. 0 (so it's connected to ground), II. fluctuateing (so it's not connected to ground)
  for (int j = 0; j < 4 && analogRead(14 + j) > 20; j++)
    NrOfCells = j + 1;
  String allCells = "Cells not connected";
  if (NrOfCells > 0) allCells = "                C1: " + (String)CellVoltage[0];
  for (int i = 1; i < NrOfCells; i++)
    allCells += ", C" + (String)(i + 1) + ": " + (String)CellVoltage[i];
  allCells += "                ";
  Serial.println(allCells);
  return allCells;
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

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
  lcd.setCursor(0, 1);
  lcd.print("   (Press ok)");
  for(int i = 0; i < (introMessage.length() - 15) * 2; i++)
  {
    lcd.home();
    lcd.print(introMessage.substring(Poz, Poz + 15));
    Poz = ++Poz % (introMessage.length() - 15);
    for (int j = 0; j < 250; j++)
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
    delay(300);
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
        Poz = 0;
        while(Poz != -1)
        {
          lcd.setCursor(0, 1);
          lcd.print(errorMessage.substring(Poz, Poz + 15));
          Poz = ++Poz % (errorMessage.length() - 15);
          for (int j = 0; j < 300; j++)
          {
            if (digitalRead(8) == HIGH) {Poz = -1; break;}
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
        lcd.clear();
        lcd.print("Nothing :))");
        AllCells = "";
        while (AllCells != "Stop")
        {
          AllCells = ReadCells();
          lcd.setCursor(0, 1);
          lcd.print(AllCells.substring(Poz, Poz + 15));
          Poz = ++Poz % (AllCells.length() - 15);
          for (int j = 0; j < 250; j++)
          {
            if (digitalRead(8) == HIGH) {AllCells = "Stop"; break;}
            delay(1); 
          }
        }
        break;
      }
    }
  }
}
