QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acercade.cpp \
        main.cpp \
        mainwindow.cpp \
    dialogtareas.cpp \
    tarea.cpp

HEADERS += \
    acercade.h \
        mainwindow.h \
    dialogtareas.h \
    tarea.h

FORMS += \
    acercade.ui \
        mainwindow.ui \
    dialogtareas.ui

RESOURCES += \
    recursos.qrc \
    recursos/agregar-archivo.png \
    recursos/agregar.png \
    recursos/lista-de-quehaceres.png \
    recursos/salida.png

TRANSLATIONS +=\
    Tareas_fr.ts \
    Tareas_en.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Tareas_fr.qm \
    Tareas_fr.ts \
    recursos.qrc \
    recursos/agregar-archivo.png \
    recursos/agregar.png \
    recursos/lista-de-quehaceres.png \
    recursos/salida.png

