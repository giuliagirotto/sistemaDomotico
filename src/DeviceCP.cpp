#include "DeviceCP.h"
#include <sstream>
#include <iostream>



DeviceCP::DeviceCP(const std::string& name, int id, double power, int duration,Controller& controller)
    : Device(name, id, power,controller), duration(duration), startTime("") {}

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

void DeviceCP::setTimer(std::string start, std::string stop){
    startTime = start;
    int hours,minutes;
    std::istringstream stream(startTime);
    stream >> hours >> minutes;
    int timeToMin = hours * 60 + minutes;
    int endTimeMin = timeToMin + duration;
    hours = endTimeMin / 60;
    minutes = endTimeMin % 60;
    
    std::ostringstream stopTime;
    endTime << (hours < 10 ? "0" : "") << hours << "."
          << (minutes < 10 ? "0" : "") << minutes;
    stopTime = endTime.str();
}

void DeviceCP::removeTimer(){
        startTime = "";
}

void DeviceCP::checkTimer(std::string currentTime) {
    
    if (isOn) { 
        timeOn++;  //aggiorna il tempo in minuti in cui il dispositivo e stato acceso, per poi calcolare l'energia.
    }
    if (startTime == currentTime) {
        controller.turnOn(this->getName());
    }
    if (stopTime == currentTime) {
        controller.turnOff(this->getName());
    }
}
