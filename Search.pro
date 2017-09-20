TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    action.cpp \
    state.cpp \
    node.cpp

HEADERS += \
    action.h \
    state.h \
    city.h \
    node.h

