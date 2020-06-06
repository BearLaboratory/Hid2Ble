#ifndef ESP32_BLE_KEYBOARD_H
#define ESP32_BLE_KEYBOARD_H
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)

#include "BleConnectionStatus.h"
#include "BLEHIDDevice.h"
#include "BLECharacteristic.h"

class Hid2Ble
{
private:
  BleConnectionStatus *connectionStatus;
  BLEHIDDevice *hid;
  BLECharacteristic *inputKeyboard;
  BLECharacteristic *outputKeyboard;
  BLECharacteristic *inputMediaKeys;
  static void taskServer(void *pvParameter);

public:
  Hid2Ble(std::string deviceName = "BLab BLE Keyboard", std::string deviceManufacturer = "BLab", uint8_t batteryLevel = 100);
  void begin(void);
  void end(void);
  void send2Ble(char *keys);
  bool isConnected(void);
  void setBatteryLevel(uint8_t level);
  uint8_t batteryLevel;
  std::string deviceManufacturer;
  std::string deviceName;

protected:
  virtual void onStarted(BLEServer *pServer){};
};

#endif
#endif
