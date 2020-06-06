# HID2BLE ESP32 Keyboard library

将 hid 通过 esp32 蓝牙发送至电脑

# 如何使用？

1. include 库

```c++
    #include <Hid2Ble.h>
```

2. 创建对象

```c++
   Hid2Ble hid2Ble;
```

3. 启动

```c++
   hid2Ble.begin();
```

4. 判断蓝牙连接

```c++
   hid2Ble.isConnected();
```

5. 发送 hid 键盘码

```c++
   hid2Ble.send2Ble(codeArray);
```
