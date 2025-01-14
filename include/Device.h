#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device {
protected:
    std::string name;
    int id;
    double power;
    double totalEnergy;
    bool isOn;

public:
    Device(const std::string& name, int id, double power);
    virtual ~Device() = default;

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void updateTimer(int currentTime) = 0;

    const std::string& getName() const;
    bool isDeviceOn() const;

    double getInstantPower() const;
    double getTotalEnergyConsumed() const;
};

#endif // DEVICE_H
