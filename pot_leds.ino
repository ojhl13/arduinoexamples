
#define POTPIN A0        /*Declaracion de puerto del potenciometro*/
#define LED5PIN 13;      /*Seleccion del pin del quinto led*/
#define LED4PIN 12;      /*Seleccion del pin del cuarto led*/
#define LED3PIN 11;      /*Seleccion del pin del tercer led*/
#define LED2PIN 10;      /*Seleccion del pin del segundo led*/
#define LED1PIN 9;       /*Seleccion del pin del primer led*/
int valorPot = 0;     /*Almacenamiento del valor del potenciometro*/
/*Declaración de los rangos para encender cada uno de los leds*/
int rangos[]={200,400,600,800,1000}; 

void setup() {
  // declarando los pines de los LEDs como salidas
  pinMode(LED1PIN, OUTPUT);
  pinMode(LED2PIN, OUTPUT);
  pinMode(LED3PIN, OUTPUT);
  pinMode(LED4PIN, OUTPUT);
  pinMode(LED5PIN, OUTPUT); 
  /* Inicializando el puerto serial a 9660 datos por segundo*/
  Serial.begin(9600); 

}

void loop()
{
  int numLEDsON=LED1PIN;
/*leyendo el valor del potenciometro*/
  valorPot = analogRead(POTPIN);
  /* imprimiendo el dato del leido del potenciometro */
  Serial.print("sensor = ");
  Serial.println(valorPot);
  delay(100);
  /*Analizando el valor del potenciometro 
    para saber cuantos LEDs prender*/
  if(rangos[0] = valorPot){/*200*/
    numLEDsON + = 1; /*se prendera solo un led*/
  }
  else if(rangos[1] = valorPot){/*400*/
    numLEDsON + = 2; /*se prendera solo un led*/
  }
  else if(rangos[2] = valorPot){/*600*/
    numLEDsON + = 3; /*se prendera solo un led*/
  }
  else if(rangos[3] = valorPot){/*800*/
    numLEDsON + = 4; /*se prendera solo un led*/
  }
  else if(rangos[4] = valorPot){/*1000*/
    numLEDsON + = 5; /*se prendera solo un led*/
  }

  for(int i=LED1PIN; i<numLEDsON; i++)
  {
    digitalWrite(i, HIGH);   // Prendiendo los LED´s
  }
  for(int i=numLEDsON; i<= LED5PIN; i++)
  {
    digitalWrite(i,LOW); /*Apagando los demas LEDS*/
  }


  
}
// {
//  /*leyendo el valor del potenciometro*/
//  valorPot = analogRead(POTPIN);
//  /* imprimiendo el dato del leido del potenciometro */
//  Serial.print("sensor = ");
//  Serial.println(valorPot);
//  /*Analizando el valor del potenciometro 
//    para saber cuantos LEDs prender*/
//  if(rangos[0] = valorPot)
//  {
//    for(int i=LED1PIN; i<LED2PIN; i++)
//    {
//      digitalWrite(i, HIGH);   // Prendiendo los LED´s
//    }
//    for(int i=LED2PIN; i<= LED5PIN; i++)
//    {
//       digitalWrite(i,LOW); /*Apagando los demas LEDS*/
//    }
//  }
//  else if(rangos[1] = valorPot)
//  {
//   for(int i=LED1PIN; i<LED3PIN; i++)
//    {
//      digitalWrite(i, HIGH);   // Prendiendo los LED´s
//    }
//    for(int i=LED2PIN; i<= LED5PIN; i++)
//    {
//       digitalWrite(i,LOW); /*Apagando los demas LEDS*/
//    }
//  }
//  else if(rangos[2] = valorPot)
//  {
//   for(int i=LED1PIN; i<LED4PIN; i++)
//    {
//      digitalWrite(i, HIGH);   // Prendiendo los LED´s
//    }
//    for(int i=LED3PIN; i<= LED5PIN; i++)
//    {
//       digitalWrite(i,LOW); /*Apagando los demas LEDS*/
//    }
//  }
//  else if(rangos[3] = valorPot)
//  {
//    for(int i=LED1PIN; i<LED5PIN; i++)
//    {
//      digitalWrite(i, HIGH);   // Prendiendo los LED´s
//    }
//    for(int i=LED3PIN; i<= LED5PIN; i++)
//    {
//       digitalWrite(i,LOW); /*Apagando los demas LEDS*/
//    }
//  }
//  else if(rangos[4] = valorPot)
//  {
//    for(int i=LED1PIN; i<LED3PIN; i++)
//    {
//      digitalWrite(i, HIGH);   // Prendiendo los LED´s
//    }
//    for(int i=LED2PIN; i<= LED5PIN; i++)
//    {
//       digitalWrite(i,LOW); /*Apagando los demas LEDS*/
//    }
//  }
//  else
//  {
//
//  }
//
//}//