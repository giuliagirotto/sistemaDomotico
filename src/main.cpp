#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include "Logger.h"
#include "Controller.h"

// Funzione per validare un orario nel formato HH:MM
bool isValidTime(const std::string& time) {
    try {
        if (time.length() != 5 || time[2] != ':') return false;
        int hours = std::stoi(time.substr(0, 2));
        int minutes = std::stoi(time.substr(3, 2));
        return hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60;
    } catch (const std::exception&) {
        return false;
    }
}

// Funzione helper per loggare errori
void logAndPrintError(Logger& log, const std::string& message) {
    log.logEvent(message);
    std::cout << "Errore: " << message << std::endl;
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
        control.turnDeviceOn(deviceName);
        log.logEvent("Il dispositivo '" + deviceName + "' si è acceso.");
    } else if (action == "off") {
        control.turnDeviceOff(deviceName);
        log.logEvent("Il dispositivo '" + deviceName + "' si è spento.");
    } else {
        throw std::invalid_argument("Azione non valida: " + action);
    }
}

void processCommand(const std::string& command, Logger& log, Controller& control) {
    static const std::unordered_map<std::string, int> commandMap = {
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
        logAndPrintError(log, "Comando non riconosciuto: " + command);
        return;
    }

    
    try {
        switch (it->second) {
            case 1: {
                // Gestione del comando "set"
                if (args.starts_with("time ")) {
                    std::string time = args.substr(5);
                    if (isValidTime(time)) {
                        control.setTime(time);
                        logger.logEvent("Orario impostato a: " + time);
                    } else {
                        throw std::invalid_argument("Orario non valido: " + time);
                    }
                } else {
                    size_t firstSpace = args.find(' ');
                    std::string deviceName = args.substr(0, firstSpace);
                    std::string action = args.substr(firstSpace + 1);
                    handleDeviceAction(deviceName, action, log, control);
                }
                break;
            }
            case 2: {
                if (control.removeTimer(args)) {
                    log.logEvent("Rimosso il timer dal dispositivo '" + args + "'.");
                } else {
                    throw std::runtime_error("Impossibile rimuovere il timer per il dispositivo: " + args);
                }
                break;
            }
            case 3: {
                if (args.empty()) {
                    log.logEvent("Mostrati tutti i consumi.");
                    control.showAllDevices();
                } else {
                    log.logEvent("Mostrato consumo per dispositivo: " + args);
                    control.showDevice(args);
                }
                break;
            }
            case 4: {
                if (args == "time") {
                    control.resetTime();
                    log.logEvent("Orario resettato.");
                } else if (args == "timers") {
                    control.resetTimers();
                    log.logEvent("Timers resettati.");
                } else if (args == "all") {
                    control.resetAll();
                    log.logEvent("Sistema resettato alle condizioni iniziali.");
                } else {
                    throw std::invalid_argument("Argomento non valido per il reset: " + args);
                }
                break;
            }
            default:
                throw std::logic_error("Comando non gestito correttamente.");
        }
    } catch (const std::exception& e) {
        logAndPrintError(log, e.what());
    }
}

int main() {
    Logger log("domotica.log");
    Controller control(3.4, 3.5); // Classe per gestire i dispositivi e i timer

    std::cout << "Sistema domotico avviato. Inserisci un comando:" << std::endl;

    std::string command;
    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, command);
        processCommand(command, log, control);
    }

    return 0;
}
