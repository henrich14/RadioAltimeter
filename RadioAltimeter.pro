#-------------------------------------------------
#
# Project created by QtCreator 2013-09-17T15:02:54
#
#-------------------------------------------------

QT       += core gui
CONFIG += qwt

TARGET = RadioAltimeter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    phase.cpp \
    twochannelaltimeter.cpp \
    impuls.cpp \
    doppler.cpp

HEADERS  += mainwindow.h \
    phase.h \
    twochannelaltimeter.h \
    impuls.h \
    doppler.h

FORMS    += mainwindow.ui \
    phase.ui \
    twochannelaltimeter.ui \
    impuls.ui \
    doppler.ui


INCLUDEPATH += C:\QtSDK\qwt-6.0.0\src
LIBS += C:\QtSDK\qwt-6.0.0\lib\libqwt.a

INCLUDEPATH += C:\qwtpolar-1.0.1\src
LIBS += C:\qwtpolar-1.0.1\lib\libqwtpolar.a

INCLUDEPATH += C:\QtSDK\muparser_v2_2_3\src
INCLUDEPATH += C:\QtSDK\muparser_v2_2_3\include
LIBS += C:\QtSDK\muparser_v2_2_3\lib\libmuparser.a
