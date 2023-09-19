QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buscarmatricula.cpp \
    buscarnome.cpp \
    main.cpp \
    mainwindow.cpp \
    ordenardepartamento.cpp \
    ordenardepartamentotipocontratonome.cpp \
    ordenarmatricula.cpp \
    ordenarnome.cpp \
    ordenartipodecontrato.cpp \
    ordenartitulacao.cpp \
    professor.cpp \
    templatebusca.cpp \
    templateordenacao.cpp \
    tratamentodearquivos.cpp

HEADERS += \
    buscarmatricula.h \
    buscarnome.h \
    mainwindow.h \
    ordenardepartamento.h \
    ordenardepartamentotipocontratonome.h \
    ordenarmatricula.h \
    ordenarnome.h \
    ordenartipodecontrato.h \
    ordenartitulacao.h \
    professor.h \
    templatebusca.h \
    templateordenacao.h \
    tratamentodearquivos.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
