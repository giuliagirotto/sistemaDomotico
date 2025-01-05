//GIROTTO GIULIA 2109947
#ifdef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomainip>

class Logger{
    private:
        std::ofstream logFile;

        //metodo per ottenere il timestamp attuale
        std::string getCurrentTime() const;
    
    public:
        //costruttore
        Logger(const std::string& fileName);

        //metodo per registrare un evento generico nel file di log e sul terminale
        void logEvent(const std::string& event);

        // Metodo per registrare un evento con valore numerico (es. [07:00] Consumo totale del sistema: 3.5 kW)
        void logEvent(const std::string& event, double value, const std::string& unit);
        // Distruttore
        ~Logger();
};

#endif