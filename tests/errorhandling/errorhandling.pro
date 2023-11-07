include(../ssh.pri)

TARGET=errorhandling
HEADERS = \
    test.h
SOURCES= \
    test.cpp \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/lib/release/ -lQSsh
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/lib/debug/ -lQSsh
else:unix: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -lQSsh

INCLUDEPATH += $$PWD/../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../usr/local/include
