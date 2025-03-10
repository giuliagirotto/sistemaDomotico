//SILVIA MARCATO 2109577
#include "Controller.h"
#include "Logger.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

//costruttore del controller
Controller::Controller(double maxPower, double solarProduction): 
  maxPower(maxPower), 
  solarProduction(solarProduction), 
  currentPower(0.0), 
  currentTime("00.00") {
  logger = std::make_shared<Logger>("log.txt");
  logger->logEvent("["+ currentTime + "] Sistema domotico avviato");
}

//distruttore
Controller::~Controller(){
  logger->logEvent("[" + currentTime + "] Sistema domotico terminato");
}

int Controller::compareTime(const std::string& time1, const std::string& time2){
  int hours1, minutes1, hours2, minutes2;
  char dot;

  std::istringstream timeStream1(time1);
  timeStream1 >> hours1 >> dot >> minutes1;

  std::istringstream timeStream2(time2);
  timeStream2 >> hours2 >> dot >> minutes2;

  if(hours1 < hours2 || (hours1 == hours2 && minutes1 < minutes2)){ //confronto due orari
      return -1;
    } else if (hours1 == hours2 && minutes1 == minutes2){
      return 0;
    } else {
      return 1;
    }
}

//Incremento del tempo di un minuto
std::string Controller::incrementMinute(const std::string& time){
  int hours, minutes;
  char dot;

  std::istringstream timeStream(time);
  timeStream >> hours >> dot >> minutes;

  minutes++;
  if(minutes == 60) {
    minutes = 0;
    hours++;
  }
  if(hours == 24){
    hours = 0;
  }

  std::ostringstream newTime; //genero la stringa del nuovo orario
  newTime << (hours < 10 ? "0" : "") << hours << "."
          << (minutes < 10 ? "0" : "") << minutes;
  return newTime.str();
}

//GESTIONE DEI DISPOSITIVI; 
//Aggiungo un dispositivo alla mia lista
void Controller::addDevice(const std::shared_ptr<Device>& device){
  if(devices.find(device->getName()) != devices.end()){
    throw std::runtime_error("Il dispositivo: " + device->getName() + " esiste già.");
  }
  devices[device->getName()] = device;
  logger->logEvent("[" + currentTime + "] Aggiunto dispositivo: " + device->getName());
}

//Accendo un dispositivo e aggiorno la potenza
void Controller::turnOn(const std::string& deviceName){
  auto it = devices.find(deviceName);
  if(it == devices.end()){ //controllo se il dispositivo è nella lista
    throw std::runtime_error("Dispositivo non trovato: " + deviceName);
  }

  if(!it ->second->isDeviceOn()){
    double newPower = currentPower + it ->second->getInstantPower();
    if(newPower <= (maxPower + solarProduction)) {
      it->second->turnOn();
      currentPower = newPower; 
      logger->logEvent("[" + currentTime + "] Il dispositivo " + it->second-> getName() + " è acceso.");
    } else {
      enforcePowerLimit(); //Mi assiucuro che il limite di potenza non sia superato
    }  
}}

//Spengo un dispositivo e aggiorno la potenza
void Controller::turnOff(const std::string& deviceName){
  auto it = devices.find(deviceName); 
  if(it == devices.end()){ //controllo se il dispositivo è nella lista
    throw std::runtime_error("Dispositivo non trovato: " + deviceName); 
  }  
  
  if(it->second-> isDeviceOn()){
    it->second->turnOff();
    currentPower -= it->second->getInstantPower();
    logger->logEvent("[" + currentTime+ "] Il dispositivo " + it->second -> getName() + " è spento.");
  }
}

//GESTISCO IL TIMER 
//Imposto il timer per un dispositivo
void Controller::setDeviceTimer (const std::string& deviceName, const std::string& startTime, const std::string& stopTime){
  auto it = devices.find(deviceName);
  if(it == devices.end()){
    throw std::runtime_error("Dispositivo non trovato: " + deviceName);
  }
  auto foundDevice = it-> second;
  foundDevice -> setTimer(startTime, stopTime);
  logger->logEvent("[" + currentTime +"] Impostato un timer per il dispositivo " + deviceName + " dalle " + startTime + " alle " + stopTime);
}

//Rimuovo il timer per un dispositivo
void Controller::removeDeviceTimer (const std::string& deviceName){
  auto it = devices.find(deviceName);
  if(it == devices.end()){
    throw std::runtime_error("Dispositivo non trovato: " + deviceName);
  }
  it -> second -> removeTimer();
  logger->logEvent("[" + currentTime + "] Rimosso il timer dal dispositivo " + deviceName);
}

