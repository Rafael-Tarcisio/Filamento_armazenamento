//Autor: Rafael Tarcisio

#include <DHT.h>
#define DHTPIN 6
#define DHTTYPE DHT11   // Define que o sensor é do tipo DHT11
DHT dht(DHTPIN, DHTTYPE);
const float temperaturaMax = 25.0;   // Temperatura máxima 
const float temperaturaMin = 15.0;   // Temperatura máxima
const float umidadeMax = 20.0;   // Temperatura máxima 
const float umidadeMin = 40.0;   // Temperatura máxima

void setup() 
{
  Serial.begin(9600); 
  pinMode(8, OUTPUT);      // LED no pino 8
  pinMode(9, OUTPUT);      // LED no pino 9
  pinMode(10, OUTPUT);     // LED no pino 10
  dht.begin();
}

void loop()
{
 float humidity = dht.readHumidity(); // Ler humidade
 float temperature = dht.readTemperature(); // Ler temperatura
 Serial.print("Temperatura: ");       
 Serial.println(temperature); 
 Serial.print("umidade: ");
 Serial.println(humidity); 
 delay(500);

  if (temperature > temperaturaMax || humidity > umidadeMax || temperature < temperaturaMin || humidity < umidadeMin) 
  { 
    digitalWrite(8, HIGH);  // Acende o LED
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  } else if ( temperature < temperaturaMax && humidity > umidadeMax || temperature > temperaturaMax && humidity < umidadeMax)
  {
    digitalWrite(8, LOW);  // Acende o LED
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
  } else if ( temperature < temperaturaMax && humidity < umidadeMax &&  temperature > temperaturaMin && humidity > umidadeMin)
  {
    digitalWrite(8, LOW);  // Acende o LED
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
  }
}