#include "DeviceM.h"
#include <iostream>


DeviceM::DeviceM(const std::string& name, int id, double power)
    : Device(name, id, power, controller), startTime(""), stopTime("") {}

void DeviceM::turnOn() {
    if (!var_isOn) {
        var_isOn = true;
    }
}

void DeviceM::turnOff() {
    if (var_isOn) {
        var_isOn = false;
    }
}

void DeviceM::setTimer(std::string start,std::string stop){
    startTime = start;
    stopTime = stop;
}

void DeviceM::removeTimer(){
    if (var_isOn){
        startTime = "";
        stoptime = "";
    }
    else if (var_isOn){
        startTime = "";
        stoptime = "";
        controller.turnOff(this->getName());
    }
    
}
void DeviceM::checkTimer(std::string currentTime) {
    timeOn++;
    if (startTime == currentTime) {
        controller.turnOn(this->getName());
    }
    if (stopTime == currentTime) {
        controller.turnOff(this->getName());
    }
    
}
