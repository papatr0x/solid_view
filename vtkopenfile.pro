#-------------------------------------------------
#
# Project created by QtCreator 2018-03-10T12:57:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vtkopenfile
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


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    DisplayWindow.cpp

HEADERS += \
        MainWindow.h \
    DisplayWindow.h

FORMS += \
        MainWindow.ui

LIBS += -L$$PWD/../../vtk-install/lib/ \
  -lvtkalglib-8.1 \
  -lvtkCommonColor-8.1\
  -lvtkCommonComputationalGeometry-8.1 \
  -lvtkCommonCore-8.1 \
  -lvtkCommonDataModel-8.1 \
  -lvtkCommonExecutionModel-8.1 \
  -lvtkCommonMath-8.1 \
  -lvtkCommonMisc-8.1 \
  -lvtkCommonSystem-8.1 \
  -lvtkCommonTransforms-8.1 \
  -lvtkFiltersCore-8.1 \
  -lvtkFiltersExtraction-8.1 \
  -lvtkFiltersGeneral-8.1 \
  -lvtkFiltersGeometry-8.1 \
  -lvtkFiltersSources-8.1 \
  -lvtkFiltersStatistics-8.1 \
  -lvtkglew-8.1 \
  -lvtkGUISupportQt-8.1 \
  -lvtkGUISupportQtOpenGL-8.1 \
  -lvtkImagingCore-8.1 \
  -lvtkImagingFourier-8.1 \
  -lvtkInteractionStyle-8.1 \
  -lvtkIOCore-8.1 \
  -lvtkIOGeometry-8.1 \
  -lvtkIOLegacy-8.1 \
  -lvtkIOPLY-8.1 \
  -lvtklz4-8.1 \
  -lvtkRenderingCore-8.1 \
  -lvtkRenderingOpenGL2-8.1 \
  -lvtksys-8.1 \
  -lvtkzlib-8.1 \


INCLUDEPATH += $$PWD/../../vtk-install/include/vtk-8.1
DEPENDPATH += $$PWD/../../vtk-install/include/vtk-8.1
