#-------------------------------------------------
#
# Project created by QtCreator 2021-06-01T11:32:39
#
#-------------------------------------------------

QT       += gui network widgets
DEFINES += QSSH_LIBRARY
TARGET = QSsh
TEMPLATE = lib

#------------------------------------
#--- QtCreator 3.2.1 SLE SSH CODE ---
#------------------------------------
include(ssh/ssh.pri)
include(./botan/botan.pri)
include(./tests/ssh.pri)


#------------------------------------

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    LICENSE.txt
