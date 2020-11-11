  int redPin = 11;
int greenPin = 10;
int bluePin = 9;
 int count,count2;
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  count=255;
  count2=10;

}
 
void loop()
{
  while(count>0){
    while(count2<254){
      setColor(count ,count2 , 0);  // red
      
  

      delay(200);
  }
  count2=0;
  count--;
}
count=0;
} 
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
