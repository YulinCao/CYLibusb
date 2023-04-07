package com.cyl.libusb.usb;

import com.cyl.libusb.usb.api.DeviceAction;
import com.cyl.libusb.usb.api.DeviceReaderObserver;
import com.cyl.libusb.usb.device.UsbDevice;

public class UsbOperator implements DeviceAction {

    static {
        System.loadLibrary("UsbUtils");
    }

    public static UsbOperator getInstance(){
        return UsbOperatorHolder.Holder;
    }

    private static class UsbOperatorHolder {
        private static UsbOperator Holder = new UsbOperator();
    }

    @Override
    public boolean open(UsbDevice device) {
        return false;
    }

    @Override
    public boolean close(UsbDevice device) {
        return false;
    }

    @Override
    public void read(UsbDevice device, DeviceReaderObserver observer) {

    }

    @Override
    public void write(UsbDevice device, byte[] data) {

    }

    public static native void sendUsbData();

}
