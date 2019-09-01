#-------------------------------------------------
#
# Project created by QtCreator 2019-08-28T00:24:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = single_gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    affine.cpp \
    vigenere.cpp \
    caesar.cpp \
    playfair.cpp \
    column.cpp \
    permutation.cpp \
    rc4.cpp \
    des.cpp \
    rsa.cpp \
    dh.cpp \
    content.cpp

HEADERS += \
        mainwindow.h \
    affine.h \
    vigenere.h \
    caesar.h \
    playfair.h \
    column.h \
    permutation.h \
    rc4.h \
    des.h \
    rsa.h \
    dh.h \
    content.h

FORMS += \
        mainwindow.ui \
    affine.ui \
    vigenere.ui \
    caesar.ui \
    playfair.ui \
    column.ui \
    permutation.ui \
    rc4.ui \
    des.ui \
    rsa.ui \
    dh.ui \
    content.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
