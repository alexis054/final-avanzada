QT += testlib
QT -= gui
#CONFIG+= c++11 console
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

QT += widgets
LIBS += -lOpengl32

TEMPLATE = app

SOURCES +=  tst_ei_autotest.cpp \
    ../estadisticos.cpp \
    ../filtro.cpp \
    ../filtroespacial.cpp \
    ../filtropap.cpp \
    ../gestordearchivos.cpp \
    ../gestordearchivosaic.cpp \
    ../gestordearchivospnm.cpp \
    ../graficador.cpp \
    ../imagen.cpp \
    ../interfaz.cpp \
    ../lut.cpp \
    ../pixel.cpp \
    ../sistema.cpp
HEADERS += \
    ../estadisticos.h \
    ../filtroespacial.h \
    ../filtropap.h \
    ../gestordearchivos.h \
    ../gestordearchivosaic.h \
    ../gestordearchivospnm.h \
    ../graficador.h \
    ../imagen.h \
    ../interfaz.h \
    ../lut.h \
    ../pixel.h \
    ../sistema.h
