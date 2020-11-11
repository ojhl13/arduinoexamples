#include<LiquidCrystal.h>                                            // including the lcd library

const int rs = 8, en = 9, d4 = 13 , d5 = 12, d6 = 11, d7 = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int in = 3;                                                      // declaring pin 8 for sensor output
 int Reset=7;                                                   // declaring pin 6 for push button
 int start=4;                                                    // declaring pin 7 for other push button
 int count=0,i=0,k=0,rate=0;                                         // initializing other variables

unsigned long time2,time1;
 unsigned long time;

byte heart[8] = 
 {
   0b00000,
   0b01010,
   0b11111,
   0b11111,
   0b11111,
   0b01110,
   0b00100,
   0b00000
 };

void setup ( )
 {
   lcd.createChar(1, heart);                            
   lcd.begin(16,2);                                               // starting the lcd
   
   lcd.print("Heart Beat ");                              // printing heart beat on the display
   lcd.write(1);
   lcd.setCursor(0,1);                                         // setting the cursor from start
   lcd.print("Monitering");                              // printing monitoring on the display
 // initializing the pins as input pins 

pinMode(in, INPUT);
   pinMode(Reset, INPUT);
   pinMode(start, INPUT);

// setting the push buttons state as high
   digitalWrite(Reset, HIGH);
   digitalWrite(start, HIGH);
   delay(1000);                                     // giving a delay
 }

void loop()
 {
   if(!(digitalRead(start)))                       // checking if the start button is pressed or not
   {
     k=0;
     lcd.clear();
     lcd.print("Please wait.......");              // displaying the please wait on the lcd
     while(k<5)                                     // applying another condition
     {
      if(digitalRead(in))                         // reading from the sensor
      {
       if(k==0)
       time1=millis();
       k++;
       while(digitalRead(in));
      }
     }
       // applying the formula for calculating the heart beat

      time2=millis();
       rate=time2-time1;
       rate=rate/5;
       rate=60000/rate;
       lcd.clear();                                       // clearing the lcd
       lcd.print("Heart Beat Rate:");                    // printing heart beat rate on display
       lcd.setCursor(0,1);                            // setting the cursor at start
       lcd.print(rate);                            // printing the heart beat on the display
       lcd.print(" ");
       lcd.write(1);      
       k=0;
       rate=0;
     }
   if(!digitalRead(Reset))                         // checking if reset button is pressed or not
   {
     rate=0;
      lcd.clear();                              // clearing the lcd
       lcd.print("Heart Beat Rate:");          // printing heart beat rate on display
       lcd.setCursor(0,1);                    // setting the cursor at start
       lcd.write(1);
       lcd.print(rate);                       // printing the heart beat on the display
       k=0;
   }
 }
