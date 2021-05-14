#include <SoftwareSerial.h>
SoftwareSerial link(2, 3); // Rx, Tx

#include "DHT.h"
#define DHTPIN 13     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

const char nodeSensor1[] = "0100|01"; //Humidity
const char nodeSensor2[] = "0200|01"; //Temperature

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  char buff[50];
  char buff2[10];
  float sensorValue = 0.0000;

  //Capture command from master
  link.begin(9600);

  if (link.available())
  {
    link.readBytes(buff, 8);
    link.end();
    buff[8] = '\0';
    Serial.print(F("\n\nReceived command \t>> "));
    Serial.print(buff);

    if (strstr(buff, nodeSensor1))
    {
      buff[0] = '\0';
      sensorValue = dht.readHumidity();
      dtostrf(sensorValue, 7, 4, buff2);
      sprintf(buff, "@%s|%s", nodeSensor4, buff2);
      link.begin(9600); link.print(buff); link.end();
    }

    if (strstr(buff, nodeSensor2))
    {
      buff[0] = '\0';
      sensorValue = dht.readTemperature();
      dtostrf(sensorValue, 7, 4, buff2);
      sprintf(buff, "@%s|%s", nodeSensor5, buff2);
      link.begin(9600); link.print(buff); link.end();
    }

    Serial.print(F("\nReturn response \t>> "));
    Serial.print(buff);

    delay(100);
  }

  link.begin(9600);
  buff2[0] = '\0';
}

/*
   const char nodeSensor1[] = "0100|01"; must use [] or strstr wont work properly

*/
