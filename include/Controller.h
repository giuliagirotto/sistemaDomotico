#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <memory>
#include <string>
#include "Device.h"

class Device;
class Logger;

class Controller {
private:
    std::vector<std::unique_ptr<Device>> devices;
    stdm:shared_ptr<Logger> logger;
    double maxPower; //potenza massima 
    double solarProduction; //produzione solare
    double currentPower; //potenza attuale
    std::string currentTime; //orario attuale

    void enforcePowerLimit(); //applica il limite della potenza

public:
    Controller(double maxPower, double solarProduction); //costruttore
    ~Controller (); //distruttore
    
    //gestione dispositivi
    void addDevice(const std::shared_ptr<Device> device);
    void turnOn(const std::string& deviceName);
    void turnOff(const std::string& deviceName);

    //gestione timer
    void setDeviceTimer(const std::string& deviceName, const std::string& startTime, const std::string& stopTime);
    void removeDeviceTimer(const std::string& deviceName);

    //monitoraggio devices
    void showDevices() const;
    void showDevice(const std::string& deviceName) const;

    //gestione del tempo
    void setTime(const std::string& time);
    void resetTime();
    void resetTimers();
    void resetAll();
};

#endif //CONTROLLER_H
