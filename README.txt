#eventuali problemi

home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp: In destructor ‘Controller::~Controller()’:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:21:3: error: ‘log’ was not declared in this scope; did you mean ‘long’?
   21 |   log.logEvent("[" + currentTime + "] Sistema domotico terminato");
      |   ^~~
      |   long
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp: In member function ‘int Controller::compareTime(const string&, const string&)’:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:31:8: error: ‘istringstram’ is not a member of ‘std’; did you mean ‘istringstream’?
   31 |   std::istringstram timeStream2(time2);
      |        ^~~~~~~~~~~~
      |        istringstream
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:32:3: error: ‘timeStream2’ was not declared in this scope; did you mean ‘timeStream1’?
   32 |   timeStream2 >> hours2 >> dot >> minutes2;
      |   ^~~~~~~~~~~
      |   timeStream1
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp: At global scope:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:68:6: error: no declaration matches ‘void Controller::addDevice(const std::shared_ptr<Device>&)’
   68 | void Controller::addDevice(const std::shared_ptr<Device>& device){
      |      ^~~~~~~~~~
In file included from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:2:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/Controller.h:31:10: note: candidate is: ‘void Controller::addDevice(std::shared_ptr<Device>)’
   31 |     void addDevice(const std::shared_ptr<Device> device);
      |          ^~~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/Controller.h:13:7: note: ‘class Controller’ defined here
   13 | class Controller {
      |       ^~~~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp: In member function ‘void Controller::turnOn(const string&)’:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:78:21: error: ‘class std::vector<std::unique_ptr<Device> >’ has no member named ‘find’
   78 |   auto it = devices.find(deviceName);
      |                     ^~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:80:60: error: ‘device’ was not declared in this scope; did you mean ‘Device’?
   80 |     throw std::runtime_error("Dispositivo non trovato: " + device->getName());
      |                                                            ^~~~~~
      |                                                            Device
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:88:7: error: ‘log’ was not declared in this scope; did you mean ‘long’?
   88 |       log.logEvent("[" + currentTime + "] Il dispositivo " + device -> getName() + " è acceso.");
      |       ^~~
      |       long
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:88:62: error: ‘device’ was not declared in this scope; did you mean ‘Device’?
   88 |      log.logEvent("[" + currentTime + "] Il dispositivo " + device -> getName() + " è acceso.");
      |                                                             ^~~~~~
      |                                                             Device
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:95:25: error: qualified-id in declaration before ‘(’ token
   95 | void Controller::turnOff(const std::string& deviceName){
      |                         ^
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:110:33: error: qualified-id in declaration before ‘(’ token
  110 | void Controller::setDeviceTimer (const std::string& deviceName, const std::string& startTime, const std::string& stopTime){
      |                                 ^
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:121:36: error: qualified-id in declaration before ‘(’ token
  121 | void Controller::removeDeviceTimer (const std::string& deviceName){
      |                                    ^
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:132:29: error: qualified-id in declaration before ‘(’ token
  132 | void Controller::showDevices() const{
      |                             ^
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:239:2: error: expected ‘}’ at end of input
  239 | }
      |  ^
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/Controller.cpp:77:55: note: to match this ‘{’
   77 | void Controller::turnOn(const std::string& deviceName){
      |                                                       ^
make[2]: *** [CMakeFiles/sistemaDomotico.dir/build.make:90: CMakeFiles/sistemaDomotico.dir/src/Controller.cpp.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:83: CMakeFiles/sistemaDomotico.dir/all] Error 2
make: *** [Makefile:91: all] Error 2
