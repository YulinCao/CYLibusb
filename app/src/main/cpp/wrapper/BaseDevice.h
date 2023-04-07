//
// Created by changjun.cao on 2023/3/14.
//

#include "usb/libusb/libusbi.h"

#ifndef CYLIBUSB_BASEDEVICE_H
#define CYLIBUSB_BASEDEVICE_H

 class BaseDevice {

 public:

    void open();
    void close();

    void write(const char* data, unsigned int size);
    void read();

 private:
     libusb_device *device;
     libusb_device_handle *dev_handle;
 };

#endif //CYLIBUSB_BASEDEVICE_H
