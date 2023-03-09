#include <jni.h>
#include <string>
#include "android/log.h"
#include "usb/libusb/libusbi.h"

#define LOGD(...) __android_log_print(ANDROID_LOG_INFO, "Libusb", __VA_ARGS__)

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

    }
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

    for (int i = 0; i < 1000; ++i) {
        libusb_device **device_list = NULL;
        ssize_t list_size = libusb_get_device_list(ctx, &device_list);
        if (list_size < 0 || !device_list) {

            libusb_exit(ctx);
            return -1;
        }
        libusb_free_device_list(device_list, 1);
    }

    libusb_exit(ctx);
    return 0;

}

extern "C" JNIEXPORT void JNICALL
Java_com_cyl_libusb_LibusbUtils_sendUsbData(
        JNIEnv* env,
        jclass jcls) {

}

