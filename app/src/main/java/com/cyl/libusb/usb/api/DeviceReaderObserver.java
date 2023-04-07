package com.cyl.libusb.usb.api;

import com.cyl.libusb.usb.device.UsbDevice;

public interface DeviceReaderObserver {

    void read(UsbDevice device, byte[] data);

}
