// Samuele Caushaj 2123698
#include "DeviceCP.h"
#include <sstream>
#include <iostream>



DeviceCP::DeviceCP(const std::string& name, int id, double power, int duration,Controller& controller)
    : Device(name, id, power,controller), duration(duration), startTime("") {}

//Accende Dispositivo
void DeviceCP::turnOn() {
    if (!isOn) {
        isOn = true;
    }
}

//Spegnimento Dispositivo
void DeviceCP::turnOff() {
    if (isOn) {
        isOn = false;
    }
}

// imposta un timer
void DeviceCP::setTimer(std::string start, std::string stop){
    startTime = start; // tempo di inizio.
    int hours,minutes;

    std::istringstream stream(startTime);
    stream >> hours >> minutes;

    int timeToMin = hours * 60 + minutes;
    int endTimeMin = timeToMin + duration;
    hours = endTimeMin / 60;
    minutes = endTimeMin % 60;
    
    std::ostringstream stopTime;
    stopTime << (hours < 10 ? "0" : "") << hours << "."
          << (minutes < 10 ? "0" : "") << minutes;
    stopTime = stopTime.str(); // ora di fine ciclo, calcolato utlizzando la duration e l'orario iniziale.
}

// rimuove il timer.
void DeviceCP::removeTimer(){
        startTime = "";
}


//controlla se e tempo per attivare un dispositivo
void DeviceCP::checkTimer(std::string currentTime) {
    
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
