
#include <MaxMatrix.h>
int DIN1 = 11;   // DIN pin of MAX7219 module
int CLK1 = 12;   // CLK pin of MAX7219 module
int CS1 = 10;    // CS pin of MAX7219 module

int DIN2 = 9;   // DIN pin of MAX7219 module
int CLK2 = 8;   // CLK pin of MAX7219 module
int CS2 = 7;

int DIN3 = 6;   // DIN pin of MAX7219 module
int CLK3 = 4;   // CLK pin of MAX7219 module
int CS3 = 5;

int maxInUse = 4;

MaxMatrix L1(DIN1, CS1, CLK1, maxInUse);
MaxMatrix L2(DIN2, CS2, CLK2, maxInUse);
MaxMatrix L3(DIN3, CS3, CLK3, maxInUse);
 

char zero[] = {8, 8,  //8 row, 8 cols
B00011100,
B00100010,
B00100110,
B00101010,
B00110010,
B00100010,
B00011100,
B00000000


           };
char one[] = {8, 8,
B00001000,
B00011000,
B00101000,
B00001000,
B00001000,
B00001000,
B00001000,
B00000000

           };
char two[] = {8, 8,
B01111000,
B00000100,
B00000100,
B00111000,
B01000000,
B01000000,
B01111100,
B00000000


           };
char three[] = {8, 8,
B00111000,
B00000100,
B00000100,
B00111000,
B00000100,
B00000100,
B00111000,
B00000000


           };
char four[] = {8, 8,
B01000100,
B01000100,
B01000100,
B01111100,
B00000100,
B00000100,
B00000100,
B00000000

           };
char five[] = {8, 8,
B01111100,
B01000000,
B01000000,
B01111000,
B00000100,
B00000100,
B01111000,
B00000000

           };
char six[] = {8, 8,
B00111100,
B01000000,
B01000000,
B01111000,
B01000100,
B01000100,
B00111000,
B00000000

           };
char seven[] = {8, 8,
B01111100,
B00000100,
B00001000,
B00010000,
B00100000,
B00100000,
B00100000,
B00000000
           };
char eight[] = {8, 8,
B00111000,
B01000100,
B01000100,
B00111000,
B01000100,
B01000100,
B00111000,
B00000000
           };
char nine[] = {8, 8,
B00011100,
B00100010,
B00100010,
B00011100,
B00000010,
B00000010,
B00011100,
B00000000

           };
char empty[] = {8, 8,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000


           };           

int nombre_demployee = 4100;
String x = "";
char y;
int i = 0;
int j;
int select = 0;


void compareData(char wipe,int select){
  
    if(wipe == '0')
      L1.writeSprite(select, 0, zero );
    else if(wipe == '1')
      L1.writeSprite(select, 0, one );
    else if(wipe == '2')
      L1.writeSprite(select, 0, two );
    else if(wipe == '3')
      L1.writeSprite(select, 0, three );
    else if(wipe == '4'){
      Serial.println("yes four");
      L1.writeSprite(select, 0, four );
    }
      
    else if(wipe == '5')
      L1.writeSprite(select, 0, five );
    else if(wipe == '6')
      L1.writeSprite(select, 0, six );
    else if(wipe == '7')
      L1.writeSprite(select, 0, seven );
    else if(wipe == '8')
      L1.writeSprite(select, 0, eight );
    else if(wipe == '9')
      L1.writeSprite(select, 0, nine );
    else
      L1.writeSprite(select, 0, empty );

}

                 
void setup() {
  Serial.begin(115200);
  L1.init(); // MAX7219 initialization
  L1.setIntensity(15); // initial led matrix intensity, 0-15
  //m.setDot(7,5,true);//Column,Row
  L1.writeSprite(0, 0, four);
  L1.writeSprite(8, 0, one);
  L1.writeSprite(16, 0, zero);
  L1.writeSprite(24, 0, zero);

  L2.init(); // MAX7219 initialization
  L2.setIntensity(15); // initial led matrix intensity, 0-15
  //m.setDot(7,5,true);//Column,Row
  L2.writeSprite(0, 0, empty);
  L2.writeSprite(8, 0, five);
  L2.writeSprite(16, 0, eight);
  L2.writeSprite(24, 0, empty);

  L3.init(); // MAX7219 initialization
  L3.setIntensity(15); // initial led matrix intensity, 0-15
  //m.setDot(7,5,true);//Column,Row
  L3.writeSprite(0, 0, empty);
  L3.writeSprite(8, 0, two);
  L3.writeSprite(16, 0, six);
  L3.writeSprite(24, 0, empty);
  
}


void loop() 
{
  if (Serial.available()) {
    
      y = Serial.read();
      if(y == '\n')
      {
          if(x == "inc"){
             nombre_demployee++;
             Serial.print(x);
             Serial.println(nombre_demployee);
             select = 0;
             String strNbre = String(nombre_demployee);
             for (j = 0; j < strNbre.length() ;j++){
             compareData(strNbre[j] , select) ;
             select = select + 8; 
             /*Serial.println(strNbre[j]);
             if(strNbre[j] == '4'){
              Serial.println("yes");
             }*/
             }
             x = "";
          }
          else if(x == "dec"){
             nombre_demployee--;
             Serial.print(x);
             Serial.println(nombre_demployee);
             int select = 0;
             String strNbre = String(nombre_demployee);
             for (int j = 0; j < strNbre.length() ;j++){
             compareData(strNbre[j] , select) ;
             select = select + 8; 
             }
             x = "";
          }
          else if(x == "acc"){
             L2.writeSprite(0, 0, empty);
             L2.writeSprite(8, 0, empty);
             L2.writeSprite(16, 0, zero);
             L2.writeSprite(24, 0, empty);
             x = "";
          }
          else if(x == "rec"){
             L3.writeSprite(0, 0, empty);
             L3.writeSprite(8, 0, empty);
             L3.writeSprite(16, 0, zero);
             L3.writeSprite(24, 0, empty);
             x = "";
          }
          x = "";
      }
      if(y != '\r' & y != '\n')
      {
        x = x + y;  
      }  
 }
 
}

void shift(){
  for (int i=0; i<8; i++)
  {
    L1.shiftLeft(false,false);
    delay(200);
  }
  L1.clear();
}
