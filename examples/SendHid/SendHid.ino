#include <Hid2Ble.h>

Hid2Ble hid2Ble;

//键盘码，回车键
char codeArray[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  //启动蓝牙
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
  delay(5000);
}
