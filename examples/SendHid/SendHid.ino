#include <Hid2Ble.h>
#include <BLEServer.h>
#include "BLE2902.h"
#include "BLECharacteristic.h"

Hid2Ble hid2Ble;

uint8_t i = 0;
//键盘码，回车键
char codeArray[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//键盘锁定报文
char lockArray[12] = {0x57, 0xAB, 0x12, 0x00, 0x00, 0x00, 0x00, 0x02, 0x07, 0xAC, 0x20, 0x57};
struct OutputReport
{
  uint8_t leds; // bitmask: num lock = 1, caps lock = 2, scroll lock = 4, compose = 8, kana = 16
};
class Mycallback : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *me)
  {
    OutputReport *report = (OutputReport *)me->getData();
    lockArray[7] = (int)report->leds;
    //发送给键盘
    
  }
};

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  //启动蓝牙
  hid2Ble.setCallBack(new Mycallback());
  hid2Ble.begin();
}

void loop()
{
  if (hid2Ble.isConnected())
  {
    Serial.println("send enter to ble...");
    hid2Ble.send2Ble(codeArray);
  }

  Serial.println("Waiting 5 seconds...");
  i += 5;
  delay(5000);
  hid2Ble.setBatteryLevel((uint8_t)100 - i);
  Serial.println(hid2Ble.batteryLevel);
}
