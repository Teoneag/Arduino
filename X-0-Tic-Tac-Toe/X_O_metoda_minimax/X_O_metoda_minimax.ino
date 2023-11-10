char tabla[]={'-','-','-','-','-','-','-','-','-'};
int intro=0,cineincepe;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  poveste_inceput(); 
  cineincepe=random(0,2);
  if(intro!=4)
  cineincepe=0;
  if(cineincepe==0)
      {
        do
       {
           mutareX();
          if(victorie())break;
           mutare0();
            afisare();
        }
          while(!victorie());
      }
      else
      {
        do
        {
          mutare0();
          if(victorie())break;
          mutareX();
          afisare();
         }
          while(!victorie());
      }
   delay(5000);
   for(int i=0;i<5;i++) Serial.println();
   for(int i=0;i<9;i++) tabla[i]='-';
}

int poveste_inceput()
{
 if(intro==0)
    {
      Serial.println("Salut!");
      Serial.println("Tu vei muta primul-esti cu X");
      Serial.println("Tabla de joc are pozitii numerotate de la 1 la 9");
      Serial.println("1 2 3");
      Serial.println("4 5 6");
      Serial.println("7 8 9");
      Serial.println("");
      intro=1;
    }
    else
    {
      if(intro==1)
      {
        Serial.println("Neata!");
        Serial.println("Mai ai chef? Apropo, esti cu X...");
        Serial.println("Cred ca stii: tabla de joc are pozitii numerotate de la 1 la 9");
        Serial.println("1 2 3");
        Serial.println("4 5 6");
        Serial.println("7 8 9");
        Serial.println("");
        intro=2;
      }
      else
      {
        if(intro==2)
        {
          Serial.println("Ne revedem...");
          Serial.println("Mai bagi o tura?(iarasi esti cu X)");
          Serial.println("Blablabla de la 1 la 9");
          Serial.println("1 2 3, baba la bordei.");
          Serial.println("4 5 6, treci de spala vase!");
          Serial.println("7 8 9, closca sta pe oua...");
          Serial.println("");
          intro=3;
        }
        else
          {
          if(intro==3)
          {
            Serial.println("Acu sper ca nu mai vrei si intro, ca deja ma doare gura!");
            Serial.println("Apropo, nu te-ai plictisit sa incepi tot tu?");
            Serial.println("Hhahahhahahahaha, nu-mi poti raspunde!");
            Serial.println("Oricum, nu ma intereseaja, deci de acum o sa incepem cum ne-o fi norocul...");
            intro=4;
          }
          }
      }
    } 
}

boolean victorie()
{
  char winner='-';
  if(tabla[0]==tabla[1]&&tabla[1]==tabla[2]) winner=tabla[0];
  if(tabla[3]==tabla[4]&&tabla[4]==tabla[5]) winner=tabla[3];
  if(tabla[6]==tabla[7]&&tabla[7]==tabla[8]) winner=tabla[6];
  if(tabla[0]==tabla[3]&&tabla[3]==tabla[6]) winner=tabla[0];
  if(tabla[1]==tabla[4]&&tabla[4]==tabla[7]) winner=tabla[1];
  if(tabla[2]==tabla[5]&&tabla[5]==tabla[8]) winner=tabla[2];
  if(tabla[0]==tabla[4]&&tabla[4]==tabla[8]) winner=tabla[0];
  if(tabla[2]==tabla[4]&&tabla[4]==tabla[6]) winner=tabla[2];

  if(winner=='-')
    {
      winner='*';
      for(int i=0;i<9;i++)
        if(tabla[i]=='-')
          winner='-';
    }
   
  if(winner=='-')
    return false;
    else
    {
      if(winner=='X')
        {
          afisare();
          Serial.println("Ati castigat! Felicitari!");
        }
     int pov_fin=random(0,5);
     if(winner=='0')
     {
      if(pov_fin==0) Serial.println("Arduino a castigat! Mai incercati!");
      if(pov_fin==1) Serial.println("Mai baga o fisa!");
      if(pov_fin==2) Serial.println("C-ai facut Bobita?");
      if(pov_fin==3) Serial.println("N-ai nici o sansa! Lasa-te de meserie! ");
      if(pov_fin==4) Serial.println("Arduino e prea bun! N-ai cum sa castigi!");
     }
     
     if(winner=='*')
     {
      if(pov_fin==0) Serial.println("Remiza. Plictisitor!");
      if(pov_fin==1) Serial.println("Tu nu te-ai plictisit?!");
      if(pov_fin==2) Serial.println("Parca-s prea putine casute, nu crezi?");
      if(pov_fin==3) Serial.println("Iar s-a umplut caroul!");
      if(pov_fin==4) Serial.println("Priveste partea buna:n-ai pierdut!");
     }
      return true;
    }
  
}
void afisare()
{
  for(int i=0;i<9;i++)
    {
      Serial.print(tabla[i]);
      Serial.print("");
      if(i==2||i==5||i==8)
       Serial.println();
    }
}


void mutareX()
{
  boolean valid=false;
  int m0=0;
  while(!valid)
  {
    Serial.println("Alege o pozitei de la 1 la 9");
    while (m0<'1'||m0>'9')
      m0=Serial.read();
      delay(1000);
      m0=m0-48;
      Serial.print("Ati ales pozitia: ");
      Serial.print(m0,DEC);
      Serial.println();
      if(tabla[m0-1]!='-')
        Serial.println("Pozitie eronata!");
        else
        {
          tabla[m0-1]='X';
          valid=true;
        }
  }
  
}

 
void mutare0()
{
  if(cineincepe==0)
  {
    if(nrmut==1)
  }
      {
        int i=-1;
        while(i==-1)
          {
            i=random(0,9);
             if(tabla[i]=='-')
               {
                  tabla[i]='0';
                  Serial.print("Arduino a ales pozitia: ");
                  Serial.print(i+1,DEC);
                  Serial.println();
                  break;
                 
               }
              else i=-1;
          }
      }
}
