#ifndef DEVICE_M_H
#define DEVICE_M_H

#include "Device.h"

class DeviceM : public Device {
private:
    int stopTime;

public:
    DeviceM(const std::string& name, int id, double power);
    void turnOn() override;
    void turnOff() override;
    void checkTimer(int currentTime) override;
};

#endif // DEVICE_M_H
