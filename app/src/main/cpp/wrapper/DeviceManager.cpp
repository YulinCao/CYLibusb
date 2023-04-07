//
// Created by changjun.cao on 2023/3/14.
//

#include "DeviceManager.h"

DeviceManager *DeviceManager::m_SingleInstance = nullptr;
std::mutex DeviceManager::m_Mutex;

// 注意：不能返回指针的引用，否则存在外部被修改的风险！
DeviceManager * DeviceManager::getInstance()
{

    //  这里使用了两个 if 判断语句的技术称为双检锁；好处是，只有判断指针为空的时候才加锁，
    //  避免每次调用 GetInstance的方法都加锁，锁的开销毕竟还是有点大的。
    if (m_SingleInstance == nullptr)
    {
        std::unique_lock<std::mutex> lock(m_Mutex); // 加锁
        if (m_SingleInstance == nullptr)
        {
            m_SingleInstance = new (std::nothrow) SingleInstance();
        }
    }

    return m_SingleInstance;
}

void DeviceManager::init(std::string param){
    int r;

    r = libusb_init(&ctx);
    if (r != LIBUSB_SUCCESS) {
        LOGD("libusb init fail %d",r);
        return;
    }
}