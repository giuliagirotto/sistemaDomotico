#ifndef DEVICE_CP_H
#define DEVICE_CP_H

#include "Device.h"

class DeviceCP : public Device {
private:
    int duration;
    std::string startTime;
    std::string stopTime;

public:
    DeviceCP(const std::string& name, int id, double power, int duration, Controller& controller);
    void turnOn() override;
    void turnOff() override;
    void checkTimer(std::string currentTime) override; 
    void setTimer(std::string startTime,std::string stopTime) override;
    void removeTimer() override;
};

#endif // DEVICE_CP_H
