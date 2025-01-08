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
void Controller::turnOn(const std::string& deviceName){
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
void Controller::turnOff(const std::string& deviceName){
  auto it = devices.find(deviceName); 
  if(it == devices.end()){ //controllo se il dispositivo è nella lista
    throw std::runtime_error("Dispositivo non trovato: " + device->getName()); 
  }  
  
  if(it == isDeviceOn()){
    it == turnOff();
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
  auto foundDevice = device -> second;
  foundDevice -> setTimer(startTime, stopTime);
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
  //inizializza i contatori per energia prodotta e consumata
  double totalEnergyProduced = 0.0;
  double totalEnergyConsumed = 0.0;

  for(const auto& [name, device] : devices){
    double energy = device->getEnergyConsumed();
    if(energy>0){
      totalEnergyProduced += energy;
    }else{
       totalEnergyConsumed += -energy;
    }
  }
  //Scrivo nel logger
  logger.logEvent("Il sistema, fino a questo momento, ha prodotto: " + std::toString(totalEnergyProduced) +
    " kW e consumato " + std::toString(totalEnergyConsumed) + " kW.";
  for(const auto& [name,device] : devices) {
    double deviceEnergy = device->getEnergyConsumed();
    std::string tipo = (deviceEnergy>0) ? "profotto " : "consumato ";
    if(deviceEnergy<0){
      deviceEnergy = -deviceEnergy;
    }
    logger.logEvent("- Il dispositivo '" + device.getName() + "' ha " +
      tipo + std::to_string(deviceEnergy) + " kWh");
  }

//Visualizzo un dispositivo e il suo consumo specifico
void Controller::showDevice(const std::string& deviceName) const{
  auto it = devices.find(deviceName);
  if(it == devices.end()){
    throw std::runtime_error("Dispositivo non trovato: " + deviceName);
  }
  double energia = device ->second->getEnergyConsumed();
  std::string tipo = (energia>0) ? "prodotto" : "consumato";
  logger.logEvent("Il dispositivo '" + device.getName() + "' ha " +
      tipo + std::to_string(deviceEnergy) + " kWh");
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
void Controller::resetTimers(){
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

  std::vector<std::pair<std::string, std::shared_ptr<Device>>> activeDevices;
  for (const auto&& [name,device] : devices){
    if(device->isOn() && device->getName() != "Frigorifero"){ //non spengo il frigorifero
      activateDevices.push_back({name,device});
    }
  }

//Spengo i dispositivi nel caso in cui la potenza massima sia stata superata
  for (const auto& [name,device] : activeDevices) {
    if (currentPower <= (maxPower + solarProduction)){
      break;
    }
    device -> turnOff();
    currentPower -= device->getPower();
    logger.logEvent("Il dispositivo " + device->getName() + " è stato spento per eccesso di consumo.");
  }
}
  



