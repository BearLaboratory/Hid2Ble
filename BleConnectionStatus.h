#ifndef ESP32_BLE_CONNECTION_STATUS_H
#define ESP32_BLE_CONNECTION_STATUS_H
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)

#include <BLEServer.h>
#include "BLE2902.h"
#include "BLECharacteristic.h"

class BleConnectionStatus : public BLEServerCallbacks
{
public:
  BleConnectionStatus(void);

  /**
   * 蓝牙连接状态
   */
  bool connected = false;
  /**
   * 蓝牙连接回调函数
   */
  void onConnect(BLEServer *pServer);
  /**
   * 蓝牙断开连接回调函数
   */
  void onDisconnect(BLEServer *pServer);
  BLECharacteristic *inputKeyboard;
  BLECharacteristic *outputKeyboard;
  BLECharacteristic *inputMediaKeys;
};

#endif
#endif
