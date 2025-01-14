#ifndef DEVICE_CP_H
#define DEVICE_CP_H

#include "Device.h"

class DeviceCP : public Device {
private:
    int duration;
    int startTime;

public:
    DeviceCP(const std::string& name, int id, double power, int duration);
    void turnOn() override;
    void turnOff() override;
    void checkTimer(int currentTime) override;
};

#endif // DEVICE_CP_H
