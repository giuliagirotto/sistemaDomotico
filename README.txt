#eventuali problemi

ed_ptr<_Tp, _Lp>::__shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[14], int, double, int}; _Tp = DeviceCP; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr.h:409:59:   required from ‘std::shared_ptr<_Tp>::shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[14], int, double, int}; _Tp = DeviceCP]’
/usr/include/c++/11/bits/shared_ptr.h:862:14:   required from ‘std::shared_ptr<_Tp> std::allocate_shared(const _Alloc&, _Args&& ...) [with _Tp = DeviceCP; _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[14], int, double, int}]’
/usr/include/c++/11/bits/shared_ptr.h:878:39:   required from ‘std::shared_ptr<_Tp> std::make_shared(_Args&& ...) [with _Tp = DeviceCP; _Args = {const char (&)[14], int, double, int}]’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:139:49:   required from here
/usr/include/c++/11/ext/new_allocator.h:162:11: error: no matching function for call to ‘DeviceCP::DeviceCP(const char [14], int, double, int)’
  162 |         { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:9:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:13:5: note: candidate: ‘DeviceCP::DeviceCP(const string&, int, double, int, Controller&)’
   13 |     DeviceCP(const std::string& name, int id, double power, int duration, Controller& controller);
      |     ^~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:13:5: note:   candidate expects 5 arguments, 4 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note: candidate: ‘DeviceCP::DeviceCP(const DeviceCP&)’
    6 | class DeviceCP : public Device {
      |       ^~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note:   candidate expects 1 argument, 4 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note: candidate: ‘DeviceCP::DeviceCP(DeviceCP&&)’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note:   candidate expects 1 argument, 4 provided
In file included from /usr/include/x86_64-linux-gnu/c++/11/bits/c++allocator.h:33,
                 from /usr/include/c++/11/bits/allocator.h:46,
                 from /usr/include/c++/11/string:41,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:2:
/usr/include/c++/11/ext/new_allocator.h: In instantiation of ‘void __gnu_cxx::new_allocator<_Tp>::construct(_Up*, _Args&& ...) [with _Up = DeviceM; _Args = {const char (&)[29], int, double}; _Tp = DeviceM]’:
/usr/include/c++/11/bits/alloc_traits.h:516:17:   required from ‘static void std::allocator_traits<std::allocator<_CharT> >::construct(std::allocator_traits<std::allocator<_CharT> >::allocator_type&, _Up*, _Args&& ...) [with _Up = DeviceM; _Args = {const char (&)[29], int, double}; _Tp = DeviceM; std::allocator_traits<std::allocator<_CharT> >::allocator_type = std::allocator<DeviceM>]’
/usr/include/c++/11/bits/shared_ptr_base.h:519:39:   required from ‘std::_Sp_counted_ptr_inplace<_Tp, _Alloc, _Lp>::_Sp_counted_ptr_inplace(_Alloc, _Args&& ...) [with _Args = {const char (&)[29], int, double}; _Tp = DeviceM; _Alloc = std::allocator<DeviceM>; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:650:16:   required from ‘std::__shared_count<_Lp>::__shared_count(_Tp*&, std::_Sp_alloc_shared_tag<_Alloc>, _Args&& ...) [with _Tp = DeviceM; _Alloc = std::allocator<DeviceM>; _Args = {const char (&)[29], int, double}; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:1342:14:   required from ‘std::__shared_ptr<_Tp, _Lp>::__shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceM>; _Args = {const char (&)[29], int, double}; _Tp = DeviceM; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr.h:409:59:   required from ‘std::shared_ptr<_Tp>::shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceM>; _Args = {const char (&)[29], int, double}; _Tp = DeviceM]’
/usr/include/c++/11/bits/shared_ptr.h:862:14:   required from ‘std::shared_ptr<_Tp> std::allocate_shared(const _Alloc&, _Args&& ...) [with _Tp = DeviceM; _Alloc = std::allocator<DeviceM>; _Args = {const char (&)[29], int, double}]’
/usr/include/c++/11/bits/shared_ptr.h:878:39:   required from ‘std::shared_ptr<_Tp> std::make_shared(_Args&& ...) [with _Tp = DeviceM; _Args = {const char (&)[29], int, double}]’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:140:48:   required from here
/usr/include/c++/11/ext/new_allocator.h:162:11: error: no matching function for call to ‘DeviceM::DeviceM(const char [29], int, double)’
  162 |         { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:10:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:12:5: note: candidate: ‘DeviceM::DeviceM(const string&, int, double, Controller&)’
   12 |     DeviceM(const std::string& name, int id, double power, Controller& controller);
      |     ^~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:12:5: note:   candidate expects 4 arguments, 3 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:6:7: note: candidate: ‘DeviceM::DeviceM(const DeviceM&)’
    6 | class DeviceM : public Device {
      |       ^~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:6:7: note:   candidate expects 1 argument, 3 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:6:7: note: candidate: ‘DeviceM::DeviceM(DeviceM&&)’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:6:7: note:   candidate expects 1 argument, 3 provided
In file included from /usr/include/x86_64-linux-gnu/c++/11/bits/c++allocator.h:33,
                 from /usr/include/c++/11/bits/allocator.h:46,
                 from /usr/include/c++/11/string:41,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:2:
/usr/include/c++/11/ext/new_allocator.h: In instantiation of ‘void __gnu_cxx::new_allocator<_Tp>::construct(_Up*, _Args&& ...) [with _Up = DeviceCP; _Args = {const char (&)[22], int, double, int}; _Tp = DeviceCP]’:
/usr/include/c++/11/bits/alloc_traits.h:516:17:   required from ‘static void std::allocator_traits<std::allocator<_CharT> >::construct(std::allocator_traits<std::allocator<_CharT> >::allocator_type&, _Up*, _Args&& ...) [with _Up = DeviceCP; _Args = {const char (&)[22], int, double, int}; _Tp = DeviceCP; std::allocator_traits<std::allocator<_CharT> >::allocator_type = std::allocator<DeviceCP>]’
/usr/include/c++/11/bits/shared_ptr_base.h:519:39:   required from ‘std::_Sp_counted_ptr_inplace<_Tp, _Alloc, _Lp>::_Sp_counted_ptr_inplace(_Alloc, _Args&& ...) [with _Args = {const char (&)[22], int, double, int}; _Tp = DeviceCP; _Alloc = std::allocator<DeviceCP>; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:650:16:   required from ‘std::__shared_count<_Lp>::__shared_count(_Tp*&, std::_Sp_alloc_shared_tag<_Alloc>, _Args&& ...) [with _Tp = DeviceCP; _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[22], int, double, int}; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:1342:14:   required from ‘std::__shared_ptr<_Tp, _Lp>::__shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[22], int, double, int}; _Tp = DeviceCP; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr.h:409:59:   required from ‘std::shared_ptr<_Tp>::shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[22], int, double, int}; _Tp = DeviceCP]’
/usr/include/c++/11/bits/shared_ptr.h:862:14:   required from ‘std::shared_ptr<_Tp> std::allocate_shared(const _Alloc&, _Args&& ...) [with _Tp = DeviceCP; _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[22], int, double, int}]’
/usr/include/c++/11/bits/shared_ptr.h:878:39:   required from ‘std::shared_ptr<_Tp> std::make_shared(_Args&& ...) [with _Tp = DeviceCP; _Args = {const char (&)[22], int, double, int}]’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:141:49:   required from here
/usr/include/c++/11/ext/new_allocator.h:162:11: error: no matching function for call to ‘DeviceCP::DeviceCP(const char [22], int, double, int)’
  162 |         { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:9:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:13:5: note: candidate: ‘DeviceCP::DeviceCP(const string&, int, double, int, Controller&)’
   13 |     DeviceCP(const std::string& name, int id, double power, int duration, Controller& controller);
      |     ^~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:13:5: note:   candidate expects 5 arguments, 4 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note: candidate: ‘DeviceCP::DeviceCP(const DeviceCP&)’
    6 | class DeviceCP : public Device {
      |       ^~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note:   candidate expects 1 argument, 4 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note: candidate: ‘DeviceCP::DeviceCP(DeviceCP&&)’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note:   candidate expects 1 argument, 4 provided
In file included from /usr/include/x86_64-linux-gnu/c++/11/bits/c++allocator.h:33,
                 from /usr/include/c++/11/bits/allocator.h:46,
                 from /usr/include/c++/11/string:41,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:2:
/usr/include/c++/11/ext/new_allocator.h: In instantiation of ‘void __gnu_cxx::new_allocator<_Tp>::construct(_Up*, _Args&& ...) [with _Up = DeviceM; _Args = {const char (&)[12], int, int}; _Tp = DeviceM]’:
/usr/include/c++/11/bits/alloc_traits.h:516:17:   required from ‘static void std::allocator_traits<std::allocator<_CharT> >::construct(std::allocator_traits<std::allocator<_CharT> >::allocator_type&, _Up*, _Args&& ...) [with _Up = DeviceM; _Args = {const char (&)[12], int, int}; _Tp = DeviceM; std::allocator_traits<std::allocator<_CharT> >::allocator_type = std::allocator<DeviceM>]’
/usr/include/c++/11/bits/shared_ptr_base.h:519:39:   required from ‘std::_Sp_counted_ptr_inplace<_Tp, _Alloc, _Lp>::_Sp_counted_ptr_inplace(_Alloc, _Args&& ...) [with _Args = {const char (&)[12], int, int}; _Tp = DeviceM; _Alloc = std::allocator<DeviceM>; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:650:16:   required from ‘std::__shared_count<_Lp>::__shared_count(_Tp*&, std::_Sp_alloc_shared_tag<_Alloc>, _Args&& ...) [with _Tp = DeviceM; _Alloc = std::allocator<DeviceM>; _Args = {const char (&)[12], int, int}; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:1342:14:   required from ‘std::__shared_ptr<_Tp, _Lp>::__shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceM>; _Args = {const char (&)[12], int, int}; _Tp = DeviceM; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr.h:409:59:   required from ‘std::shared_ptr<_Tp>::shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceM>; _Args = {const char (&)[12], int, int}; _Tp = DeviceM]’
/usr/include/c++/11/bits/shared_ptr.h:862:14:   required from ‘std::shared_ptr<_Tp> std::allocate_shared(const _Alloc&, _Args&& ...) [with _Tp = DeviceM; _Alloc = std::allocator<DeviceM>; _Args = {const char (&)[12], int, int}]’
/usr/include/c++/11/bits/shared_ptr.h:878:39:   required from ‘std::shared_ptr<_Tp> std::make_shared(_Args&& ...) [with _Tp = DeviceM; _Args = {const char (&)[12], int, int}]’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:142:48:   required from here
/usr/include/c++/11/ext/new_allocator.h:162:11: error: no matching function for call to ‘DeviceM::DeviceM(const char [12], int, int)’
  162 |         { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:10:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:12:5: note: candidate: ‘DeviceM::DeviceM(const string&, int, double, Controller&)’
   12 |     DeviceM(const std::string& name, int id, double power, Controller& controller);
      |     ^~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:12:5: note:   candidate expects 4 arguments, 3 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:6:7: note: candidate: ‘DeviceM::DeviceM(const DeviceM&)’
    6 | class DeviceM : public Device {
      |       ^~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:6:7: note:   candidate expects 1 argument, 3 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:6:7: note: candidate: ‘DeviceM::DeviceM(DeviceM&&)’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:6:7: note:   candidate expects 1 argument, 3 provided
In file included from /usr/include/x86_64-linux-gnu/c++/11/bits/c++allocator.h:33,
                 from /usr/include/c++/11/bits/allocator.h:46,
                 from /usr/include/c++/11/string:41,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:2:
/usr/include/c++/11/ext/new_allocator.h: In instantiation of ‘void __gnu_cxx::new_allocator<_Tp>::construct(_Up*, _Args&& ...) [with _Up = DeviceM; _Args = {const char (&)[12], int, double}; _Tp = DeviceM]’:
/usr/include/c++/11/bits/alloc_traits.h:516:17:   required from ‘static void std::allocator_traits<std::allocator<_CharT> >::construct(std::allocator_traits<std::allocator<_CharT> >::allocator_type&, _Up*, _Args&& ...) [with _Up = DeviceM; _Args = {const char (&)[12], int, double}; _Tp = DeviceM; std::allocator_traits<std::allocator<_CharT> >::allocator_type = std::allocator<DeviceM>]’
/usr/include/c++/11/bits/shared_ptr_base.h:519:39:   required from ‘std::_Sp_counted_ptr_inplace<_Tp, _Alloc, _Lp>::_Sp_counted_ptr_inplace(_Alloc, _Args&& ...) [with _Args = {const char (&)[12], int, double}; _Tp = DeviceM; _Alloc = std::allocator<DeviceM>; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:650:16:   required from ‘std::__shared_count<_Lp>::__shared_count(_Tp*&, std::_Sp_alloc_shared_tag<_Alloc>, _Args&& ...) [with _Tp = DeviceM; _Alloc = std::allocator<DeviceM>; _Args = {const char (&)[12], int, double}; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:1342:14:   required from ‘std::__shared_ptr<_Tp, _Lp>::__shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceM>; _Args = {const char (&)[12], int, double}; _Tp = DeviceM; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr.h:409:59:   required from ‘std::shared_ptr<_Tp>::shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceM>; _Args = {const char (&)[12], int, double}; _Tp = DeviceM]’
/usr/include/c++/11/bits/shared_ptr.h:862:14:   required from ‘std::shared_ptr<_Tp> std::allocate_shared(const _Alloc&, _Args&& ...) [with _Tp = DeviceM; _Alloc = std::allocator<DeviceM>; _Args = {const char (&)[12], int, double}]’
/usr/include/c++/11/bits/shared_ptr.h:878:39:   required from ‘std::shared_ptr<_Tp> std::make_shared(_Args&& ...) [with _Tp = DeviceM; _Args = {const char (&)[12], int, double}]’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:143:48:   required from here
/usr/include/c++/11/ext/new_allocator.h:162:11: error: no matching function for call to ‘DeviceM::DeviceM(const char [12], int, double)’
  162 |         { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:10:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:12:5: note: candidate: ‘DeviceM::DeviceM(const string&, int, double, Controller&)’
   12 |     DeviceM(const std::string& name, int id, double power, Controller& controller);
      |     ^~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:12:5: note:   candidate expects 4 arguments, 3 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:6:7: note: candidate: ‘DeviceM::DeviceM(const DeviceM&)’
    6 | class DeviceM : public Device {
      |       ^~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:6:7: note:   candidate expects 1 argument, 3 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:6:7: note: candidate: ‘DeviceM::DeviceM(DeviceM&&)’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceM.h:6:7: note:   candidate expects 1 argument, 3 provided
In file included from /usr/include/x86_64-linux-gnu/c++/11/bits/c++allocator.h:33,
                 from /usr/include/c++/11/bits/allocator.h:46,
                 from /usr/include/c++/11/string:41,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:2:
/usr/include/c++/11/ext/new_allocator.h: In instantiation of ‘void __gnu_cxx::new_allocator<_Tp>::construct(_Up*, _Args&& ...) [with _Up = DeviceCP; _Args = {const char (&)[18], int, double, int}; _Tp = DeviceCP]’:
/usr/include/c++/11/bits/alloc_traits.h:516:17:   required from ‘static void std::allocator_traits<std::allocator<_CharT> >::construct(std::allocator_traits<std::allocator<_CharT> >::allocator_type&, _Up*, _Args&& ...) [with _Up = DeviceCP; _Args = {const char (&)[18], int, double, int}; _Tp = DeviceCP; std::allocator_traits<std::allocator<_CharT> >::allocator_type = std::allocator<DeviceCP>]’
/usr/include/c++/11/bits/shared_ptr_base.h:519:39:   required from ‘std::_Sp_counted_ptr_inplace<_Tp, _Alloc, _Lp>::_Sp_counted_ptr_inplace(_Alloc, _Args&& ...) [with _Args = {const char (&)[18], int, double, int}; _Tp = DeviceCP; _Alloc = std::allocator<DeviceCP>; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:650:16:   required from ‘std::__shared_count<_Lp>::__shared_count(_Tp*&, std::_Sp_alloc_shared_tag<_Alloc>, _Args&& ...) [with _Tp = DeviceCP; _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[18], int, double, int}; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:1342:14:   required from ‘std::__shared_ptr<_Tp, _Lp>::__shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[18], int, double, int}; _Tp = DeviceCP; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr.h:409:59:   required from ‘std::shared_ptr<_Tp>::shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[18], int, double, int}; _Tp = DeviceCP]’
/usr/include/c++/11/bits/shared_ptr.h:862:14:   required from ‘std::shared_ptr<_Tp> std::allocate_shared(const _Alloc&, _Args&& ...) [with _Tp = DeviceCP; _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[18], int, double, int}]’
/usr/include/c++/11/bits/shared_ptr.h:878:39:   required from ‘std::shared_ptr<_Tp> std::make_shared(_Args&& ...) [with _Tp = DeviceCP; _Args = {const char (&)[18], int, double, int}]’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:144:49:   required from here
/usr/include/c++/11/ext/new_allocator.h:162:11: error: no matching function for call to ‘DeviceCP::DeviceCP(const char [18], int, double, int)’
  162 |         { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:9:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:13:5: note: candidate: ‘DeviceCP::DeviceCP(const string&, int, double, int, Controller&)’
   13 |     DeviceCP(const std::string& name, int id, double power, int duration, Controller& controller);
      |     ^~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:13:5: note:   candidate expects 5 arguments, 4 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note: candidate: ‘DeviceCP::DeviceCP(const DeviceCP&)’
    6 | class DeviceCP : public Device {
      |       ^~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note:   candidate expects 1 argument, 4 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note: candidate: ‘DeviceCP::DeviceCP(DeviceCP&&)’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note:   candidate expects 1 argument, 4 provided
In file included from /usr/include/x86_64-linux-gnu/c++/11/bits/c++allocator.h:33,
                 from /usr/include/c++/11/bits/allocator.h:46,
                 from /usr/include/c++/11/string:41,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:2:
/usr/include/c++/11/ext/new_allocator.h: In instantiation of ‘void __gnu_cxx::new_allocator<_Tp>::construct(_Up*, _Args&& ...) [with _Up = DeviceCP; _Args = {const char (&)[13], int, double, int}; _Tp = DeviceCP]’:
/usr/include/c++/11/bits/alloc_traits.h:516:17:   required from ‘static void std::allocator_traits<std::allocator<_CharT> >::construct(std::allocator_traits<std::allocator<_CharT> >::allocator_type&, _Up*, _Args&& ...) [with _Up = DeviceCP; _Args = {const char (&)[13], int, double, int}; _Tp = DeviceCP; std::allocator_traits<std::allocator<_CharT> >::allocator_type = std::allocator<DeviceCP>]’
/usr/include/c++/11/bits/shared_ptr_base.h:519:39:   required from ‘std::_Sp_counted_ptr_inplace<_Tp, _Alloc, _Lp>::_Sp_counted_ptr_inplace(_Alloc, _Args&& ...) [with _Args = {const char (&)[13], int, double, int}; _Tp = DeviceCP; _Alloc = std::allocator<DeviceCP>; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:650:16:   required from ‘std::__shared_count<_Lp>::__shared_count(_Tp*&, std::_Sp_alloc_shared_tag<_Alloc>, _Args&& ...) [with _Tp = DeviceCP; _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[13], int, double, int}; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:1342:14:   required from ‘std::__shared_ptr<_Tp, _Lp>::__shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[13], int, double, int}; _Tp = DeviceCP; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr.h:409:59:   required from ‘std::shared_ptr<_Tp>::shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[13], int, double, int}; _Tp = DeviceCP]’
/usr/include/c++/11/bits/shared_ptr.h:862:14:   required from ‘std::shared_ptr<_Tp> std::allocate_shared(const _Alloc&, _Args&& ...) [with _Tp = DeviceCP; _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[13], int, double, int}]’
/usr/include/c++/11/bits/shared_ptr.h:878:39:   required from ‘std::shared_ptr<_Tp> std::make_shared(_Args&& ...) [with _Tp = DeviceCP; _Args = {const char (&)[13], int, double, int}]’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:145:49:   required from here
/usr/include/c++/11/ext/new_allocator.h:162:11: error: no matching function for call to ‘DeviceCP::DeviceCP(const char [13], int, double, int)’
  162 |         { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:9:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:13:5: note: candidate: ‘DeviceCP::DeviceCP(const string&, int, double, int, Controller&)’
   13 |     DeviceCP(const std::string& name, int id, double power, int duration, Controller& controller);
      |     ^~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:13:5: note:   candidate expects 5 arguments, 4 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note: candidate: ‘DeviceCP::DeviceCP(const DeviceCP&)’
    6 | class DeviceCP : public Device {
      |       ^~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note:   candidate expects 1 argument, 4 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note: candidate: ‘DeviceCP::DeviceCP(DeviceCP&&)’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note:   candidate expects 1 argument, 4 provided
In file included from /usr/include/x86_64-linux-gnu/c++/11/bits/c++allocator.h:33,
                 from /usr/include/c++/11/bits/allocator.h:46,
                 from /usr/include/c++/11/string:41,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:2:
/usr/include/c++/11/ext/new_allocator.h: In instantiation of ‘void __gnu_cxx::new_allocator<_Tp>::construct(_Up*, _Args&& ...) [with _Up = DeviceCP; _Args = {const char (&)[11], int, double, int}; _Tp = DeviceCP]’:
/usr/include/c++/11/bits/alloc_traits.h:516:17:   required from ‘static void std::allocator_traits<std::allocator<_CharT> >::construct(std::allocator_traits<std::allocator<_CharT> >::allocator_type&, _Up*, _Args&& ...) [with _Up = DeviceCP; _Args = {const char (&)[11], int, double, int}; _Tp = DeviceCP; std::allocator_traits<std::allocator<_CharT> >::allocator_type = std::allocator<DeviceCP>]’
/usr/include/c++/11/bits/shared_ptr_base.h:519:39:   required from ‘std::_Sp_counted_ptr_inplace<_Tp, _Alloc, _Lp>::_Sp_counted_ptr_inplace(_Alloc, _Args&& ...) [with _Args = {const char (&)[11], int, double, int}; _Tp = DeviceCP; _Alloc = std::allocator<DeviceCP>; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:650:16:   required from ‘std::__shared_count<_Lp>::__shared_count(_Tp*&, std::_Sp_alloc_shared_tag<_Alloc>, _Args&& ...) [with _Tp = DeviceCP; _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[11], int, double, int}; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr_base.h:1342:14:   required from ‘std::__shared_ptr<_Tp, _Lp>::__shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[11], int, double, int}; _Tp = DeviceCP; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/11/bits/shared_ptr.h:409:59:   required from ‘std::shared_ptr<_Tp>::shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[11], int, double, int}; _Tp = DeviceCP]’
/usr/include/c++/11/bits/shared_ptr.h:862:14:   required from ‘std::shared_ptr<_Tp> std::allocate_shared(const _Alloc&, _Args&& ...) [with _Tp = DeviceCP; _Alloc = std::allocator<DeviceCP>; _Args = {const char (&)[11], int, double, int}]’
/usr/include/c++/11/bits/shared_ptr.h:878:39:   required from ‘std::shared_ptr<_Tp> std::make_shared(_Args&& ...) [with _Tp = DeviceCP; _Args = {const char (&)[11], int, double, int}]’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:146:49:   required from here
/usr/include/c++/11/ext/new_allocator.h:162:11: error: no matching function for call to ‘DeviceCP::DeviceCP(const char [11], int, double, int)’
  162 |         { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /home/local/girogiu95354/sistemaDomotico/sistemaDomotico/src/main.cpp:9:
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:13:5: note: candidate: ‘DeviceCP::DeviceCP(const string&, int, double, int, Controller&)’
   13 |     DeviceCP(const std::string& name, int id, double power, int duration, Controller& controller);
      |     ^~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:13:5: note:   candidate expects 5 arguments, 4 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note: candidate: ‘DeviceCP::DeviceCP(const DeviceCP&)’
    6 | class DeviceCP : public Device {
      |       ^~~~~~~~
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note:   candidate expects 1 argument, 4 provided
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note: candidate: ‘DeviceCP::DeviceCP(DeviceCP&&)’
/home/local/girogiu95354/sistemaDomotico/sistemaDomotico/Include/DeviceCP.h:6:7: note:   candidate expects 1 argument, 4 provided
make[2]: *** [CMakeFiles/sistemaDomotico.dir/build.make:76: CMakeFiles/sistemaDomotico.dir/src/main.cpp.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:83: CMakeFiles/sistemaDomotico.dir/all] Error 2
make: *** [Makefile:91: all] Error 2
AD\girogiu95354@DEI-LAB-PR2-013:~/sistemaDomotico/sistemaDomotico/build$ 

