//GIROTTO GIULIA 2109947
#include "Logger.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <iomanip>

//costruttore: apre file di log per scriverci 
Logger::Logger(const std::string& fileName){
    logFile.open(fileName, std::ios::app);  //apre in modalità append->aggiunge senza sovrascrivere
    if(!logFile){
        throw std::runtime_error("Impossibile aprire il file di log: " + fileName);
    }
}

//metodo per ottenere il timestamp attuale
std::string Logger::getCurrentTime() const{
    auto now=std::time(nullptr);
    auto tm=*std::localtime(&now);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%H:%M"); // Formatta l'orario
    return oss.str();
}

//metodo per loggare un evento generico
void Logger::logEvent(const std::string& event){
    //std::string timestamp=getCurrentTime();
    std::string logMessage = "prova" + event; // [HH:MM] Evento

    if(logFile)logFile<<logMessage<<"\n";  //scrive nel nel file
    std::cout<<logMessage<<"\n";    //stampa a terminale
}

//metodo per loggare un evento con valore
void Logger::logEvent(const std::string& event, double value, const std::string& unit){
    std::ostringstream oss;
    oss << event << ": " << value << " " << unit;
    logEvent(oss.str()); // Richiama il metodo generico
}

//distruttore: chiude il file di log
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}