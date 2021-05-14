// GPRS and SMS Protocol Written Ammar Sabaahul @ a.sabahul@gmail.com @ latest by 18/9/2020
#include "PROCESA.h"
#include <SoftwareSerial.h>
SoftwareSerial serialGSM(7, 8);

const char gsmComm [17] [100] PROGMEM =
{
  { "" },
  { "" },
  { "" },
  { "AT+HTTPREAD\r\n" },
  { "AT+SAPBR=3,1,\"Contype\",\"GPRS\"\r\n" },
  { "AT+SAPBR=3,1,\"APN\",\"" },
  { "AT+SAPBR=1,1\r\n" },
  { "AT+SAPBR=2,1\r\n" },
  { "AT+HTTPINIT\r\n" },
  { "AT+HTTPPARA=\"CID\",1\r\n" },
  { "" },
  { "AT+SAPBR=0,1\r\n" },
  { "AT+CLTS=1\r\n" },
  { "" },
  { "AT+CCLK?\r\n" },
  { "AT+HTTPACTION=0\r\n" }, //0 = GET, 1 = POST, 2 = HEAD
  { "AT+HTTPPARA=\"URL\",\"http://thingssentral.io/postlong?data=userid|" }
};


SIM800L::SIM800L(bool debug)
{
  _msg = debug;
}


void SIM800L::begin(int baudRate)
{
  Serial.begin(baudRate);
  if (_msg)
    Serial.print(F("\nDEBUG MODE is turn on"));
}


void SIM800L::buffGPRS()
{
  delay(3000);
  while (serialGSM.read() >= 0); //flush the RX serial buffer
}


bool SIM800L::initGPRS(char APNSetting[], bool delayGSM)
{
  pinMode(9, OUTPUT); // Control circuit
  Serial.print(F("\n\nInitiate GPRS Connection."));
  digitalWrite(9, 1);

  if (delayGSM == 1) //Mainly to wait after the module power off
  {
    digitalWrite(9, 0);
    delay(2000);
    digitalWrite(9, 1);
    delay(10000);
  }
  
  char buff[60], buff2[100];
  buff[0] = '\0';

  serialGSM.begin(9600); //Activate GPRS serial
  buffGPRS(); //flush
  
  memcpy_P (&buff2, &gsmComm [4], sizeof buff2); //1. Activate bearer profile, procedure until number 4
  serialGSM.println(buff2); buffGPRS(); buff2[0] = '\0'; //Set connection type to GPRS

  memcpy_P (&buff, &gsmComm [5], sizeof buff); //2. Activate bearer profile
  sprintf(buff2, "%s%s\"\r\n", buff, APNSetting); //should be 3s but i removed before buffGPRS();
  serialGSM.println(buff2); buffGPRS(); buff2[0] = '\0'; //Set APN based on SIMCard provider, my3g - UMobile

  memcpy_P (&buff2, &gsmComm [6], sizeof buff2); //3. Activate bearer profile, Tr = 85s
  serialGSM.println(buff2); buffGPRS(); buff2[0] = '\0';

  Serial.print(F("\nIP Address \t>> "));
  memcpy_P (&buff2, &gsmComm [7], sizeof buff2); //4. Activate bearer profile
  //Get IP adress, note that IP address will not change if the connection is not close and shutown module
  serialGSM.println(buff2); delay(3000); buff2[0] = '\0';
  buff[0] = '\0'; serialGSM.readBytes(buff, 50); Serial.print(buff);

  buffGPRS(); //flush
  serialGSM.end();

  // If error occur at gaining ip address, close GPRS connection & return error to main function
  if (!strstr(buff, "1,1"))
  {
    buff[0] = '\0';
    return 0; // 0 indicates error
  }

  Serial.print(F("\nConnection Success."));
  buff[0] = '\0';
  return 1; // 1 indicates success
}

