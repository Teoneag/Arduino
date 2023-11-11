#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int buton1 = 13;
bool a1 = 0;

int speakerPin = 9;
int length = 28;  // the number of notes
char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";
int beats[] = {2, 2, 8, 8, 8, 16, 1,  2, 2, 8, 8, 8, 16, 1,
               2, 2, 8, 8, 8, 8,  16, 1, 2, 2, 8, 8, 8,  16};
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
    char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B', 'c',
                    'd', 'e', 'f', 'g', 'a', 'b', 'x', 'y'};
    int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956,
                   834,  765,  593,  468,  346,  224,  655,  715};
    int SPEE = 5;
    for (int i = 0; i < 17; i++) {
        if (names[i] == note) {
            int newduration = duration / SPEE;
            playTone(tones[i], newduration);
        }
    }
}

void setup() {
    pinMode(speakerPin, OUTPUT);
    pinMode(buton1, INPUT);
    lcd.begin(16, 2);
    Serial.begin(9600);
    lcd.setCursor(0, 0);
    lcd.print("For fun, press");
    lcd.setCursor(0, 1);
    lcd.print("the button!");
}

void loop() {
    if (digitalRead(buton1) == LOW) a1 = true;
    delay(50);
    int a = millis() / 1000;
    if (a1) {
        a1 = false;
        lcd.setCursor(0, 0);
        lcd.print("Happy birthday");
        lcd.setCursor(0, 1);
        lcd.print("to you...          ");

        for (int i = 0; i < length; i++) {
            if (notes[i] == ' ') {
                delay(beats[i] * tempo);  // rest
            } else {
                playNote(notes[i], beats[i] * tempo);
            }
            // pause between notes
            delay(tempo);
        }
        lcd.setCursor(0, 0);
        lcd.print("                             ");
        lcd.setCursor(0, 1);
        lcd.print("                             ");

        int a = millis() / 1000;
        Serial.println(a);
        Serial.println((millis() / 1000));
        while ((millis() / 1000) <= a + 5) {
            lcd.setCursor(0, 0);
            lcd.print(a + 6 - (millis() / 1000));
            lcd.setCursor(0, 1);
            lcd.print(((millis() / 1000)) - a);
            lcd.print(".01.2020");
        }
        lcd.setCursor(0, 0);
        lcd.print("La Multi Ani, ");
        lcd.setCursor(0, 1);
        lcd.print("Cristi !!!      ");
    }
}
