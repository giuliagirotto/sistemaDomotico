#ifndef DEVICE_M_H
#define DEVICE_M_H

#include "Device.h"

class DeviceM : public Device {
private:
    std::string stopTime;
    std::string startTime;

public:
    DeviceM(const std::string& name, int id, double power, Controller& controller);
    void turnOn() override;
    void turnOff() override;
    void checkTimer(int currentTime) override;
    void setTimer(startTime, endTime) override;
    void removeTimer() override;
};

#endif // DEVICE_M_H
