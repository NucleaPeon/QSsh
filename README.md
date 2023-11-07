QSsh QtCreator SSH Library
==========================

QSsh is a component of QtCreator which allows users to run SSH commands.
Other developers have uploaded this code to Github, but I'd like to make
a few distinctions of what this repo is, compared to, say, https://github.com/lvklabs/QSsh.

* This library must be supported by and compatible with Mac OS X 10.6.8.
* No C++11 code.
* No Qt4 compatibility

This code is pulled from the base QtCreator 3.1.2 version.
It is compatible with Qt 5.3.2 which is what the Qt5 SLE fork is based upon.

Botan 1.10.2 is included in QSsh (and has its own CMakeLists.txt if you wish to install that library by itself).

Usage
-----

To build:

```sh
git clone https://github.com/NucleaPeon/QSsh.git
cd QSsh/build
cmake ..
make
```

To Install:

```sh
make install
```

To run tests (also in build/ directory):
```sh
make test
```

Currently only a Shared/Dynamic library is built.


Requirements
------------

* Qt 5.3.2 / Qt5 SLE (5.3.1 not tested but should work too)
* CMake (no longer supporting ``qmake``)
* Qt Core, Widget and Network modules
* OS X 10.6.8, Windows 7+ or modern Linux

_Windows XP should get support at a later date_


Current Status
--------------

[X] Library compiles using cmake on OS X 10.6.8.
[ ] Library compiles on Windows 7
[ ] Library compiles on Linux with Qt 5.15
[ ] Test stucture refactored and runable through ``ctest``
[ ] Actual inclusion and use within another project
[ ] Include instructions on building a static library
