#include "Device.h"
#include <iostream>

Device::Device(const std::string& name, int id, double power)
    : name(name), id(id), power(power), isOn(false) {}

const std::string& Device::getName() const {
    return name;
}

bool Device::isDeviceOn() const {
    return isOn;
}
