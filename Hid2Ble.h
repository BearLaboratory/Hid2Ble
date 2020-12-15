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
  BLECharacteristicCallbacks *callBack;
  static void taskServer(void *pvParameter);

public:
  /**
    * 构造函数
    */
  Hid2Ble(std::string deviceName = "BLab BLE Keyboard", std::string deviceManufacturer = "BLab", uint8_t batteryLevel = 100);
  void begin(void);
  void end(void);
  void send2Ble(char *keys);
  void sendMedia2Ble(char *keys);
  bool isConnected(void);
  /**
   * 设置电池电量
  */
  void setBatteryLevel(uint8_t level);

  void setCallBack(BLECharacteristicCallbacks *callBack);
  /**
   * 电池电量
   */ 
  uint8_t batteryLevel;
  /**
   * 设备制造商名称
   */ 
  std::string deviceManufacturer;
  /**
   * 设备名称
   */ 
  std::string deviceName;

protected:
  virtual void onStarted(BLEServer *pServer){};
};

#endif
#endif
