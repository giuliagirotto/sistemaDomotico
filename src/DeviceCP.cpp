#include "DeviceCP.h"
#include <sstream>
#include <iostream>



DeviceCP::DeviceCP(const std::string& name, int id, double power, int duration)
    : Device(name, id, power), duration(duration), controller(controller), startTime("") {}

void DeviceCP::turnOn() {
    if (!var_isOn) {
        var_isOn = true;
    }
}

void DeviceCP::turnOff() {
    if (var_isOn) {
        var_isOn = false;
    }
}

void DeviceCP::setTimer(std::string start){
    startTime = start;
    int hours,minutes;
    std::istringstream stream(startTime);
    stream >> hours >> minutes;
    int timeToMin = hours * 60 + minutes;
    int endTimeMin = timeToMin + duration;
    hours = endTimeMin / 60;
    minutes = endTimeMin % 60;
    
    std::ostringstream endTime;
    endTime << (hours < 10 ? "0" : "") << hours << "."
          << (minutes < 10 ? "0" : "") << minutes;
    stopTime = endTime.str();
}

void DeviceCP::removeTimer(){
        startTime = "";
}

void DeviceCP::checkTimer(std::string currentTime) {
    
    timeon++;
    if (startTime == currentTime) {
        controller.turnOn(this->getName());
    }
    if (stopTime == currentTime) {
        controller.turnOff(this->getName());
    }
}
