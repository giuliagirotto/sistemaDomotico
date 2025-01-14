#include "DeviceM.h"
#include <iostream>
#include "Logger.h"

extern Logger log; // Logger globally available

DeviceM::DeviceM(const std::string& name, int id, double power)
    : Device(name, id, power, controller), stopTime(0) {}

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

void DeviceM::checkTimer(std::string currentTime) {
    // Manual devices do not have automatic timers, so no action needed here

    if (startTime == currentTime) {
        turnOn();
    }
    if (stopTime == currentTime) {
        turnOff();
    }
}
