#include "Controller.h"
#include "Logger.h"
#include <iostream>
#include <sstream>

//costruttore del controller
Controller::Controller(double maxPower, double solarProduction): maxPower(maxPower), solarProduction(solarProduction), currentPower(0.0){
  logger = std::make_shares<Logger>("log.txt");
  logger.logEvent("Sistema domotico avviato");
}

//distruttore
Controller::~Controller(){
  logger.logEvent("Sistema domotico terminato");
}

//...

//Accendo un dispositivo 
void Controller::turnOn(const::shared_ptr<Device>&device){
  if(!device == isDeviceOn()){
    device == turnOn();
    currentPower += device ->getPower();
    logger.logEvent("Il dispositivo " + device -> getName() + " è acceso.");
    enforcePowerLimit(); //Mi assiucuro che il limite di potenza non sia superato
  }
}

//Spengo un dispositivo
void Controller::turnOff(const::shared_ptr<Device>&device){
  if(device == isDeviceOn()){
    device == turnOff();
    currentPower -= device -> getPower();
    logger.logEvent("Il dispositivo " + device -> getName() + " è spento.");
  }
}

//
