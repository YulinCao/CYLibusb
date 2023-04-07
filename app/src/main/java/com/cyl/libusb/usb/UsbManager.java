package com.cyl.libusb.usb;

import com.cyl.libusb.usb.device.UsbDevice;

import java.util.ArrayList;
import java.util.List;

public class UsbManager {

    public static UsbManager getInstance(){
        return UsbManagerHolder.Holder;
    }

    private List<UsbDevice> mListDevice = new ArrayList<UsbDevice>();

    private UsbOperator mOperator = new UsbOperator();

    private static class UsbManagerHolder {
        private static UsbManager Holder = new UsbManager();
    }

    public void init(){

    }

    public void exit(){

    }

    public List<UsbDevice> getListDevice(){
        getUsbDeviceList();
        return mListDevice;
    }

    public static native void initUsb(String param);

    public static native int getUsbDeviceList();

    public static native boolean isDeviceOnline();
}
