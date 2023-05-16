void setup(){
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop(){  
  
  float Vout;
  float Vin;
  float R1=987.0;
  float cR2=248.0;
  float R2;
  unsigned long time=millis();

  for(int f=0; f<256; f++)
  {
    int p=random(0,10);
    if(time<10000||p==0)
      {
      Vin=f*5.0/256.0;
      Serial.print("Vin: ");
      Serial.println(Vin);
      Vout=Vin/(cR2/R1+1);
      int r=random(0,3);
      int sr=random(0,2 );
      if(sr==0) Vout+=r/100.0;
      else Vout-=r/100.0;
      Serial.print("Vout: ");
      Serial.println(Vout);
      
      R2 = (Vin/Vout-1)*R1;
      Serial.print("R2 este ");
      Serial.println(R2);
      noTone(9);
      }
      else
      {
        Serial.println("The object is in range");
        tone(9, 1);
      }
  }
  
  for(int f=256; f>0; f--)
  {
    int p=random(0,10);
    if(time<10000||p==0)
      {
      Vin=f*5.0/256.0;
      Serial.print("Vin: ");
      Serial.println(Vin);
      Vout=Vin/(cR2/R1+1);
      int r=random(0,3);
      int sr=random(0,2 );
      if(sr==0) Vout+=r/100.0;
      else Vout-=r/100.0;
      Serial.print("Vout: ");
      Serial.println(Vout);
      
      R2 = (Vin/Vout-1)*R1;
      Serial.print("R2 este ");
      Serial.println(R2);
      noTone(9);
      }
      else
      {
        Serial.println("The object is in range");
        tone(9, 1);
      }
  }
}
