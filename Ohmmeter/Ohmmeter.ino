void setup(){
Serial.begin(9600);
}

void loop(){  
  
  int analogPin=0;
  int Vout_analogPin;
  float Vout;
  int Vin=5;
  float R1=98;
  float R2;

  Vout_analogPin = analogRead(analogPin);
  
  if(Vout_analogPin){
    Vout = Vout_analogPin*Vin/1024.0;
    R2 = (Vin/Vout-1)*R1;
    float Test_Vout=Vin*1.0*R2/(R1+R2);
    Serial.print("Vout este ");
    Serial.println(Vout);
    Serial.print("R2 este ");
    Serial.println(R2);
    Serial.print("Test_vout: ");
    Serial.println(Test_Vout);
    delay(1000);
  }
}