//MONITORO LA POTENZA  
//Visualizzo la lista dei sispositivi e il consumo totale
void Controller::showDevices() const{
  //inizializza i contatori per energia prodotta e consumata
  double totalEnergyProduced = 0.0;
  double totalEnergyConsumed = 0.0;

  for(const auto& [name, device] : devices){
    double energy = device->getTotalEnergyConsumed();
    if(energy>0){
      totalEnergyProduced += energy;
    }else{
       totalEnergyConsumed += -energy;
    }
  }
  //Scrivo nel logger
  logger->logEvent("[" + currentTime + "] Il sistema, fino a questo momento, ha prodotto: " + 
      std::to_string(totalEnergyProduced) + " kW e consumato " + 
      std::to_string(totalEnergyConsumed) + " kW.");
  for(const auto& [name,device] : devices) {
    double deviceEnergy = device->getTotalEnergyConsumed();
    std::string tipo = (deviceEnergy>0) ? "prodotto " : "consumato ";
    if(deviceEnergy<0){
      deviceEnergy = -deviceEnergy;
    }
    logger->logEvent("[" + currentTime + "] Il dispositivo '" + device->getName() + "' ha " +
      tipo + std::to_string(deviceEnergy) + " kWh");
  }
}

//Visualizzo un dispositivo e il suo consumo specifico
void Controller::showDevice(const std::string& deviceName) const{
  auto it = devices.find(deviceName);
  if(it == devices.end()){
    throw std::runtime_error("Dispositivo non trovato: " + deviceName);
  }
  double energia = it ->second->getTotalEnergyConsumed();
  std::string tipo = (energia>0) ? "prodotto" : "consumato";
  logger->logEvent("[" + currentTime + "] Il dispositivo '" + it->second->getName() + "' ha " +
      tipo +" "+ std::to_string(energia) + " kWh");
}

//MOSTRO IL TEMPO
void Controller::setTime(const std::string& time){
  if(compareTime(time, currentTime) <= 0){
    throw std::runtime_error("L'orario deve essere nel futuro rispetto a quello attuale.");
  }
  std::string tempTime = currentTime;
  while (compareTime(tempTime, time) < 0){
    tempTime = incrementMinute(tempTime);
    for(auto& [name,device] : devices){
      device->checkTimer(tempTime);
    }
    enforcePowerLimit();
  }
  currentTime = time;
  logger->logEvent("[" + currentTime + "] L'orario attuale è " + currentTime +" (alla fine dell'esecuzione)");
}

//Reset orario
void Controller::resetTime(){
  currentTime = "00.00";
  for (auto& [name,device] : devices){
      device->turnOff();
    }
  currentPower = 0.0;
  logger->logEvent("[" + currentTime + "] L'orario attuale è " + currentTime);
}

//Reset timer
void Controller::resetTimers(){
  for(auto& [name, devices] : devices){
    devices -> removeTimer();
  }
  logger->logEvent("[" + currentTime + " ] Tutti i timer sono stati rimossi.");
}

//Reset del sistema
void Controller::resetAll(){
  resetTime();
  resetTimers();
  for(auto& [name, devices] : devices){
    devices -> turnOff();
  }
  currentPower = 0.0;
  logger->logEvent("[" + currentTime + " ] Il sistema è stato resettato.");
}

//LIMITE POTENZA
void Controller::enforcePowerLimit(){
  if (currentPower <= (maxPower+solarProduction)){
    return;
  }

  std::vector<std::pair<std::string, std::shared_ptr<Device>>> activeDevices;
  for (const auto& [name,device] : devices){
    if(device->isDeviceOn() && device->getName() != "Frigorifero"){ //non spengo il frigorifero
      activeDevices.push_back({name,device});
    }
  }
  //Inverto l'ordine dei device per spegnerli in ordine opposto a quello di accensione
  std::reverse(activeDevices.begin(), activeDevices.end());
  //Spengo i dispositivi nel caso in cui la potenza massima sia stata superata
  for (const auto& [name,device] : activeDevices) {
    if (currentPower <= (maxPower + solarProduction)){
      break;
    }
    device -> turnOff();
    currentPower -= device->getInstantPower();
    logger->logEvent("[" + currentTime + " ] Il dispositivo " + device->getName() + " è stato spento per eccesso di consumo.");
  }
}
