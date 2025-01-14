// Samuele Caushaj 2123698
#include "DeviceM.h"
#include <iostream>


DeviceM::DeviceM(const std::string& name, int id, double power, Controller& controller)
    : Device(name, id, power, controller), startTime(""), stopTime("") {}

//accende dispositivo
void DeviceM::turnOn() {
    if (!isOn) {
        isOn = true;
    }
}

//spegne dispositivo
void DeviceM::turnOff() {
    if (isOn) {
        isOn = false;
    }
}

//imposta un timer.
void DeviceM::setTimer(std::string start,std::string stop){
    startTime = start;
    stopTime = stop;
}


//rimuove il timer
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

//controlla se e tempo di attivare il timer.
void DeviceM::checkTimer(std::string currentTime) {
    if (isOn) { 
        timeOn++;  
    }
    if (startTime == currentTime) {
        controller.turnOn(this->getName());
    }
    if (stopTime == currentTime) {
        controller.turnOff(this->getName());
    }
    
}
