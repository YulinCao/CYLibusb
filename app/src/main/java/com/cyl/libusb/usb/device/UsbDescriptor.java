package com.cyl.libusb.usb.device;

public class UsbDescriptor {

    /** Size of this descriptor (in bytes) */
    public int  bLength;

    /** Descriptor type. Will have value
     * \ref libusb_descriptor_type::LIBUSB_DT_DEVICE LIBUSB_DT_DEVICE in this
     * context. */
    public int  bDescriptorType;

    /** USB specification release number in binary-coded decimal. A value of
     * 0x0200 indicates USB 2.0, 0x0110 indicates USB 1.1, etc. */
    public int bcdUSB;

    /** USB-IF class code for the device. See \ref libusb_class_code. */
    public int  bDeviceClass;

    /** USB-IF subclass code for the device, qualified by the bDeviceClass
     * value */
    public int  bDeviceSubClass;

    /** USB-IF protocol code for the device, qualified by the bDeviceClass and
     * bDeviceSubClass values */
    public int  bDeviceProtocol;

    /** Maximum packet size for endpoint 0 */
    public int  bMaxPacketSize0;

    /** USB-IF vendor ID */
    public int idVendor;

    /** USB-IF product ID */
    public int idProduct;

    /** Device release number in binary-coded decimal */
    public int bcdDevice;

    /** Index of string descriptor describing manufacturer */
    public int  iManufacturer;

    /** Index of string descriptor describing product */
    public int  iProduct;

    /** Index of string descriptor containing device serial number */
    public int  iSerialNumber;

    /** Number of possible configurations */
    public int  bNumConfigurations;
}
