#eventuali problemi

home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp: In function ‘int main()’:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:134:40: error: ‘DeviceM’ was not declared in this scope; did you mean ‘Device’?
  134 |     devices.push_back(std::make_shared<DeviceM>("Impianto fotovoltaico", 1, +1.5));
      |                                        ^~~~~~~
      |                                        Device
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:134:48: error: no matching function for call to ‘make_shared<<expression error> >(const char [22], int, double)’
  134 |     devices.push_back(std::make_shared<DeviceM>("Impianto fotovoltaico", 1, +1.5));
      |                       ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/11/memory:77,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/Controller.h:6,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:7:
/usr/include/c++/11/bits/shared_ptr.h:875:5: note: candidate: ‘template<class _Tp, class ... _Args> std::shared_ptr<_Tp> std::make_shared(_Args&& ...)’
  875 |     make_shared(_Args&&... __args)
      |     ^~~~~~~~~~~
/usr/include/c++/11/bits/shared_ptr.h:875:5: note:   template argument deduction/substitution failed:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:134:48: error: template argument 1 is invalid
  134 |     devices.push_back(std::make_shared<DeviceM>("Impianto fotovoltaico", 1, +1.5));
      |                       ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:135:40: error: ‘DeviceCP’ was not declared in this scope; did you mean ‘Device’?
  135 |     devices.push_back(std::make_shared<DeviceCP>("Lavatrice", 2, -2.0, 110));
      |                                        ^~~~~~~~
      |                                        Device
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:135:49: error: no matching function for call to ‘make_shared<<expression error> >(const char [10], int, double, int)’
  135 |     devices.push_back(std::make_shared<DeviceCP>("Lavatrice", 2, -2.0, 110));
      |                       ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/11/memory:77,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/Controller.h:6,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:7:
/usr/include/c++/11/bits/shared_ptr.h:875:5: note: candidate: ‘template<class _Tp, class ... _Args> std::shared_ptr<_Tp> std::make_shared(_Args&& ...)’
  875 |     make_shared(_Args&&... __args)
      |     ^~~~~~~~~~~
/usr/include/c++/11/bits/shared_ptr.h:875:5: note:   template argument deduction/substitution failed:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:135:49: error: template argument 1 is invalid
  135 |     devices.push_back(std::make_shared<DeviceCP>("Lavatrice", 2, -2.0, 110));
      |                       ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:136:49: error: no matching function for call to ‘make_shared<DeviceCP>(const char [14], int, double, int)’
  136 |     devices.push_back(std::make_shared<DeviceCP>("Lavastoviglie", 3, -1.5, 195));
      |                       ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/11/memory:77,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/Controller.h:6,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:7:
/usr/include/c++/11/bits/shared_ptr.h:875:5: note: candidate: ‘template<class _Tp, class ... _Args> std::shared_ptr<_Tp> std::make_shared(_Args&& ...)’
  875 |     make_shared(_Args&&... __args)
      |     ^~~~~~~~~~~
/usr/include/c++/11/bits/shared_ptr.h:875:5: note:   template argument deduction/substitution failed:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:137:48: error: no matching function for call to ‘make_shared<DeviceM>(const char [29], int, double)’
  137 |     devices.push_back(std::make_shared<DeviceM>("Pompa di calore + termostato", 4, -2.0));
      |                       ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/11/memory:77,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/Controller.h:6,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:7:
/usr/include/c++/11/bits/shared_ptr.h:875:5: note: candidate: ‘template<class _Tp, class ... _Args> std::shared_ptr<_Tp> std::make_shared(_Args&& ...)’
  875 |     make_shared(_Args&&... __args)
      |     ^~~~~~~~~~~
/usr/include/c++/11/bits/shared_ptr.h:875:5: note:   template argument deduction/substitution failed:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:138:49: error: no matching function for call to ‘make_shared<DeviceCP>(const char [22], int, double, int)’
  138 |     devices.push_back(std::make_shared<DeviceCP>("Tapparelle elettriche", 5, -0.3, 1));
      |                       ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/11/memory:77,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/Controller.h:6,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:7:
