#include <SoftwareSerial.h>
SoftwareSerial link(2, 3); // Rx, Tx

const char nodeSensor1[] = "0100|01"; //Sensor reading 1
//const char nodeSensor2[] = "0200|01"; //
//const char nodeSensor3[] = "0300|01"; //
//const char nodeSensor4[] = "0400|01"; //
//const char nodeSensor5[] = "0500|01"; //

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
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
      sensorValue = 0.0000; //Replace this with sensor reading
      dtostrf(sensorValue, 7, 4, buff2); //convert float number into char array
      sprintf(buff, "@%s|%s", nodeSensor1, buff2);
      link.begin(9600); link.print(buff); link.end();
    }

/* Uncomment this if you would like to add more readings
    if (strstr(buff, nodeSensor2))
    {
      buff[0] = '\0';
      sensorValue = 0.0000;
      dtostrf(sensorValue, 7, 4, buff2);
      sprintf(buff, "@%s|%s", nodeSensor2, buff2);
      link.begin(9600); link.print(buff); link.end();
    }

    if (strstr(buff, nodeSensor3))
    {
      buff[0] = '\0';
      sensorValue = 0.0000;
      dtostrf(sensorValue, 7, 4, buff2);
      sprintf(buff, "@%s|%s", nodeSensor3, buff2);
      link.begin(9600); link.print(buff); link.end();
    }

    if (strstr(buff, nodeSensor4))
    {
      buff[0] = '\0';
      sensorValue = 0.0000;
      dtostrf(sensorValue, 7, 4, buff2);
      sprintf(buff, "@%s|%s", nodeSensor3, buff2);
      link.begin(9600); link.print(buff); link.end();
    }

    if (strstr(buff, nodeSensor5))
    {
      buff[0] = '\0';
      sensorValue = 0.0000;
      dtostrf(sensorValue, 7, 4, buff2);
      sprintf(buff, "@%s|%s", nodeSensor3, buff2);
      link.begin(9600); link.print(buff); link.end();
    }
*/

    Serial.print(F("\nReturn response \t>> "));
    Serial.print(buff);

    delay(100);
  }

  link.begin(9600);
  //while (link.read() >= 0); //Clean buffer
  buff2[0] = '\0';
}

/*
   const char nodeSensor1[] = "0100|01"; must use [] or strstr wont work properly

*/
