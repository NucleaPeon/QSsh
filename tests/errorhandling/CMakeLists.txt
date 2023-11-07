cmake_minimum_required(VERSION 3.3)
project(QSsh-Tests-errorhandling
        VERSION 0.1.0
        LANGUAGES CXX
)

if(APPLE)
	# g++-4.2 on Snow Leopard doesn't allow for inline variable definitions whereas
	# clang 3 does. If on Apple, you need to use clang for this to compile correctly.
	set(CMAKE_C_COMPILER clang)
	set(CMAKE_CXX_COMPILER clang++)
endif()

#LEFT OFF: Change names to ${PROJECT_NAME} and add in source/headers/etc
# UI is included
# qssh.pc.in file
# ensure it builds and installs and can be imported.

set(CMAKE_CXX_STANDARD_COMPUTED_DEFAULT "98")

include_directories("../../")
set(CMAKE_AUTOMOC ON)
find_package(Qt5 REQUIRED
    Widgets
    Network
    Test
)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Test Qt5::Network)
