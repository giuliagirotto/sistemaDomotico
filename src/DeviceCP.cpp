#include "DeviceCP.h"
#include <sstream>
#include <iostream>



DeviceCP::DeviceCP(const std::string& name, int id, double power, int duration)
    : Device(name, id, power), duration(duration), controller(controller), startTime("") {}

void DeviceCP::turnOn() {
    if (!isOn) {
        isOn = true;
    }
}

void DeviceCP::turnOff() {
    if (isOn) {
        isOn = false;
    }
}

void DeviceCP::setTimer(std::string start){
    startTime = start;
}

void DeviceCP::removeTimer(){
        startTime = "";
}

void DeviceCP::checkTimer(std::string currentTime) {
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
    
    
    if (startTime == currentTime) {
        controller.turnOn(this->getName());
    }
    if (endTime.str() == currentTime) {
        controller.turnOff(this->getName());
    }
}
