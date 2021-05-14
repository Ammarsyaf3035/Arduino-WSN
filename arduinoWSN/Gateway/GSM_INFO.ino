// SETTING FOR GPRS (DATA TRANSMISSION USING INTERNET), THE IDS CAN BE GATHERED FROM THINGSSENTRAL DASHB0ARD
const char GPRSSetting [11] [15] PROGMEM = // [number of store] [character value max]
{
  {""},          //APN Setting (10 maximum characters!) - Current = 01156247015
  {""},  //SensorID1 = SENSOR 1 
  {""},  //SensorID2 = SENSOR 2
  {""},  //SensorID1 = SENSOR 3
  {""},  //SensorID2 = SENSOR 4
  {""}   //SensorID1 = SENSOR 5
};

// SETTING FOR SMS (DATA TRANSMISSION USING SMS - OPTIONAL)
const char SMSSetting [2] [40] PROGMEM = // [number of store] [character value max]
{
  {""},   //Set your phone number
  {"SMS MESSAGE SENT!"}   //Set your SMS Message
};

//System setting
void transferParameter()
{
  sim800l.begin(9600);

  //copy the progmem info to the variable
  
  //GPRS
  memcpy_P (&APNSetting, &GPRSSetting [0], sizeof APNSetting);
  memcpy_P (&sensorID1, &GPRSSetting [1], sizeof sensorID1);
  memcpy_P (&sensorID2, &GPRSSetting [2], sizeof sensorID2);
  memcpy_P (&sensorID3, &GPRSSetting [3], sizeof sensorID3);
  memcpy_P (&sensorID4, &GPRSSetting [4], sizeof sensorID4);
  memcpy_P (&sensorID5, &GPRSSetting [5], sizeof sensorID5);

  //SMS
  memcpy_P (&HPNumber, &SMSSetting [0], sizeof HPNumber);
  memcpy_P (&HPMessage, &SMSSetting [1], sizeof HPMessage);
}
