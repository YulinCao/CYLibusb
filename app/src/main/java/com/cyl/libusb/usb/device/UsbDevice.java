package com.cyl.libusb.usb.device;

public class UsbDevice  {

    /** device base info */
    public int mPointer;
    public int mContext;
    public int mBusNumber;
    public int mPortNumber;
    public int mDeviceAddress;
    public long mSessionData;
    public int mAttached;

    /** jni once open device and close */
    public boolean isKeep;

    public UsbSpeed mSpeed;
    public UsbDevice mParentDevice;
    public UsbDescriptor mDeviceDescriptor;

    @Override
    public String toString() {

        StringBuilder builder = new StringBuilder("UsbDevice[mBusNumber=" + mBusNumber
                + ",mmPortNumber=" + mPortNumber + ",mDeviceAddress=" + mDeviceAddress
                + ",mSessionData=" + mSessionData + ",mAttached=" + mAttached
                + ",isKeep=" + isKeep + ",mSpeed=" + mSpeed
                + "]");

        return builder.toString();
    }
}
