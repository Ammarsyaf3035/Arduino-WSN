//GSM Parameter
#include "PROCESA.h"
#include <SoftwareSerial.h>
SoftwareSerial  link(2, 3); // (RX, TX)

SIM800L sim800l(1); // 1 = OPEN INTERFACE SETTING / 0 = CLOSE INTERFACE SETTING
char APNSetting[10], sensorID1[15], sensorID2[15], sensorID3[15], sensorID4[15], sensorID5[15], HPNumber[15], HPMessage[40];
char sensorValue1[10] = "-1", sensorValue2[10] = "-1", sensorValue3[10] = "-1", sensorValue4[10], sensorValue5[10];

void setup()
{
  transferParameter();
}

void loop()
{
  bool stat = 0; // stat = 1 means it is ok / stat = 0 there is error occured
  byte error = 0;
  // put your main code here, to run repeatedly:
  stat = sim800l.initGPRS(APNSetting, 1);

  while (stat == 0 && error <= 3) //Successfull initialization loop, if more than 3 errors, reset GSM and bypass for looping again (stat = 3)
  {
    stat = sim800l.initGPRS(APNSetting, 0);

    if (stat == 0)
      ++error;

    if (stat == 1)
      error == 0;

    if (error == 3)
      stat = 3;
  }

  if (stat == 1)//When initialization successful, gather data
  {
    do
    {
      gatherData(1);
      gatherData(2);
      gatherData(3);
      gatherData(4);
      gatherData(5);

      stat = sim800l.sendData(0,
                              sensorID1, sensorValue1,
                              sensorID2, sensorValue2,
                              sensorID3, sensorValue3,
                              sensorID4, sensorValue4,
                              sensorID5, sensorValue5);

      if (stat == 0)
      {
        sim800l.initGPRS(APNSetting, 0);
        ++error;
      }

      if (stat == 1)
        error == 0;

      if (error == 3)
        stat = 3;

    } while (stat == 0 && error <= 3);
  }
}

void gatherData(byte nodeOption)
{
  byte errorLink = 0;
  char* token;
  char buff[20];
  char nodeID[10];
  char nodeValue[10];
  char nodeSensor1[] = "@0100|01";
  char nodeSensor2[] = "@0200|01";
  char nodeSensor3[] = "@0300|01";
  char nodeSensor4[] = "@0400|01";
  char nodeSensor5[] = "@0500|01";

  switch (nodeOption)
  {
    case 1:
      sprintf(nodeID, "%s", nodeSensor1);
      break;

    case 2:
      sprintf(nodeID, "%s", nodeSensor2);
      break;

    case 3:
      sprintf(nodeID, "%s", nodeSensor3);
      break;

    case 4:
      sprintf(nodeID, "%s", nodeSensor4);
      break;

    case 5:
      sprintf(nodeID, "%s", nodeSensor5);
      break;
  }

  link.begin(9600);

  do
  {
    link.print(nodeID); //Get temperature sensor reading from node 1
    delay(500);
    link.readBytes(buff, 16);
    buff[16] = '\0';

    if (strstr(buff, nodeID))
    {
      Serial.print(F("\n\nNODE ID \t>> ")); Serial.print(nodeID);
      Serial.print(F("\nRESPONSE \t>> ")); Serial.print(buff);
      Serial.print(F("\nERROR \t\t>> "));  Serial.print(errorLink);
      errorLink = 0;
      token = strtok(buff, "|"); token = strtok(NULL, "|"); token = strtok(NULL, "|");

      sprintf(nodeValue, "%s", token);
      Serial.print(F("\nSENSOR VALUE \t>> ")); Serial.print(nodeValue);
      token[0] = '\0';
    }

    else
    {
      ++errorLink;
      if (errorLink > 5)
      {
        sprintf(nodeValue, "%s", "-1");
        Serial.print(F("\n\nSENSOR FAILED"));
      }
    }

    buff[0] = '\0';
    delay(500);
    while (link.read() >= 0);
  } while (errorLink > 0 && errorLink <= 5);

  link.end();


  switch (nodeOption) //Assign the nodeValue to the sensorValue
  {
    case 1:
      sprintf(sensorValue1, "%s", nodeValue);
      break;

    case 2:
      sprintf(sensorValue2, "%s", nodeValue);
      break;

    case 3:
      sprintf(sensorValue3, "%s", nodeValue);
      break;

    case 4:
      sprintf(sensorValue4, "%s", nodeValue);
      break;

    case 5:
      sprintf(sensorValue5, "%s", nodeValue);
      break;
  }

}
