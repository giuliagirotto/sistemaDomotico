#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <memory>
#include "Device.h"

class Controller {
private:
    std::vector<std::unique_ptr<Device>> devices;
    double maxPower;
    double solarProduction;
    int currentTime;

public:
    Controller(double maxPower, double solarProduction);
    void addDevice(std::unique_ptr<Device> device);
    void setTime(int newTime);
    void handleOverload();
    void showStatus();
};

#endif // CONTROLLER_H