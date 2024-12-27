#include "DeviceM.h"
#include <iostream>
#include "Logger.h"

extern Logger logger; // Logger globally available

DeviceM::DeviceM(const std::string& name, int id, double power)
    : Device(name, id, power), stopTime(0) {}

void DeviceM::turnOn() {
    if (!isOn) {
        isOn = true;
        logger.logEvent("Il dispositivo '" + name + "' si è acceso.");
    }
}

void DeviceM::turnOff() {
    if (isOn) {
        isOn = false;
        logger.logEvent("Il dispositivo '" + name + "' si è spento.");
    }
}

void DeviceM::updateTimer(int currentTime) {
    // Manual devices do not have automatic timers, so no action needed here
    if (stopTime == currentTime) {
        turnOff();
    }
}
