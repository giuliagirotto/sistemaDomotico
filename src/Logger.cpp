//GIROTTO GIULIA 2109947
#include "Logger.h"
#include <iostream>

//costruttore: apre file di log per scriverci 
Logger::Logger(const std::string& fileName){
    logFile.open(fileName, std::ios::app);  //apre in modalità append->aggiungo senza sovrascrivere
    if(!logFile){
        std::cerr<<"... ERRORE - impossibile aprire il file di log..."<<std::endl;
    }
}

//metodo per ottenere il timestamp attuale
std::string Logger::getCurrentTime() const{
    auto now=std::time(nullptr);
    auto tm=*std::localtime(&now);

    std::ostringstream oss;
    oss << "[" << std::put_time(&tm, "%H:%M") << "]"; // [orario]
    return oss.str();
}

//metodo per loggare un evento generico
void Logger::logEvent(const std::string& event){
    std::string timestamp=getCurrentTime();
    std::string logMessage=timestamp+" "+event; //[orarioattuale] evento

    if(logFile)logFile<<logMessage<<std:endl;  //scrivo nel nel file
    std::cout<<logMessage<<std::endl;    //stampo a terminale
}

//metodo per loggare un evento con valore
void Logger::logEvent(const std::string& evenet, double value, const std::string& unit){
    std::ostringstream oss;
    oss << event << ": " << value << " " << unit;
    
    logEvent(oss.str());
}

//distruttore: chiude il file di log
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}