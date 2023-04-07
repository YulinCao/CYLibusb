package com.cyl.libusb.usb.device;

public enum UsbSpeed {
    /** The OS doesn't report or know the device speed. */
    LIBUSB_SPEED_UNKNOWN ,

    /** The device is operating at low speed (1.5MBit/s). */
    LIBUSB_SPEED_LOW ,

    /** The device is operating at full speed (12MBit/s). */
    LIBUSB_SPEED_FULL ,

    /** The device is operating at high speed (480MBit/s). */
    LIBUSB_SPEED_HIGH ,

    /** The device is operating at super speed (5000MBit/s). */
    LIBUSB_SPEED_SUPER ,

    /** The device is operating at super speed plus (10000MBit/s). */
    LIBUSB_SPEED_SUPER_PLUS
}
