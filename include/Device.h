#ifndef DEVICE_H
#define DEVICE_H

#include "Controller.h"
#include <string>

class Device {
protected:
    std::string name;
    int id;
    double power;
    double totalEnergy;
    std::string tempStartTime;
    std::string tempEndTime;
    int timeOn;
    bool isOn;
    Controller& controller;

public:
    Device(const std::string& name, int id, double power, Controller& controller);
    virtual ~Device() = default;

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void checkTimer(std::string currentTime) = 0;
    virtual void setTimer(std::string startTime,std::string endTime) = 0;
    virtual void removeTimer() = 0;

    const std::string& getName() const;
    bool isOn() const;

    double getInstantPower() const;
    double getTotalEnergyConsumed() const;
    std::string getTempStartTime() const;
    std::string getTempEndTime() const;
    void setTempStartTime(const std::string& startingTime);
    void setTempEndTime(const std::string& endingTime);
    
};

#endif // DEVICE_H
