#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

LCDWIKI_KBV mylcd(ILI9486,A3,A2,A1,A0,A4);

//define some colour values
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

void setup() {
    Serial.begin(9600);
    mylcd.Init_LCD();
    Serial.println(mylcd.Read_ID(), HEX);
    mylcd.Fill_Screen(BLACK);
    mylcd.Set_Text_Mode(0);
    mylcd.Fill_Screen(0x0000);
    mylcd.Set_Text_colour(RED);
    mylcd.Set_Text_Back_colour(BLACK);
    mylcd.Set_Text_Size(3);
    Serial.begin(9600);
    float a = 0;
    float b = 0;
    float c = 0;
    float d = 0;
    float abcd = 0.0; //the pattern
    String stringOne;
    int pos = 30; //starting position of text
    for (int i = 0; i <= 9999; i++)
    {
    //single digit number
    if (i < 10)
    {
      a = i;
      if (i  ==  (int)(pow(a,4) + pow(b,4) + pow(c,4) + pow(d,4) + 0.5))
      {
       stringOne = String(i);
       mylcd.Print_String(stringOne, 0, pos);
       pos = pos + 30;
       Serial.println("valid number");
       Serial.println(i);
      }
    }
    //double digit number
    if (i >= 10 && i < 100)
    {
      a = i /10;     
      b = i % 10;
      if (i  ==  (int)(pow(a,4) + pow(b,4) + pow(c,4) + pow(d,4) + 0.5))
      {
        stringOne = String(i);
        mylcd.Print_String(stringOne, 0, pos);
        pos = pos + 30;
        Serial.println("valid number");
        Serial.println(i);
      }
    }
    //triple digit number
    if (i >= 100 && i < 1000)
    {
      a = i /100;
      b = (i% 100)/10; 
      c = (i% 100)%10;
      if (i  ==  (int)(pow(a,4) + pow(b,4) + pow(c,4) + pow(d,4) + 0.5))
      {
        stringOne = String(i);
        mylcd.Print_String(stringOne, 0, pos);
        pos = pos + 30;
        Serial.println("valid number");
        Serial.println(i);
      }
    }
    //quadruple digit number
    if (i >= 1000 && i < 10000)
    {
     
      a = i /1000;
      b = (i/ 100)%10;
      c = (i% 100)/10;
      d = i%10;
      if (i  ==  (int)(pow(a,4) + pow(b,4) + pow(c,4) + pow(d,4) + 0.5))
      {
        stringOne = String(i);
        mylcd.Print_String(stringOne, 0, pos);
        pos = pos + 30;
        Serial.println("valid number");
        Serial.println(i);
      }
    }
  }
}

void loop() {
}
