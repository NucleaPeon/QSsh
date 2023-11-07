cmake_minimum_required(VERSION 3.3)
project(QSsh
        VERSION 0.1.0
        LANGUAGES CXX
        DESCRIPTION "Qt5 SSH Library from Qt5.3.2 codebase")

find_package(Qt5 REQUIRED
	Core
    Widgets
    Network
    Test
)

if(APPLE)
	# g++-4.2 on Snow Leopard doesn't allow for inline variable definitions whereas
	# clang 3 does. If on Apple, you need to use clang for this to compile correctly.
	set(CMAKE_C_COMPILER clang)
	set(CMAKE_CXX_COMPILER clang++)
endif()
include_directories(BEFORE SYSTEM ${PROJECT_SOURCE_DIR})

#LEFT OFF: Change names to ${PROJECT_NAME} and add in source/headers/etc
# UI is included
# qssh.pc.in file
# ensure it builds and installs and can be imported.

set(CMAKE_CXX_STANDARD_COMPUTED_DEFAULT "98")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(APPEND QSSH_HEADERS_PRIVATE
	ssh/sshsendfacility_p.h
    ssh/sshremoteprocess_p.h
    ssh/sshpacketparser_p.h
    ssh/sshpacket_p.h
    ssh/sshoutgoingpacket_p.h
    ssh/sshkeyexchange_p.h
    ssh/sshincomingpacket_p.h
    ssh/sshexception_p.h
    ssh/sshcryptofacility_p.h
    ssh/sshconnection_p.h
    ssh/sshchannelmanager_p.h
    ssh/sshchannel_p.h
    ssh/sshcapabilities_p.h
    ssh/sshbotanconversions_p.h
    ssh/sftppacket_p.h
    ssh/sftpoutgoingpacket_p.h
    ssh/sftpoperation_p.h
    ssh/sftpincomingpacket_p.h
    ssh/sftpchannel_p.h
    ssh/sshkeypasswordretriever_p.h
    ssh/sshdirecttcpiptunnel_p.h
    ssh/sshinit_p.h
)

list(APPEND QSSH_HEADERS
    ssh/sshremoteprocess.h
    ssh/sshkeygenerator.h
    ssh/ssherrors.h
    ssh/sshconnectionmanager.h
    ssh/sshconnection.h
    ssh/sftpdefs.h
    ssh/sftpchannel.h
    ssh/sshremoteprocessrunner.h

    ssh/sshpseudoterminal.h
    ssh/sftpfilesystemmodel.h
    ssh/sshkeycreationdialog.h
    ssh/ssh_global.h
    ssh/sshdirecttcpiptunnel.h
)

list(APPEND QSSH_SOURCES
	ssh/sshsendfacility.cpp
    ssh/sshremoteprocess.cpp
    ssh/sshpacketparser.cpp
    ssh/sshpacket.cpp
    ssh/sshoutgoingpacket.cpp
    ssh/sshkeygenerator.cpp
    ssh/sshkeyexchange.cpp
    ssh/sshincomingpacket.cpp
    ssh/sshcryptofacility.cpp
    ssh/sshconnection.cpp
    ssh/sshchannelmanager.cpp
    ssh/sshchannel.cpp
    ssh/sshcapabilities.cpp
    ssh/sftppacket.cpp
    ssh/sftpoutgoingpacket.cpp
    ssh/sftpoperation.cpp
    ssh/sftpincomingpacket.cpp
    ssh/sftpdefs.cpp
    ssh/sftpchannel.cpp
    ssh/sshremoteprocessrunner.cpp
    ssh/sshconnectionmanager.cpp
    ssh/sshkeypasswordretriever.cpp
    ssh/sftpfilesystemmodel.cpp
    ssh/sshkeycreationdialog.cpp
    ssh/sshinit.cpp
    ssh/sshdirecttcpiptunnel.cpp
)

list(APPEND QSSH_UI
	ssh/sshkeycreationdialog.ui
)

list(APPEND QSSH_RES

)

add_library(${PROJECT_NAME} SHARED
	${QSSH_HEADERS_PRIVATE}
	${QSSH_HEADERS}
	${QSSH_SOURCES}
	${QSSH_UI}
	${QSSH_RES}
)

target_link_libraries(${PROJECT_NAME} botan Qt5::Core Qt5::Widgets Qt5::Network)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION}
	SOVERSION 1
)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${QSSH_HEADERS})

configure_file(QSsh.pc.in QSsh.pc @ONLY)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_BINARY_DIR}/QSsh.pc DESTINATION
	"${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig")


# ############# TESTING ############# #

enable_testing()

add_executable(sanity tests/sanity/main.cpp)
target_link_libraries(sanity botan Qt5::Core Qt5::Widgets Qt5::Network Qt5::Test QSsh)

# Enable verbose mode
add_compile_options(-v)

add_executable(shell
	tests/remoteprocess/argumentscollector.h
	tests/remoteprocess/argumentscollector.cpp
	tests/shell/main.cpp
	tests/shell/shell.h
	tests/shell/shell.cpp)

target_link_libraries(shell botan Qt5::Core Qt5::Widgets Qt5::Network Qt5::Test QSsh)

add_test(sanity sanity)

