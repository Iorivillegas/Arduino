// Incluimos librería
#include <DHT.h>
 
#define DHTPIN 6
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);


int trigPin = 2;    // Trigger
int echoPin = 3;    // Echo
long duration, cm, inches;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  dht.begin();
}

void loop() {
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
 
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t) ) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration/2) / 29.1;  
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.print("|");
  Serial.print(h);
  Serial.print("%");
  Serial.print("|");
  Serial.print(t);
  Serial.print("C");
  Serial.println();
  delay(250);
 
}


