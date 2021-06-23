QSsh QtCreator SSH Library
==========================

QSsh is a component of QtCreator which allows users to run SSH commands.
Other developers have uploaded this code to Github, but I'd like to make
a few distinctions of what this repo is, compared to, say, https://github.com/lvklabs/QSsh.

* No Qt4 support. Certain Qt4 compatibility macros and code have been replaced.
* This project builds a dynamic library for inclusion into other projects
* While tests are included, they don't function yet. I plan to put them in another repo and create packages for multiple OS's for deployment.
* I will be using this library in my other projects. I will take issues and feature requests, but please read the Requirements section below.


Requirements
------------

This code is pulled from QtCreator 3.1.2, or SLE 3.1.4 as it is currently known.

* This library must be supported by and compatible with Mac OS X 10.6.8.
* No C++11 code.
* No Qt4 compatibility


Current Status
--------------

> The project compiles successfully (on my machine). <


Installation
------------

If you are going to include it in your project, you must copy or referencethe dylib/DLL/so file(s) and the header files.

Once a release package is generated, expect more concise instructions.
Once Test repo is built, exact code can be copied or referenced.
