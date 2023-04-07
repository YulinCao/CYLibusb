#include <jni.h>
#include <string>
#include "android/log.h"
#include "usb/libusb/libusbi.h"

#define LOGD(...) __android_log_print(ANDROID_LOG_INFO, "Libusb", __VA_ARGS__)

#define VENDOR_ID    0x4e56
#define PRODUCT_ID   0x5055

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    return JNI_VERSION_1_6;
}

JNIEXPORT void JNI_OnUnload(JavaVM *vm, void *reserved) {
    LOGD("");
}

extern "C" JNIEXPORT void JNICALL
Java_com_cyl_libusb_LibusbUtils_initUsb(
        JNIEnv* env,
        jclass jcls) {

    libusb_context *ctx = NULL;
    int r;

    r = libusb_init(&ctx);
    if (r != LIBUSB_SUCCESS) {
        LOGD("libusb init fail %d",r);
        return;
    }

    libusb_device_handle *dev_handle = NULL ;
    dev_handle = libusb_open_device_with_vid_pid(ctx,VENDOR_ID,PRODUCT_ID);

    if(dev_handle != NULL)
        LOGD("libusb open success bus_number:%d", dev_handle->dev->bus_number);

    int rc = 0;
    unsigned char *data = new unsigned char[5]; //data to write
    int actual;
    data[0]='h';
    data[1]='e';
    data[2]='l';
    data[3]='l';
    data[4]='o';

    rc = libusb_bulk_transfer(dev_handle, (64 | LIBUSB_ENDPOINT_OUT), data, 4, &actual, 0);
    assert (rc != 0 || actual != 5);

    /*Check if kenel driver attached*/
    if(libusb_kernel_driver_active(dev_handle, 0))
    {
        rc = libusb_detach_kernel_driver(dev_handle, 0); // detach driver
        assert(rc == 0);
    }

    rc = libusb_claim_interface(dev_handle, 0);
    assert(rc < 0);

    rc = libusb_release_interface(dev_handle, 0);
    assert(rc != 0);

    libusb_close(dev_handle);

    libusb_exit(ctx);
    LOGD("libusb init success");
}

extern "C" JNIEXPORT jint JNICALL
Java_com_cyl_libusb_LibusbUtils_getUsbList(
        JNIEnv* env,
        jclass jcls) {

    libusb_context *ctx;
    int r;

    r = libusb_init(&ctx);
    if (r != LIBUSB_SUCCESS) {

        return -1;
    }

    libusb_device **device_list = NULL;
    ssize_t list_size = libusb_get_device_list(ctx, &device_list);
    if (list_size < 0 || !device_list) {

        libusb_exit(ctx);
        return -1;
    }

    int rc = 0;
    for(int i = 0;i < list_size;i++){
        int port = libusb_get_port_number(device_list[i]);
        LOGD("libusb device port:%d", port);
        int address = libusb_get_device_address(device_list[i]);
        LOGD("libusb device address:%d", address);
        int bus = libusb_get_bus_number(device_list[i]);
        LOGD("libusb device bus:%d", bus);

        libusb_device_descriptor desc = {0};

        rc = libusb_get_device_descriptor(device_list[i], &desc);
//        if(rc)
        LOGD("libusb Vendor:Device = %04x:%04x\n", desc.idVendor, desc.idProduct);
    }
    libusb_free_device_list(device_list, 1);

    libusb_exit(ctx);
    return 0;

}

extern "C" JNIEXPORT void JNICALL
Java_com_cyl_libusb_LibusbUtils_sendUsbData(
        JNIEnv* env,
        jclass jcls) {

}

