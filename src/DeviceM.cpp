#include "DeviceM.h"
#include <iostream>


DeviceM::DeviceM(const std::string& name, int id, double power, Controller& controller)
    : Device(name, id, power, controller), startTime(""), stopTime("") {}

void DeviceM::turnOn() {
    if (!isOn) {
        isOn = true;
    }
}

void DeviceM::turnOff() {
    if (isOn) {
        isOn = false;
    }
}

void DeviceM::setTimer(std::string start,std::string stop){
    startTime = start;
    stopTime = stop;
}

void DeviceM::removeTimer(){
    if (isOn){
        startTime = "";
        stopTime = "";
    }
    else if (isOn){
        startTime = "";
        stopTime = "";
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
