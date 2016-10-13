#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 50 
#define DHTTYPE DHT11
#define RELAY1 30
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pin=50;
int rele=13;
int estado=0;
int vcc= 11; //crear pines de 5v
int temp = 0; // lee la humeda
int hum = 0;  // lee la temperatura
const int SensorPin= A0;


void setup() 
{
  lcd.clear();
  lcd.begin(16, 2);
  pinMode(RELAY1,OUTPUT);
  pinMode(vcc,OUTPUT);
  Serial.begin(9600); // velocidad de la trasmisión in bits
  dht.begin();

}

void loop() 
{ 
  int value = analogRead(SensorPin);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  

    if (temp <= 24)
      {
       pinMode(22, LOW);
       digitalWrite(22, LOW); //ventilador
       digitalWrite(RELAY1, HIGH); // bombillo
      }
    
  else {
 
    if ((temp >= 25)&&(temp <=28))
      {
       pinMode(22, HIGH);
       digitalWrite(22, HIGH); //ventilador
       digitalWrite(RELAY1, HIGH); // bombillo
      }
   
    else 
    {
      if (temp >=29)
      {
       lcd.clear();
       pinMode(22, HIGH);
       digitalWrite(22, HIGH); //ventilador 
       digitalWrite(RELAY1, LOW); // bombillo
      }
   }
} 
// codigo para imprimir la temperatura

lcd.clear();
lcd.setCursor(0,0);
lcd.println("Tempe: "); 
lcd.setCursor(7,0);
lcd.println(temp);//Escribe la temperatura
lcd.setCursor(12,0);
lcd.print(" C"); 
   
// codigo para imprimir la humedad

lcd.setCursor(0,1);//Posiciona la primera letra despues del segmento 5 en linea 1   
lcd.print("Humedad: ");
lcd.println(hum);//Escribe la humedad
lcd.setCursor(13,1);
lcd.print(" %  "); 
}


