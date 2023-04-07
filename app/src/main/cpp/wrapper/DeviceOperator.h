//
// Created by changjun.cao on 2023/3/18.
//
#include <list>
#include <string>
#include <stdint.h>
#include <sys/types.h>

#include "BaseDevice.h"

#ifndef CYLIBUSB_DEVICEOPERATOR_H
#define CYLIBUSB_DEVICEOPERATOR_H

class DeviceOperator {

public:
    std::list<BaseDevice> getDeviceList();

    bool isDeviceOnline();

    BaseDevice findDevice(uint16_t idVendor , uint16_t idProduct);

};


#endif //CYLIBUSB_DEVICEOPERATOR_H
