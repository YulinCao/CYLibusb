package com.cyl.libusb.usb;

public class UsbDevice {

    int mContext;
    int mBusNumber;
    int mPortNumber;
    int mDeviceAddress;
    long mSessionData;
    int mAttached;

    UsbSpeed mSpeed;
    UsbDevice mParentDevice;
    UsbDescriptor mDeviceDescriptor;
}
