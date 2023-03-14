package com.cyl.libusb.usb;

public class UsbDescriptor {

    /** Size of this descriptor (in bytes) */
    int  bLength;

    /** Descriptor type. Will have value
     * \ref libusb_descriptor_type::LIBUSB_DT_DEVICE LIBUSB_DT_DEVICE in this
     * context. */
    int  bDescriptorType;

    /** USB specification release number in binary-coded decimal. A value of
     * 0x0200 indicates USB 2.0, 0x0110 indicates USB 1.1, etc. */
    int bcdUSB;

    /** USB-IF class code for the device. See \ref libusb_class_code. */
    int  bDeviceClass;

    /** USB-IF subclass code for the device, qualified by the bDeviceClass
     * value */
    int  bDeviceSubClass;

    /** USB-IF protocol code for the device, qualified by the bDeviceClass and
     * bDeviceSubClass values */
    int  bDeviceProtocol;

    /** Maximum packet size for endpoint 0 */
    int  bMaxPacketSize0;

    /** USB-IF vendor ID */
    int idVendor;

    /** USB-IF product ID */
    int idProduct;

    /** Device release number in binary-coded decimal */
    int bcdDevice;

    /** Index of string descriptor describing manufacturer */
    int  iManufacturer;

    /** Index of string descriptor describing product */
    int  iProduct;

    /** Index of string descriptor containing device serial number */
    int  iSerialNumber;

    /** Number of possible configurations */
    int  bNumConfigurations;
}
