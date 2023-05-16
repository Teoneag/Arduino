#include <util/delay.h>

const int Vin_PWMPin = 3;
const int Vout_analogPin = 0;
const int SpeakerPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(Vin_PWMPin, OUTPUT);
  pinMode(SpeakerPin, OUTPUT);
}

void loop() {

  int Vout_analog;
  float Vout;
  float Vin;
  float R1=987;
  float R2;
  float R2_normal;
  float dif;
  
  for(int f=0; f<256; f++)
  {
    Vin=f*5.0/256.0;
    analogWrite(Vin_PWMPin, f);
    Vout_analog = analogRead(Vout_analogPin);
    Vout=Vout_analog*Vin/1024.0;
    R2=(Vin/Vout-1)*R1;
    
    dif=R2_normal-R2;
    if(dif<0) dif=-dif;
    if(Vin>4&&dif>20)
    {
      Serial.println("The object is in range");
      tone(SpeakerPin, 1);
    }
    else
    {
      Serial.print("Vin: ");
      Serial.println(Vin);
      Serial.print("Vout: ");
      Serial.println(Vout);
      Serial.print("R2: ");
      Serial.println(R2);
      noTone(SpeakerPin);
    }
  }

  for(int f=256; f>0; f--)
  {
    Vin=f*5.0/256.0;
    analogWrite(Vin_PWMPin, f);
    Vout_analog = analogRead(Vout_analogPin);
    Vout=Vout_analog*Vin/1024.0;
    R2=(Vin/Vout-1)*R1;
    
    dif=R2_normal-R2;
    if(dif<0) dif=-dif;
    if(Vin>4&&dif>20)
    {
      Serial.println("The object is in range");
      tone(SpeakerPin, 1);
    }
    else
    {
      Serial.print("Vin: ");
      Serial.println(Vin);
      Serial.print("Vout: ");
      Serial.println(Vout);
      Serial.print("R2: ");
      Serial.println(R2);
      noTone(SpeakerPin);
    }
  }
}
