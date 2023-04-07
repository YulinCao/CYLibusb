//
// Created by changjun.cao on 2023/3/14.
//

#include <string>
#include "usb/libusb/libusbi.h"
#include "DeviceOperator.h"

#ifndef CYLIBUSB_DEVICEMANAGER_H
#define CYLIBUSB_DEVICEMANAGER_H

class DeviceManager {

public:

    static DeviceManager *getInstance();

    void init(std::string param);

    void exit();

private:

    DeviceManager(){}
    ~DeviceManager(){
        ctx        = nullptr;
        m_Operator = nullptr;
    }

    libusb_context *ctx;

    DeviceOperator *m_Operator;
    // 唯一单实例对象指针
    static DeviceManager *m_SingleInstance;
    static std::mutex m_Mutex;
};

#endif //CYLIBUSB_DEVICEMANAGER_H
