#include "DeviceCP.h"
#include <iostream>
#include "Logger.h"

extern Logger logger; // Logger globally available

DeviceCP::DeviceCP(const std::string& name, int id, double power, int duration)
    : Device(name, id, power), duration(duration), startTime(0) {}

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

void DeviceCP::updateTimer(int currentTime) {
    // Only start the device when the current time matches the start time
    if (startTime == currentTime) {
        turnOn();
    }
    // If the current time reaches the end of the duration, turn off the device
    if (isOn && currentTime >= startTime + duration) {
        turnOff();
    }
}
