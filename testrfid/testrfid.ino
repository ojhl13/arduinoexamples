#include <SPI.h>;
#include <MFRC522.h>;
RFID rfid(1,2); 
void setup() { 
Serial.begin(9600); //Inicializa la velocidad de Serial 
SPI.begin(); //Función que inicializa SPI 
rfid.init(); //Función que inicializa RFID 
} 
void loop() { 
if (rfid.isCard()) { //Verifica si hay una tarjeta 
if (rfid.readCardSerial()) { //Funcion que lee la tarjeta 
Serial.println(" "); 
Serial.println(" "); 
Serial.println("El numero de serie de la tarjeta es : "); 
for(int i=0;i<=4; i++){ 
if(i!=4){ 
Serial.print(rfid.serNum[i],HEX); //rfid.serNum lee el número de serie unico de la tarjeta 
Serial.print(" "); 
} 
else{ 
Serial.print(rfid.serNum[i],HEX); 
Serial.print(" "); 
} 
} 
delay(1000); 
} 
} 
rfid.halt(); 
}