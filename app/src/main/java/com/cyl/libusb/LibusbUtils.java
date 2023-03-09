package com.cyl.libusb;

public class LibusbUtils {
    public static native void initUsb();

    public static native int getUsbList();

    public static native void sendUsbData();
}
