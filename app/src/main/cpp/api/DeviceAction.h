//
// Created by changjun.cao on 2023/3/18.
//

#ifndef CYLIBUSB_DEVICEACTION_H
#define CYLIBUSB_DEVICEACTION_H


class DeviceAction {

public:
    void virtual open() = 0;

    void virtual close() = 0;

    void virtual read() = 0;

    void virtual write(const unsigned char * data, unsigned int size) = 0;
};


#endif //CYLIBUSB_DEVICEACTION_H
