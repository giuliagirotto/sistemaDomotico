#include "Device.h"
#include "Controller.h"
#include <iostream>

Device::Device(const std::string& name, int id, double power, Controller& controller)
    : name(name), id(id), power(power), controller(controller) , totalEnergy(0), timeOn(0), isOn(false) {}

const std::string& Device::getName() const {
    return name;
}

bool Device::isOn() const {
    return isOn;
}

double Device::getInstantPower(){
    return power;
}

void Device::totalEnergyConsumed(){
    totalEnergy = power * timeOn / 60;
}
double Device::getTotalEnergyConsumed(){
    totalEnergyConsumed();
    return totalEnergy;
}

