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
void logAndPrintError(Logger& logger, const std::string& message) {
    logger.logEvent(message);
    std::cout << "Errore: " << message << std::endl;
}

// Funzione helper per accensione/spegnimento dispositivo
void handleDeviceAction(const std::string& deviceName, const std::string& action, Logger& logger, Controller& controller) {
    if (action == "on") {
        if (controller.turnDeviceOn(deviceName)) {
            logger.logEvent("Il dispositivo '" + deviceName + "' si è acceso.");
        } else {
            throw std::runtime_error("Impossibile accendere il dispositivo: " + deviceName);
        }
    } else if (action == "off") {
        if (controller.turnDeviceOff(deviceName)) {
            logger.logEvent("Il dispositivo '" + deviceName + "' si è spento.");
        } else {
            throw std::runtime_error("Impossibile spegnere il dispositivo: " + deviceName);
        }
    } else {
        throw std::invalid_argument("Azione non valida: " + action);
    }
}

void processCommand(const std::string& command, Logger& logger, Controller& controller) {
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
        logAndPrintError(logger, "Comando non riconosciuto: " + command);
        return;
    }

    try {
        switch (it->second) {
            case 1: {
                // Gestione del comando "set"
                if (args.starts_with("time ")) {
                    std::string time = args.substr(5);
                    if (isValidTime(time)) {
                        controller.setTime(time);
                        logger.logEvent("Orario impostato a: " + time);
                    } else {
                        throw std::invalid_argument("Orario non valido: " + time);
                    }
                } else {
                    size_t firstSpace = args.find(' ');
                    std::string deviceName = args.substr(0, firstSpace);
                    std::string action = args.substr(firstSpace + 1);
                    handleDeviceAction(deviceName, action, logger, controller);
                }
                break;
            }
            case 2: {
                if (controller.removeTimer(args)) {
                    logger.logEvent("Rimosso il timer dal dispositivo '" + args + "'.");
                } else {
                    throw std::runtime_error("Impossibile rimuovere il timer per il dispositivo: " + args);
                }
                break;
            }
            case 3: {
                if (args.empty()) {
                    logger.logEvent("Mostrati tutti i consumi.");
                    controller.showAllDevices();
                } else {
                    logger.logEvent("Mostrato consumo per dispositivo: " + args);
                    controller.showDevice(args);
                }
                break;
            }
            case 4: {
                if (args == "time") {
                    controller.resetTime();
                    logger.logEvent("Orario resettato.");
                } else if (args == "timers") {
                    controller.resetTimers();
                    logger.logEvent("Timers resettati.");
                } else if (args == "all") {
                    controller.resetAll();
                    logger.logEvent("Sistema resettato alle condizioni iniziali.");
                } else {
                    throw std::invalid_argument("Argomento non valido per il reset: " + args);
                }
                break;
            }
            default:
                throw std::logic_error("Comando non gestito correttamente.");
        }
    } catch (const std::exception& e) {
        logAndPrintError(logger, e.what());
    }
}

int main() {
    Logger logger("domotica.log");
    Controller controller; // Classe per gestire i dispositivi e i timer

    std::cout << "Sistema domotico avviato. Inserisci un comando:" << std::endl;

    std::string command;
    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, command);
        processCommand(command, logger, controller);
    }

    return 0;
}
