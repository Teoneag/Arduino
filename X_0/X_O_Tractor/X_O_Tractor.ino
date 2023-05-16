char tabla[]={'-','-','-','-','-','-','-','-','-'};
int intro=0;
int rem;//remiza//
int ard;//arduino//
int smecherie;

void setup()
{
  Serial.begin(9600);
}

void loop()
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
   
     int incepe=random(0,2);
     if(intro!=4)
      incepe=0;
     if(incepe==0)
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
     
     if(winner=='0')
     {
     ard=random(0,5);
      if(ard==0) Serial.println("Arduino a castigat! Mai incercati!");
      if(ard==1) Serial.println("Mai baga o fisa!");
      if(ard==2) Serial.println("C-ai facut Bobita?");
      if(ard==3) Serial.println("N-ai nici o sansa! Lasa-te de meserie! ");
      if(ard==4) Serial.println("Arduino e prea bun! N-ai cum sa castigi!");
     }
     
     if(winner=='*')
     {
     rem=random(0,5);
      if(rem==0) Serial.println("Remiza. Plictisitor!");
      if(rem==1) Serial.println("Tu nu te-ai plictisit?!");
      if(rem==2) Serial.println("Parca-s prea putine casute, nu crezi?");
      if(rem==3) Serial.println("Iar s-a umplut caroul!");
      if(rem==4) Serial.println("Priveste partea buna:n-ai pierdut!");
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
          smecherie=m0-1;
          valid=true;
        }
  }
  
}

 
void mutare0()
{
  int ok=0;
  while(ok==0)
  {
 
   if(tabla[0]==tabla[1]&&tabla[0]=='0'&&tabla[2]=='-')
   {
      tabla[2]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(3,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[1]==tabla[2]&&tabla[1]=='0'&&tabla[0]=='-')
   {
      tabla[0]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(1,DEC);
      Serial.println();
      ok=1;
    }
   else
    
    if(tabla[3]==tabla[4]&&tabla[3]=='0'&&tabla[5]=='-')
   {
      tabla[5]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(6,DEC);
      Serial.println();
      ok=1;
    }
   else      

    if(tabla[4]==tabla[5]&&tabla[4]=='0'&&tabla[3]=='-')
   {
      tabla[3]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(4,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[6]==tabla[7]&&tabla[6]=='0'&&tabla[8]=='-')
   {
      tabla[8]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(9,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[7]==tabla[8]&&tabla[7]=='0'&&tabla[6]=='-')
   {
      tabla[6]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(7,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[0]==tabla[3]&&tabla[0]=='0'&&tabla[6]=='-')
   {
      tabla[6]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(7,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[3]==tabla[6]&&tabla[3]=='0'&&tabla[0]=='-')
   {
      tabla[0]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(1,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[1]==tabla[4]&&tabla[1]=='0'&&tabla[7]=='-')
   {
      tabla[7]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(8,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[4]==tabla[7]&&tabla[4]=='0'&&tabla[1]=='-')
   {
      tabla[1]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(2,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[2]==tabla[5]&&tabla[2]=='0'&&tabla[8]=='-')
   {
      tabla[8]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(9,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[5]==tabla[8]&&tabla[5]=='0'&&tabla[2]=='-')
   {
      tabla[2]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(3,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[0]==tabla[4]&&tabla[0]=='0'&&tabla[8]=='-')
   {
      tabla[8]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(9,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[4]==tabla[8]&&tabla[4]=='0'&&tabla[0]=='-')
   {
      tabla[0]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(1,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[2]==tabla[4]&&tabla[2]=='0'&&tabla[6]=='-')
   {
      tabla[6]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(7,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[4]==tabla[6]&&tabla[4]=='0'&&tabla[2]=='-')
   {
      tabla[2]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(3,DEC);
      Serial.println();
      ok=1;
    }
   else


   
   if(tabla[0]==tabla[2]&&tabla[0]=='0'&&tabla[1]=='-')
   {
      tabla[1]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(2,DEC);
      Serial.println();
      ok=1;
    }
   else


if(tabla[3]==tabla[5]&&tabla[0]=='0'&&tabla[4]=='-')
   {
      tabla[4]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(5,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[6]==tabla[8]&&tabla[6]=='0'&&tabla[7]=='-')
   {
      tabla[7]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(8,DEC);
      Serial.println();
      ok=1;
    }
   else


   if(tabla[0]==tabla[6]&&tabla[0]=='0'&&tabla[3]=='-')
   {
      tabla[3]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(4,DEC);
      Serial.println();
      ok=1;
    }
   else

if(tabla[1]==tabla[7]&&tabla[1]=='0'&&tabla[4]=='-')
   {
      tabla[4]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(5,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[2]==tabla[8]&&tabla[2]=='0'&&tabla[5]=='-')
   {
      tabla[5]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(6,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[0]==tabla[8]&&tabla[0]=='0'&&tabla[4]=='-')
   {
      tabla[4]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(5,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[2]==tabla[6]&&tabla[2]=='0'&&tabla[4]=='-')
   {
      tabla[4]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(5,DEC);
      Serial.println();
      ok=1;
    }
   else

















    if(tabla[0]==tabla[1]&&tabla[0]=='X'&&tabla[2]=='-')
   {
      tabla[2]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(3,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[1]==tabla[2]&&tabla[1]=='X'&&tabla[0]=='-')
   {
      tabla[0]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(1,DEC);
      Serial.println();
      ok=1;
    }
   else


    
    if(tabla[3]==tabla[4]&&tabla[3]=='X'&&tabla[5]=='-')
   {
      tabla[5]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(6,DEC);
      Serial.println();
      ok=1;
    }
   else      

    if(tabla[4]==tabla[5]&&tabla[4]=='X'&&tabla[3]=='-')
   {
      tabla[3]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(4,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[6]==tabla[7]&&tabla[6]=='X'&&tabla[8]=='-')
   {
      tabla[8]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(9,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[7]==tabla[8]&&tabla[7]=='X'&&tabla[6]=='-')
   {
      tabla[6]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(7,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[0]==tabla[3]&&tabla[0]=='X'&&tabla[6]=='-')
   {
      tabla[6]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(7,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[3]==tabla[6]&&tabla[3]=='X'&&tabla[0]=='-')
   {
      tabla[0]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(1,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[1]==tabla[4]&&tabla[1]=='X'&&tabla[7]=='-')
   {
      tabla[7]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(8,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[4]==tabla[7]&&tabla[4]=='X'&&tabla[1]=='-')
   {
      tabla[1]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(2,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[2]==tabla[5]&&tabla[2]=='X'&&tabla[8]=='-')
   {
      tabla[8]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(9,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[5]==tabla[8]&&tabla[5]=='X'&&tabla[2]=='-')
   {
      tabla[2]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(3,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[0]==tabla[4]&&tabla[0]=='X'&&tabla[8]=='-')
   {
      tabla[8]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(9,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[4]==tabla[8]&&tabla[4]=='X'&&tabla[0]=='-')
   {
      tabla[0]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(1,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[2]==tabla[4]&&tabla[2]=='X'&&tabla[6]=='-')
   {
      tabla[6]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(7,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[4]==tabla[6]&&tabla[4]=='X'&&tabla[2]=='-')
   {
      tabla[2]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(3,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[0]==tabla[2]&&tabla[0]=='X'&&tabla[1]=='-')
   {
      tabla[1]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(2,DEC);
      Serial.println();
      ok=1;
    }
   else


if(tabla[3]==tabla[5]&&tabla[0]=='X'&&tabla[4]=='-')
   {
      tabla[4]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(5,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[6]==tabla[8]&&tabla[6]=='X'&&tabla[7]=='-')
   {
      tabla[7]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(8,DEC);
      Serial.println();
      ok=1;
    }
   else


   if(tabla[0]==tabla[6]&&tabla[0]=='X'&&tabla[3]=='-')
   {
      tabla[3]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(4,DEC);
      Serial.println();
      ok=1;
    }
   else

if(tabla[1]==tabla[7]&&tabla[1]=='X'&&tabla[4]=='-')
   {
      tabla[4]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(5,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[2]==tabla[8]&&tabla[2]=='X'&&tabla[5]=='-')
   {
      tabla[5]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(6,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[0]==tabla[8]&&tabla[0]=='X'&&tabla[4]=='-')
   {
      tabla[4]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(5,DEC);
      Serial.println();
      ok=1;
    }
   else

   if(tabla[2]==tabla[6]&&tabla[2]=='X'&&tabla[4]=='-')
   {
      tabla[4]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(5,DEC);
      Serial.println();
      ok=1;
    }





   else
    if(tabla[4]=='X'&&tabla[0]=='-')
     {
       tabla[0]='0'; 
       Serial.print("Arduino a ales pozitia: ");
       Serial.print(1,DEC);
       Serial.println();
       ok=1;
     }
    else
    if(tabla[0]=='X'&&tabla[4]=='-'||tabla[2]=='X'&&tabla[4]=='-'||tabla[8]=='X'&&tabla[4]=='-'||tabla[6]=='X'&&tabla[4]=='-'||tabla[1]=='X'&&tabla[4]=='-'||tabla[3]=='X'&&tabla[4]=='-'||tabla[5]=='X'&&tabla[4]=='-'||tabla[7]=='X'&&tabla[4]=='-')
     {
       tabla[4]='0'; 
       Serial.print("Arduino a ales pozitia: ");
       Serial.print(5,DEC);
       Serial.println();
       ok=1;
     }
    else
    if(tabla[1]=='X'&&smecherie-6>=0&&tabla[smecherie-6]=='-')
     {
       tabla[smecherie-6]='0'; 
       Serial.print("Arduino a ales pozitia: ");
       Serial.print(smecherie-5);
       Serial.println();
       ok=1;
     }
     else
    if(tabla[3]=='X'&&smecherie-2>=0&&tabla[smecherie-2]=='-')
     {
       tabla[smecherie-2]='0'; 
       Serial.print("Arduino a ales pozitia: ");
       Serial.print(smecherie-1);
       Serial.println();
       ok=1;
     }
     else
    if(tabla[5]=='X'&&tabla[smecherie+2]=='-')
     {
       tabla[smecherie+2]='0'; 
       Serial.print("Arduino a ales pozitia: ");
       Serial.print(smecherie+3);
       Serial.println();
       ok=1;
     }
     else
    if(tabla[7]=='X'&&tabla[smecherie+6]=='-')
     {
       tabla[smecherie+6]='0'; 
       Serial.print("Arduino a ales pozitia: ");
       Serial.print(smecherie+7);
       Serial.println();
       ok=1;
     }




   
   else
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
                  ok=1;
                  break;
                 
               }
              else i=-1;
          }
      }
  }
}
