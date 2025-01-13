# Dichiarazione della versione minima di CMake
cmake_minimum_required(VERSION 3.10)

# Nome del progetto
project(sistemaDomotico)

# Usa lo standard C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Usa le opzioni di ottimizzazione attivate(-O2)
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Aggiungi file sorgente
set(SOURCES
  src/main.cpp
  src/Controller.cpp
  src/Device.cpp
  src/DeviceCP.cpp
  src/DeviceM.cpp
  src/Logger.cpp
)

# Aggiungi file header
set(HEADERS
  Include/Controller.h
  Include/Device.h
  Include/DeviceCP.h
  Include/DeviceM.h
  Include/Logger.h
)

# Crea un eseguibile chiamato "sistemaDomotico" con i file trovati
add_executable(sistemaDomotico ${SOURCES} ${HEADERS})

# Includi la directory
target_include_directories(sistemaDomotico PRIVATE Include)

# Imposta la directory di output
set_target_properties(sistemaDomotico
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
