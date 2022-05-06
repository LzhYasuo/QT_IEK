#-------------------------------------------------
#
# Project created by QtCreator 2022-03-09T10:00:00
#
#-------------------------------------------------

QT       += core gui charts

INCLUDEPATH += F:/lib_opencv/include/opencv \
               F:/lib_opencv/include/opencv2 \
               F:/lib_opencv/include

LIBS += -L F:/lib_opencv/lib/libopencv_*.a

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_IEK
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
    Src/Gui/MainWindow.cpp \
    Src/Gui/DockWidget.cpp \
    Src/Chart/ChartCurve.cpp \
    Src/Chart/ChartLine.cpp \
    Src/Chart/Chart.cpp \
    Src/Chart/ChartBar.cpp \
    Src/Chart/ChartPie.cpp \
    Src/Control/ControlDashBoard.cpp \
    Src/Control/ControlRoundProBar.cpp \
    Src/Gui/SmallWindow.cpp \
    Src/Gui/BaseWidget.cpp \
    Src/Pub/PubCss.cpp \
    Src/Model/MoldProModelDelegate.cpp \
    Src/Model/MoldProTableView.cpp \
    Src/Model/LoadDistributionModelDelegate.cpp \
    Src/Model/LoadDistributionTableView.cpp \
    Src/Chart/ChartBaseSeries.cpp \
    Src/Model/PartsInventoryModelDelegate.cpp \
    Src/Model/PartsInventoryTableView.cpp \
    Src/Gui/OpenCVGLWidget.cpp \
    Src/Task/OpenCVVideo.cpp \
    Src/Gui/TypeWindow.cpp \
    Src/Gui/ModuleWidget.cpp \
    Src/Pub/PubFunction.cpp

HEADERS += \
    Src/Gui/MainWindow.h \
    Src/Gui/DockWidget.h \
    Src/Chart/ChartCurve.h \
    Src/Chart/ChartLine.h \
    Src/Chart/Chart.h \
    Src/Chart/ChartBar.h \
    Src/Chart/ChartPie.h \
    Src/Control/ControlDashBoard.h \
    Src/Control/ControlRoundProBar.h \
    Src/Gui/SmallWindow.h \
    Src/Gui/BaseWidget.h \
    Src/Pub/PubCss.h \
    Src/Model/MoldProModelDelegate.h \
    Src/Model/MoldProTableView.h \
    Src/Model/LoadDistributionModelDelegate.h \
    Src/Model/LoadDistributionTableView.h \
    Src/Chart/ChartBaseSeries.h \
    Src/Model/PartsInventoryModelDelegate.h \
    Src/Model/PartsInventoryTableView.h \
    Src/Gui/OpenCVGLWidget.h \
    Src/Task/OpenCVVideo.h \
    Src/Gui/TypeWindow.h \
    Src/Gui/ModuleWidget.h \
    Src/Pub/PubFunction.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
