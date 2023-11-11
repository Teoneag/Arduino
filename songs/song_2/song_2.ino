#include <LiquidCrystal.h> // include the library code
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// initialize the library with the numbers of the interface pins


const int buton1=7;
const int buton2=8;
int a1=0;
int a2=0;
int speakerPin = 13;
int length = 28; // the number of notes
char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";
int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };
int tempo = 150;
void playTone(int tone, int duration) {
for (long i = 0; i < duration * 1000L; i += tone * 2) {
   digitalWrite(speakerPin, HIGH);
   delayMicroseconds(tone);
   digitalWrite(speakerPin, LOW);
   delayMicroseconds(tone);
}
}
void playNote(char note, int duration) {
char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           
                 'c', 'd', 'e', 'f', 'g', 'a', 'b',
                 'x', 'y' };
int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,
                 956,  834,  765,  593,  468,  346,  224,
                 655 , 715 };
int SPEE = 5;
// play the tone corresponding to the note name
for (int i = 0; i < 17; i++) {
   if (names[i] == note) {
    int newduration = duration/SPEE;
     playTone(tones[i], newduration);
   }
}
}

void setup()
{
pinMode(speakerPin, OUTPUT);
pinMode(buton1,INPUT);
pinMode(buton2,INPUT);
Serial.begin(9600);
lcd.begin(16, 2);
}

void loop() {
a2=digitalRead(buton2);
delay(1000);
Serial.println(a2);
if(a2==LOW)
{
  a1=digitalRead(buton1);
delay(1000);
Serial.println(a1);
if(a1==HIGH)
{ 
  a1=0;
  for (int i = 0; i < length; i++) 
  {
   if (notes[i] == ' ')
   {
     delay(beats[i] * tempo); // rest
   } else
   {
     playNote(notes[i], beats[i] * tempo);
   }
   delay(tempo); // pause between notes
}
}
}
else
{
   lcd.setCursor(0, 0);
  lcd.print(9-(millis() / 1000))
}
}
