QT -= gui
#QT += gui#?


CONFIG += c++11 console
CONFIG -= app_bundle


QT += widgets
LIBS += -lopengl32 # agrego esto

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        estadisticos.cpp \
        filtroespacial.cpp \
        filtropap.cpp \
        gestordearchivos.cpp \
        gestordearchivosaic.cpp \
        gestordearchivospnm.cpp \
        graficador.cpp \
        imagen.cpp \
        interfaz.cpp \
        lut.cpp \
        main.cpp \
        pixel.cpp \
        sistema.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    estadisticos.h \
    filtroespacial.h \
    filtropap.h \
    gestordearchivos.h \
    gestordearchivosaic.h \
    gestordearchivospnm.h \
    graficador.h \
    imagen.h \
    interfaz.h \
    lut.h \
    pixel.h \
    sistema.h
