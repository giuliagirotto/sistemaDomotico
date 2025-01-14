//GIROTTO GIULIA 2109947
#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include "Logger.h"
#include "Controller.h"
#include "Device.h"
#include "DeviceCP.h"
#include "DeviceM.h"


// Funzione per validare un orario nel formato HH:MM
bool isValidTime(const std::string& time) {
    try {
        if (time.length() != 5 || time[2] != ':') return false; //controllo formato ora HH:MM
        int hours = std::stoi(time.substr(0, 2));
        int minutes = std::stoi(time.substr(3, 2));
        return hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60; //controllo range valori
    } catch (const std::exception&) {
        return false;
    }
}

//funzione per controllo dell'iniziale
bool startsWith(const std::string& str, const std::string& prefix){
    if(str.size()<prefix.size()){
        return false; //la stringa è più corta del prefisso di controllo
    }
    return str.compare(0,prefix.size(), prefix)==0; //confronta il prefisso
}

// Funzione helper per accensione/spegnimento dispositivo
void handleDeviceAction(const std::string& deviceName, const std::string& action, Logger& log, Controller& control) {
    if (action == "on") {
        control.turnOn(deviceName);
    } else if (action == "off") {
        control.turnOff(deviceName);
    } else {
        throw std::invalid_argument("Azione non valida: " + action);
    }
}

void processCommand(const std::string& command, Logger& log, Controller& control) {
    static const std::unordered_map<std::string, int> commandMap = { //associo alle funzioni un numero così da poterle usare nello switch
        {"set", 1},
        {"rm", 2},
        {"show", 3},
        {"reset", 4}
    };

    size_t spacePos = command.find(' ');
    std::string mainCommand = command.substr(0, spacePos);
    std::string args = (spacePos != std::string::npos) ? command.substr(spacePos + 1) : "";

    auto it = commandMap.find(mainCommand);
    if (it == commandMap.end()) {
        log->logEvent("Comando non riconosciuto: " + command);
        return;
    }


    try {
        switch (it->second) {
            case 1: {
                //Gestione del comando "set"
                if (startsWith(args, "time ")) { //controllo la prima sottostringa per vedere se è set
                    std::string time = args.substr(5);
                    if (isValidTime(time)) {
                        control.setTime(time);
                    } 
                } else {
                    size_t lastSpace = args.find(' '); //controllo per il nome del device
                    if (lastSpace == std::string::npos){
                        throw std::invalid_argument("Nome dispositivo e azione non validi.");
                    }
                    std::string deviceName = args.substr(0, lastSpace);
                    std::string action = args.substr(lastSpace + 1);
                    handleDeviceAction(deviceName, action, log, control); //manipolo il device
                }
                break;
            }
            case 2: { //remove
                control.removeDeviceTimer(args);
                break;
            }
            case 3: { //show
                if (args.empty()) {
                    control.showDevices();
                } else {
                    control.showDevice(args);
                }
                break;
            }
            case 4: {//time
                if (args == "time") {
                    control.resetTime();
                } else if (args == "timers") {
                    control.resetTimers();
                } else if (args == "all") {
                    control.resetAll();
                } else {
                    throw std::invalid_argument("Argomento non valido per il reset: " + args);
                }
                break;
            }
            default:
                throw std::logic_error("Comando non gestito correttamente.");
        }
    } catch (const std::exception& e) {
        logEvent(e.what());
    }
}

int main() {
    Logger log("log.txt");
    Controller control(3.4, 3.5); // Classe per gestire i dispositivi e i timer

    // Lista dei dispositivi usando shared_ptr
    std::vector<std::shared_ptr<Device>> devices;
    devices.push_back(std::make_shared<DeviceM>("Impianto fotovoltaico", 1, +1.5, control));
    devices.push_back(std::make_shared<DeviceCP>("Lavatrice", 2, -2.0, 110,control));
    devices.push_back(std::make_shared<DeviceCP>("Lavastoviglie", 3, -1.5, 195,control));
    devices.push_back(std::make_shared<DeviceM>("Pompa di calore + termostato", 4, -2.0,control));
    devices.push_back(std::make_shared<DeviceCP>("Tapparelle elettriche", 5, -0.3, 1,control));
    devices.push_back(std::make_shared<DeviceM>("Scaldabagno", 6, -1,control));
    devices.push_back(std::make_shared<DeviceM>("Frigorifero", 7, -0.4,control));
    devices.push_back(std::make_shared<DeviceCP>("Forno a microonde", 8, -0.8, 2, control));
    devices.push_back(std::make_shared<DeviceCP>("Asciugatrice", 9, -0.5, 60, control));
    devices.push_back(std::make_shared<DeviceCP>("Televisore", 10, -0.2, 60, control));

    for(auto device : devices) {    //aggiungo device al controller
        control.addDevice(device);
    }

    std::cout << "Sistema domotico avviato. Inserisci un comando:" << std::endl;

    std::string command;
    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, command);
        processCommand(command, log, control);
    }

    return 0;
}
