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

SOURCES = $$PWD/ssh/sshsendfacility.cpp \
    $$PWD/ssh/sshremoteprocess.cpp \
    $$PWD/ssh/sshpacketparser.cpp \
    $$PWD/ssh/sshpacket.cpp \
    $$PWD/ssh/sshoutgoingpacket.cpp \
    $$PWD/ssh/sshkeygenerator.cpp \
    $$PWD/ssh/sshkeyexchange.cpp \
    $$PWD/ssh/sshincomingpacket.cpp \
    $$PWD/ssh/sshcryptofacility.cpp \
    $$PWD/ssh/sshconnection.cpp \
    $$PWD/ssh/sshchannelmanager.cpp \
    $$PWD/ssh/sshchannel.cpp \
    $$PWD/ssh/sshcapabilities.cpp \
    $$PWD/ssh/sftppacket.cpp \
    $$PWD/ssh/sftpoutgoingpacket.cpp \
    $$PWD/ssh/sftpoperation.cpp \
    $$PWD/ssh/sftpincomingpacket.cpp \
    $$PWD/ssh/sftpdefs.cpp \
    $$PWD/ssh/sftpchannel.cpp \
    $$PWD/ssh/sshremoteprocessrunner.cpp \
    $$PWD/ssh/sshconnectionmanager.cpp \
    $$PWD/ssh/sshkeypasswordretriever.cpp \
    $$PWD/ssh/sftpfilesystemmodel.cpp \
    $$PWD/ssh/sshkeycreationdialog.cpp \
    $$PWD/ssh/sshinit.cpp \
    $$PWD/ssh/sshdirecttcpiptunnel.cpp

HEADERS = $$PWD/ssh/sshsendfacility_p.h \
    $$PWD/ssh/sshremoteprocess.h \
    $$PWD/ssh/sshremoteprocess_p.h \
    $$PWD/ssh/sshpacketparser_p.h \
    $$PWD/ssh/sshpacket_p.h \
    $$PWD/ssh/sshoutgoingpacket_p.h \
    $$PWD/ssh/sshkeygenerator.h \
    $$PWD/ssh/sshkeyexchange_p.h \
    $$PWD/ssh/sshincomingpacket_p.h \
    $$PWD/ssh/sshexception_p.h \
    $$PWD/ssh/ssherrors.h \
    $$PWD/ssh/sshcryptofacility_p.h \
    $$PWD/ssh/sshconnection.h \
    $$PWD/ssh/sshconnection_p.h \
    $$PWD/ssh/sshchannelmanager_p.h \
    $$PWD/ssh/sshchannel_p.h \
    $$PWD/ssh/sshcapabilities_p.h \
    $$PWD/ssh/sshbotanconversions_p.h \
    $$PWD/ssh/sftppacket_p.h \
    $$PWD/ssh/sftpoutgoingpacket_p.h \
    $$PWD/ssh/sftpoperation_p.h \
    $$PWD/ssh/sftpincomingpacket_p.h \
    $$PWD/ssh/sftpdefs.h \
    $$PWD/ssh/sftpchannel.h \
    $$PWD/ssh/sftpchannel_p.h \
    $$PWD/ssh/sshremoteprocessrunner.h \
    $$PWD/ssh/sshconnectionmanager.h \
    $$PWD/ssh/sshpseudoterminal.h \
    $$PWD/ssh/sshkeypasswordretriever_p.h \
    $$PWD/ssh/sftpfilesystemmodel.h \
    $$PWD/ssh/sshkeycreationdialog.h \
    $$PWD/ssh/ssh_global.h \
    $$PWD/ssh/sshdirecttcpiptunnel_p.h \
    $$PWD/ssh/sshinit_p.h \
    $$PWD/ssh/sshdirecttcpiptunnel.h

FORMS = $$PWD/ssh/sshkeycreationdialog.ui

include(./botan/botan.pri)


#------------------------------------

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    LICENSE.txt