byte SIM800L::sendData(bool sendMode,
                       char sensorID1[], char sensorValue1[],
                       char sensorID2[], char sensorValue2[],
                       char sensorID3[], char sensorValue3[],
                       char sensorID4[], char sensorValue4[],
                       char sensorID5[], char sensorValue5[])
{
  pinMode(9, OUTPUT); // Control circuit

  byte i = 0;
  char buff[60], buff2[150];

  serialGSM.begin(9600);
  Serial.print(F("\n\nEnable HTTP."));
  memcpy_P (&buff2, &gsmComm [8], sizeof buff2); //Initialize HTTP Service, Tr=-s
  serialGSM.println(buff2); buffGPRS();

  memcpy_P (&buff2, &gsmComm [9], sizeof buff2); //Set HTTP Parameters Value, Tr=-s
  serialGSM.println(buff2); buffGPRS();

  Serial.print(F("\n\nSending sensor data to gateway."));
  Serial.print(F("\nData to be send."));

  Serial.print(F("\nSensor ID >> ")); Serial.print(sensorID1); Serial.print(F(" | Value >> ")); Serial.print(sensorValue1);
  Serial.print(F("\nSensor ID >> ")); Serial.print(sensorID2); Serial.print(F(" | Value >> ")); Serial.print(sensorValue2);
  Serial.print(F("\nSensor ID >> ")); Serial.print(sensorID3); Serial.print(F(" | Value >> ")); Serial.print(sensorValue3);
  Serial.print(F("\nSensor ID >> ")); Serial.print(sensorID4); Serial.print(F(" | Value >> ")); Serial.print(sensorValue4);
  Serial.print(F("\nSensor ID >> ")); Serial.print(sensorID5); Serial.print(F(" | Value >> ")); Serial.print(sensorValue5);

  memcpy(buff, sensorID1, sizeof buff); //Trim first ID for userID
  buff[5] = '\0';

  memcpy_P (&buff2, &gsmComm [16], sizeof buff2); //copy the PROGMEM info at array 17
  sprintf(buff2, "%s%s@%s|%s@%s|%s@%s|%s@%s|%s@%s|%s\"\r\n", buff2, buff,
          sensorID1, sensorValue1,
          sensorID2, sensorValue2,
          sensorID3, sensorValue3,
          sensorID4, sensorValue4,
          sensorID5, sensorValue5);

  Serial.print(F("\nGET Link \t>> "));
  Serial.print(buff2);

  //flow: setLink -> httpaction -> store response

  serialGSM.println(buff2);
  buffGPRS();

  memcpy_P (&buff2, &gsmComm [15], sizeof buff2);
  serialGSM.println(buff2);
  Serial.print(F("\nHTTP Action \t>> "));
  buff[0] = '\0'; delay(3000); serialGSM.readBytes(buff, 50); Serial.print(buff);
  buffGPRS();

  memcpy_P (&buff2, &gsmComm [3], sizeof buff2);
  serialGSM.println(buff2);
  Serial.print(F("\nHTTP Read \t>> "));  
  buff[0] = '\0'; delay(3000); serialGSM.readBytes(buff, 50); Serial.print(buff);
  buffGPRS();

  serialGSM.end();

  //check for error & error handling
  if (strstr(buff, "404") || strstr(buff, "100")) //SECONDARY FILTER note - HTTPACTION: 0,200,23 is correct
  {
    Serial.println(F("\nTransmission Success!"));
    buff[0] = '\0'; buff2[0] = '\0';
    return 1;
  }

  else
  {
    Serial.println(F("\nUnsuccessful Transmission!"));
    buff2[0] = '\0';  buff[0] = '\0';
    return 0;
  }
}

bool SIM800L::smsData(char HPNumber[], char HPMessage[])
{
  char buff[40];

  serialGSM.begin(9600);

  serialGSM.println("AT+CMGF=1");
  buffGPRS();

  sprintf(buff, "AT+CMGS=\"%s\"", HPNumber);
  serialGSM.println(buff);
  buffGPRS();

  serialGSM.print(HPMessage);
  buffGPRS();

  serialGSM.write(26); //ESC character for sms

  serialGSM.end();
}

void SIM800L::sleepAll(byte setTimer)
{
  pinMode(9, OUTPUT); // Control circuit
  digitalWrite(9, 0); //Restart GSM Module
  Serial.print(F("\n\nModule sleep mode"));

  for (byte i = 0; i < setTimer * 4; i++) //8 = 1min, 4 = 30s
    delay(8000);

  digitalWrite(9, 1);
}
