package com.cyl.libusb.usb.api;

import com.cyl.libusb.usb.device.UsbDevice;

import java.util.List;

public interface UsbAction {

    void init(String param);

    List<UsbDevice> getDevices();

    UsbDevice findDevice();

    boolean isDeviceOnline();

}
