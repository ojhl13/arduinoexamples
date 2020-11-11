bool estado=false; 
void setup()
{

 Serial.begin(9600);
  Serial.println("Link start");
  pinMode(4,INPUT);

}

void loop()
{
  estado =digitalRead(4);
  Serial.print("\t");
  Serial.println(estado);
  if(!estado){
  Serial.print("interrupcion\n");
  }
  else{
  Serial.print("salida\n");
  
  }
}
 
//Codigo de la interrupcion
void alarma()
{
  
}
