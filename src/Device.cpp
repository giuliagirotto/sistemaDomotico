#include "Device.h"
#include <iostream>

Device::Device(const std::string& name, int id, double power, Controller& controller)
    : name(name), id(id), power(power), Controller(controller) ,isOn(false) {}

const std::string& Device::getName() const {
    return name;
}

bool Device::isOn() const {
    return isOn;
}
