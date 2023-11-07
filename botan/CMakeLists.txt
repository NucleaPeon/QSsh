##
 # Botan 1.10.2 Amalgamation
 # (C) 1999-2011 Jack Lloyd and others
 #
 # Distributed under the terms of the Botan license
##

cmake_minimum_required(VERSION 3.3)
project(botan
        VERSION 1.10.2
        LANGUAGES CXX
        DESCRIPTION "Cryptographic and TLS library written in C++, originally called OpenCL")

find_package(Qt5 REQUIRED
    Core
)
include(GNUInstallDirs)  # REQUIRED TO INSTALL PKGCONFIG TO PROPER DIR!

set(CMAKE_CXX_STANDARD_COMPUTED_DEFAULT "98")

list(APPEND BOTAN_HEADERS
	botan.h
)
list(APPEND BOTAN_SOURCES
	botan.cpp
)

add_compile_options(-fpermissive -finline-functions -Wno-long-long)
# if windows and msvc
# QMAKE_CXXFLAGS_EXCEPTIONS_ON = -EHs
# QMAKE_CXXFLAGS += -wd4251 -wd4290 -wd4250
if (NOT WIN32 AND NOT MSVC)
	# All unix/mac/linux compilers should use this
	add_compile_options(-fPIC -ansi)
endif()

add_library(botan SHARED
	${BOTAN_HEADERS}
	${BOTAN_SOURCES}
)
set_target_properties(botan PROPERTIES VERSION ${PROJECT_VERSION}
	SOVERSION 1
)

set_target_properties(botan PROPERTIES PUBLIC_HEADER "${BOTAN_HEADERS}")
configure_file(botan.pc.in botan.pc @ONLY)

target_link_libraries(botan Qt5::Core)

install(TARGETS botan
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_BINARY_DIR}/botan.pc DESTINATION
	${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
