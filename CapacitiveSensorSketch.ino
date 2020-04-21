#define SERIAL_BUFFER_SIZE 256
#include <Timer.h>
#include "ExponentialFilter.h"
#include "CapacitiveSensor.h"

#define sendPin 2
#define sampleNum 30
#define sensorPinNum 7

Timer tcb;

ExponentialFilter ExpFilterArr[sensorPinNum];
CapacitiveSensor CsArr[sensorPinNum];
double total[sensorPinNum];
int show[sensorPinNum];
String WiSUN_CDM = "SKSENDTO 1 FE80:0000:0000:0000:021D:1291:0000:2136 0E1A 0 0 ";
    
void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  for( int i=0; i<sensorPinNum; i++ ){
    ExpFilterArr[i] = ExponentialFilter();
    CsArr[i] = CapacitiveSensor(sendPin,i+3);
    CsArr[i].set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  }
  tcb.every(1000, getWatereLevel);
}

void loop() {
  tcb.update();
}

void getWatereLevel(){  
  String WiSUN_payload = "";
  for( int i=0; i<sensorPinNum; i++ ){
    //total[i] =  CsArr[i].capacitiveSensor(sampleNum);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil
    total[i] = CsArr[i].capacitiveSensorRaw(sampleNum);
    //total[i] = ExpFilterArr[i].start(total[i]);
    show[i] = total[i];
    WiSUN_payload += String(show[i]) + ",";
    //delay(30);
  }
  Serial.println(WiSUN_payload);
  String WiSUN_payloadLen = String(WiSUN_payload.length(), HEX);
  Serial1.println(WiSUN_CDM + "00" +  WiSUN_payloadLen + " " + WiSUN_payload);
  //delay(100);
}
