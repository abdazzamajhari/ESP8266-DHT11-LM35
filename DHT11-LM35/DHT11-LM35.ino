#include "DHT.h" 
#define DHTPIN D1 
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);  
float vref = 3.3; 
float res = vref/1023;  

void setup(){   
  Serial.begin(9600);   
  dht.begin(); 
} 

void loop() {    
  Serial.println(" ====== DHT11 SENSOR ====== ");      
  float hum = dht.readHumidity();   
  float tem = dht.readTemperature();   
  Serial.print(" Humidity DHT11: ");   
  Serial.print(hum);   
  Serial.print("% ");   
  Serial.print("\n");   
  Serial.print(" Temperature DHT11: ");   
  Serial.print(tem);   
  Serial.print("°C ");   
  Serial.print(">>> ");   
  Serial.print((int)round(1.8*tem+32));   
  Serial.println("°F ");    
  Serial.println(" ====== LM35 SENSOR ====== ");     
  float temp = analogRead(A0);     
  temp = (temp*res);     
  temp = temp*100;     
  Serial.print(" Temperature LM35: ");    
  Serial.print(temp);
  Serial.println("°C ");
  Serial.println(" ========================== ");

  delay(10000); //waiting for 10 seconds
}