/usr/include/c++/11/bits/shared_ptr.h:875:5: note: candidate: ‘template<class _Tp, class ... _Args> std::shared_ptr<_Tp> std::make_shared(_Args&& ...)’
  875 |     make_shared(_Args&&... __args)
      |     ^~~~~~~~~~~
/usr/include/c++/11/bits/shared_ptr.h:875:5: note:   template argument deduction/substitution failed:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:139:48: error: no matching function for call to ‘make_shared<DeviceM>(const char [12], int, int)’
  139 |     devices.push_back(std::make_shared<DeviceM>("Scaldabagno", 6, -1));
      |                       ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/11/memory:77,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/Controller.h:6,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:7:
/usr/include/c++/11/bits/shared_ptr.h:875:5: note: candidate: ‘template<class _Tp, class ... _Args> std::shared_ptr<_Tp> std::make_shared(_Args&& ...)’
  875 |     make_shared(_Args&&... __args)
      |     ^~~~~~~~~~~
/usr/include/c++/11/bits/shared_ptr.h:875:5: note:   template argument deduction/substitution failed:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:140:48: error: no matching function for call to ‘make_shared<DeviceM>(const char [12], int, double)’
  140 |     devices.push_back(std::make_shared<DeviceM>("Frigorifero", 7, -0.4));
      |                       ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/11/memory:77,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/Controller.h:6,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:7:
/usr/include/c++/11/bits/shared_ptr.h:875:5: note: candidate: ‘template<class _Tp, class ... _Args> std::shared_ptr<_Tp> std::make_shared(_Args&& ...)’
  875 |     make_shared(_Args&&... __args)
      |     ^~~~~~~~~~~
/usr/include/c++/11/bits/shared_ptr.h:875:5: note:   template argument deduction/substitution failed:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:141:49: error: no matching function for call to ‘make_shared<DeviceCP>(const char [18], int, double, int)’
  141 |     devices.push_back(std::make_shared<DeviceCP>("Forno a microonde", 8, -0.8, 2));
      |                       ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/11/memory:77,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/Controller.h:6,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:7:
/usr/include/c++/11/bits/shared_ptr.h:875:5: note: candidate: ‘template<class _Tp, class ... _Args> std::shared_ptr<_Tp> std::make_shared(_Args&& ...)’
  875 |     make_shared(_Args&&... __args)
      |     ^~~~~~~~~~~
/usr/include/c++/11/bits/shared_ptr.h:875:5: note:   template argument deduction/substitution failed:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:142:49: error: no matching function for call to ‘make_shared<DeviceCP>(const char [13], int, double, int)’
  142 |     devices.push_back(std::make_shared<DeviceCP>("Asciugatrice", 9, -0.5, 60));
      |                       ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/11/memory:77,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/Controller.h:6,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:7:
/usr/include/c++/11/bits/shared_ptr.h:875:5: note: candidate: ‘template<class _Tp, class ... _Args> std::shared_ptr<_Tp> std::make_shared(_Args&& ...)’
  875 |     make_shared(_Args&&... __args)
      |     ^~~~~~~~~~~
/usr/include/c++/11/bits/shared_ptr.h:875:5: note:   template argument deduction/substitution failed:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:143:49: error: no matching function for call to ‘make_shared<DeviceCP>(const char [11], int, double, int)’
  143 |     devices.push_back(std::make_shared<DeviceCP>("Televisore", 10, -0.2, 60));
      |                       ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/11/memory:77,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/Controller.h:6,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:7:
/usr/include/c++/11/bits/shared_ptr.h:875:5: note: candidate: ‘template<class _Tp, class ... _Args> std::shared_ptr<_Tp> std::make_shared(_Args&& ...)’
  875 |     make_shared(_Args&&... __args)
      |     ^~~~~~~~~~~
/usr/include/c++/11/bits/shared_ptr.h:875:5: note:   template argument deduction/substitution failed:
make[2]: *** [CMakeFiles/sistemaDomotico.dir/build.make:76: CMakeFiles/sistemaDomotico.dir/src/main.cpp.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:83: CMakeFiles/sistemaDomotico.dir/all] Error 2
make: *** [Makefile:91: all] Error 2
