#include <Adafruit_Sensor.h>
#include <dht.h>

#define tempPin 4
#define delayByHour 3600000   //delay by one hour
#define delayByHalfHour 1800000  //delay by half an hour
#define delayByMinute 60000   //delay by one minute

dht DHT;


void setup() {
  Serial.begin(9600);
}

float convertToFarenheit(){
  float total = DHT.temperature * 9/5;
  total = total + 32;
  return total;
}

void loop() {
  int temp = DHT.read11(tempPin);
  float faren = convertToFarenheit();
  Serial.print(DHT.temperature, 1);
  Serial.print(" C / ");
  Serial.print(faren, 1);
  Serial.print(" F");
  Serial.println();
  delay(25000);

}
