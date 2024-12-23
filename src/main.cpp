#include <iostream>
#include <string>
#include "Logger.h"
#include "Controller.h"

int main(){
// Funzione per validare un orario nel formato HH:MM
bool isValidTime(const std::string& time) {
    if (time.length() != 5 || time[2] != ':') return false;
    int hours = std::stoi(time.substr(0, 2));
    int minutes = std::stoi(time.substr(3, 2));
    return hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60;
}

void processCommand(const std::string& command, Logger& logger, Controller& controller) {
    // Mappa dei comandi principali a interi
    static const std::unordered_map<std::string, int> commandMap = {
        {"set", 1},
        {"rm", 2},
        {"show", 3},
        {"reset", 4},
        {"exit", 5}
    };

    size_t spacePos = command.find(' ');
    std::string mainCommand = command.substr(0, spacePos); // Comando principale
    std::string args = (spacePos != std::string::npos) ? command.substr(spacePos + 1) : "";

    auto it = commandMap.find(mainCommand);
    if (it == commandMap.end()) {
        logger.logEvent("Comando non riconosciuto: " + command);
        std::cout << "Errore: comando non valido." << std::endl;
        return;
    }

    switch (it->second) {
        case 1: { // "set"
           if (args.find("time") == 0) {
        // Comando "set time HH:MM"
        std::string time = args.substr(5);
        if (isValidTime(time)) {
            controller.setTime(time);
            logger.logEvent("Orario impostato a: " + time);
        } else {
            logger.logEvent("Errore: orario non valido.");
        }
    } else {
        // Comandi "set DEVICE_NAME on/off" o "set DEVICE_NAME HH:MM [HH:MM]"
        size_t firstSpace = args.find(' ');
        std::string deviceName = args.substr(0, firstSpace);
        std::string action = args.substr(firstSpace + 1);

        if (action == "on") {
            // Accensione dispositivo
            if (controller.turnDeviceOn(deviceName)) {
                logger.logEvent("Il dispositivo '" + deviceName + "' si è acceso.");
            } else {
                logger.logEvent("Errore: dispositivo '" + deviceName + "' non trovato.");
            }
        } else if (action == "off") {
            // Spegnimento dispositivo
            if (controller.turnDeviceOff(deviceName)) {
                logger.logEvent("Il dispositivo '" + deviceName + "' si è spento.");
            } else {
                logger.logEvent("Errore: dispositivo '" + deviceName + "' non trovato.");
            }
        } else if (isValidTime(action)) {
            // Imposta un timer (HH:MM o HH:MM [HH:MM])
            size_t secondSpace = action.find(' ');
            std::string startTime = action.substr(0, secondSpace);
            std::string endTime = (secondSpace != std::string::npos) ? action.substr(secondSpace + 1) : "";

            if (controller.setDeviceTimer(deviceName, startTime, endTime)) {
                logger.logEvent("Timer impostato per '" + deviceName + "' a partire da " + startTime +
                                (endTime.empty() ? "" : " fino a " + endTime) + ".");
            } else {
                logger.logEvent("Errore: impossibile impostare il timer per '" + deviceName + "'.");
            }
        } else {
            // Azione non valida
            logger.logEvent("Errore: comando 'set' non valido per '" + deviceName + "'.");
        }
    }
    break;
        }
        case 2: { // "rm"
            if (controller.removeTimer(args)) {
                logger.logEvent("Rimosso il timer dal dispositivo '" + args + "'.");
            } else {
                logger.logEvent("Errore: dispositivo '" + args + "' non trovato.");
            }
            break;
        }
        case 3: { // "show"
            if (args.empty()) {
                logger.logEvent("Mostrati tutti i consumi.");
                controller.showAllDevices();
            } else {
                logger.logEvent("Mostrato consumo per dispositivo: " + args);
                controller.showDevice(args);
            }
            break;
        }
        case 4: { // "reset"
            if (args == "time") {
                controller.resetTime();
                logger.logEvent("Orario resettato a 00:00.");
            } else if (args == "timers") {
                controller.resetTimers();
                logger.logEvent("Timer resettati.");
            } else if (args == "all") {
                controller.resetAll();
                logger.logEvent("Sistema resettato alle condizioni iniziali.");
            } else {
                logger.logEvent("Errore: comando 'reset' non valido.");
            }
            break;
        }
        case 5: { // "exit"
            logger.logEvent("Sistema domotico terminato.");
            std::exit(0);
            break;
        }
        default:
            logger.logEvent("Comando non riconosciuto: " + command);
            std::cout << "Errore: comando non valido." << std::endl;
            break;
    }

int main() {
    Logger logger("domotica.log");
    Controller controller; // Classe per gestire i dispositivi e i timer

    std::cout << "Sistema domotico avviato. Inserisci un comando:" << std::endl;

    std::string command;
    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, command); // Legge il comando dall'utente
        processCommand(command, logger, controller); // Processa il comando
    }

    return 0;
}