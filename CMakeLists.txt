# Dichiarazione della versione minima di CMake
cmake_minimum_required(VERSION 3.10)

# Nome del progetto
project(sistemaDomotico)

# Usa lo standard C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Aggiungi la directory "include" ai percorsi di ricerca dei file header
include_directories(include)

# Cerca tutti i file sorgente nella directory "src"
file(GLOB SOURCES "src/*.cpp")

# Crea un eseguibile chiamato "sistemaDomotico" con i file trovati
add_executable(sistemaDomotico ${SOURCES})