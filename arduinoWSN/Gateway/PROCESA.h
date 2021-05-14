#ifndef tl
#define tl

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"

#endif

class SIM800L
{
  public:
    //constructor
    SIM800L(bool debug = false);

    //methods (almost same as your function header)
    void begin(int baudRate = 9600);

    bool initGPRS(char APNSetting[], bool delayGSM);
    byte sendData(bool sendMode,
                  char sensorID1[], char sensorValue1[],
                  char sensorID2[], char sensorValue2[],
                  char sensorID3[], char sensorValue3[],
                  char sensorID4[], char sensorValue4[],
                  char sensorID5[], char sensorValue5[]);
    bool smsData(char HPNumber[], char HPMessage[]);
    void sleepAll(byte);

  private:
    bool _msg;

    void buffGPRS();
};

#endif
