#define PI 3.1416
#define DIAMETER_WHEEL 7 //cm
#define NUMOFNOTCHES 20
#define TIME 100 //microseconds
volatile float rune = 0;
float oldrune = 0;
float lastdistance;
// distanceperlap = PI *DIAMETER_WHEEL ;// longitude of the wheel
//distanceperlap = PI * DIAMETER_WHEEL*(RUNE/NUMOFNOTCHES) // distance traveled
//
 
void doEncoder(){
  rune++;
  
}
 
void setup(){
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(3), doEncoder, CHANGE);
  pinMode(13,OUTPUT);
  Serial.println("Hola Mundo enfermo");
  lastdistance=0;
}
void loop(){
  float distance;
  float Speed;
  delay(TIME);
  distance = PI* DIAMETER_WHEEL *(rune/NUMOFNOTCHES); // distance traveled
  rune=0;
  Serial.print(distance);
  Serial.print("\t");
  Speed = (distance  - lastdistance)/TIME; // pero no se en que medidas salen?? distancia esta en cm  y tiempo esta en us entonces creo debo ajustar las unidades para que sea  m/s
  Serial.println(Speed);
 /* if (oldrune != rune ){
    Serial.println(rune);
    oldrune = rune ;
  }*/
   
}
