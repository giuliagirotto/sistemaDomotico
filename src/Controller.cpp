#include "Controller.h"
#include "Logger.h"
#include <iostream>
#include <sstream>
#include <vector>

//costruttore del controller
Controller::Controller(double maxPower, double solarProduction): 
maxPower(maxPower), solarProduction(solarProduction), currentPower(0.0), currentTime("00.00") {
  logger = std::make_shares<Logger>("log.txt");
  logger.logEvent("Sistema domotico avviato");
}

//distruttore
Controller::~Controller(){
  logger.logEvent("Sistema domotico terminato");
}

//GESTIONE DEI DISPOSITIVI; 
//Aggiungo un dispositivo alla mia lista
void Controller::addDevice(const std::shared_ptr<Device>& device){
  if(devices.find(device->getName() != devices.end()){
    throw std::runtime_error("Il dispositivo: " + device->getName() + " esiste già.");
  }
  device[device->getName()] = device;
  logger.logEvent("Aggiunto dispositivo: " + device->getName());
}

//Accendo un dispositivo e aggiorno la potenza
void Controller::turnOn(const::shared_ptr<Device>&device){
  auto it = devices.find(deviceName);
  if(it == devices.end()){ //controllo se il dispositivo è nella lista
    throw std::runtime_error("Dispositivo non trovato: " + device->getName());
  }

  if(!it == isDeviceOn()){
    double newPower = currentPower + it ->second->getPower();
    if(newPower <= (maxPower + solarProduction)) {
      it->second->turnOn();
      currentPower = newPower; 
      logger.logEvent("Il dispositivo " + device -> getName() + " è acceso.");
    } else {
      enforcePowerLimit(); //Mi assiucuro che il limite di potenza non sia superato
    }  
}

//Spengo un dispositivo e aggiorno la potenza
void Controller::turnOff(const::shared_ptr<Device>&device){
  auto it = devices.find(deviceName); 
  if(it == devices.end()){ //controllo se il dispositivo è nella lista
    throw std::runtime_error("Dispositivo non trovato: " + device->getName()); 
  }  
  
  if(device == isDeviceOn()){
    device == turnOff();
    currentPower -= device -> getPower();
    logger.logEvent("Il dispositivo " + device -> getName() + " è spento.");
  }
}

//GESTISCO IL TIMER 
//Imposto il timer per un dispositivo
void Controller::setDeviceTimer (const std::string& deviceName, const std::string& startTime, const sdt::string& stopTime){
  auto it = devices.find(deviceName);
  if(it == devices.end()){
    throw std::runtime_error("Dispositivo non trovato: " + deviceName);
  }
  it -> second -> setTimer(startTime, stopTime);
  logger.logEvent("Impostato un timer per il dispositivo: " + deviceName + " dalle " + startTime + " alle " + stopTime);
}

//Rimuovo il timer per un dispositivo
void Controller::removeDeviceTimer (const std::string& deviceName){
  auto it = devices.find(deviceName);
  if(it == devices.end()){
    throw std::runtime_error("Dispositivo non trovato: " + deviceName);
  }
  it -> second -> removeTimer();
  logger.logEvent("Rimosso il timer per il dispositivo: " + deviceName + " ");
}

//MONITORO LA POTENZA  ?????????????????????????????????????????????????????????????????????????????????
//Visualizzo la lista dei sispositivi e il consumo totale
void Controller::showDevices() const{
  double totalEnergyProduced = 0.0;
  double totalEnergyConsumed = 0.0;
  
  std::cout<<"Lista dei dispositivi attivi e inzattivi: " << std::endl;
  for(const auto& device : devices) {
    std::cout << device -> getName() << " " << << device -> isOn() ? "Acceso" : "Spento") 
              << " - Potenza: " << device -> getPower() << " kW" << std::endl;
  }
  double totalConsumption = calcolateConsumption();
  std::cout << "Consumo totale del sistema: " << totalConsumption << " kW" << std::endl;
}

//Visualizzo un dispositivo e il suo consumo specifico
void Controller::showDevice(const std::string& deviceName) const{
  auto it = devices.find(deviceName);
  if(it == devices.end()){
    throw std::runtime_error("Dispositivo non trovato: " + deviceName);
  }
  std::cout 
}

//MOSTRO IL TEMPO
void Controller::setTime(const std::string& time){
  if(compareTime(time, currentTime) <= 0){
    throw std::runtime_error("L'orario deve essere nel futuro rispetto a quello attuale.");
  }
  std::string tempTime = currentTime;
  while (compareTime(tempTime, time) < 0){
    tempTime = incrementMinute(tempTime);
    for(auto& [name,device] : device){
      device->checkTimer(tempTime);
    }
    enforcePowerLimit();
  }
  currentTime = time;
  logger.logEvent("Orario attuale: " + currentTime);
}

//Reset orario
void Controller::resetTime(){
  currentTime = "00.00";
  for (auto& [name,device] : device){
      device->turnOff();
    }
  currentPower = 0.0;
  logger.logEvent("Orario attuale: " + currentTime);
}

//Reset timer
void Controller::resetTimer(){
  for(auto& [name, devices] : devices){
    device -> removeTimer();
  }
  logger.logEvent("Tutti i timer sono stati rimossi.");
}

//Reset del sistema
void Controller::resetAll(){
  resetTime();
  resetTimers();
  for(auto& [name, devices] : devices){
    device -> turnOff();
  }
  currentPower = 0.0;
  logger.logEvent("Il sistema è stato resettato.");
}

//LIMITE POTENZA
void Controller::enforcePowerLimit(){
  if (currentPower <= (maxPower+solarProduction)){
    return;
  }

  std:

  



