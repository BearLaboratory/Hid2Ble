#include <Hid2Ble.h>
#include <BLEServer.h>
#include "BLE2902.h"
#include "BLECharacteristic.h"

Hid2Ble hid2Ble;

uint8_t i = 0;
//音量减
char codeArray[2] = {0x03, 0x00};
struct OutputReport
{
    uint8_t leds; // bitmask: num lock = 1, caps lock = 2, scroll lock = 4, compose = 8, kana = 16
};
class Mycallback : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *me)
    {
        OutputReport *report = (OutputReport *)me->getData();
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
        Serial.println("send volum - to ble...");
        hid2Ble.sendMedia2Ble(codeArray);
        delay(5000);
    }
}
