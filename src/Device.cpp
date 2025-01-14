// Samuele Caushaj 2123698
#include "Device.h"
#include "Controller.h"
#include <iostream>

Device::Device(const std::string& name, int id, double power, Controller& controller)
    : name(name), id(id), power(power), controller(controller) , totalEnergy(0), timeOn(0), isOn(false) {}

//recupera nome dispositivo
const std::string& Device::getName() const {
    return name;
}

//accende dispositivo
bool Device::isDeviceOn() const {
    return isOn;
}

//recupera la potenza in KWH
double Device::getInstantPower() {
    return power;
}

// Calcola l'energia totale
void Device::totalEnergyConsumed(){
    totalEnergy = power * timeOn / 60; // potenza in KWH * tempo in minuti che il dispositivo e stato acceso / 60 minuti.
}

// recupera l'energia
double Device::getTotalEnergyConsumed() {
    totalEnergyConsumed();
    return totalEnergy;
}
