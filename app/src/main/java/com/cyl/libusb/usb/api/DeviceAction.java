package com.cyl.libusb.usb.api;

import com.cyl.libusb.usb.device.UsbDevice;

public interface DeviceAction {

    boolean open(UsbDevice device);

    boolean close(UsbDevice device);

    void read(UsbDevice device, DeviceReaderObserver observer);

    void write(UsbDevice device, byte[] data);

}
