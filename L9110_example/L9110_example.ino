#define IA  8 
#define IB  9

void setup() {
  pinMode(IA,OUTPUT);
  pinMode(IB,OUTPUT);
}



void Forward(char speed)
{
digitalWrite(IA, LOW);
analogWrite(IB, speed);
}

void Reverse(char speed )
{
digitalWrite(IA, HIGH);
analogWrite(IB, 255-speed);
}

void Stop(void)
{
  digitalWrite(IA, HIGH);
  analogWrite(IB, 0);
}


void loop() {
  // put your main code here, to run repeatedly:
  Forward(150);
  delay(1000);
  Stop();
  delay(100);
  Reverse(150);
  delay(1000);
}

