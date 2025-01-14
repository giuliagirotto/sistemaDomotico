#include "Device.h"
#include "Controller.h"
#include <iostream>

Device::Device(const std::string& name, int id, double power, Controller& controller)
    : name(name), id(id), power(power), controller(controller) , tempStartTime(""), tempEndTime(""), timeOn(0), isOn(false) {}

const std::string& Device::getName() const {
    return name;
}

bool Device::isOn() const {
    return isOn;
}

double getInstantPower(){
    return power;
}
int timeToMin(std::string time){
    int hours,minutes;
    std::istringstream stream(time);
    stream >> hours >> minutes;
    int timeToMin = hours * 60 + minutes;
    return  timeToMin;
}
void energyConsumedMonitor(std::string start_time, std::string end_time){
    iniTime = timeToMin(start_time);
    finTime = timeToMin(end_time);
    totalEnergy += (finTime - iniTime);
}
