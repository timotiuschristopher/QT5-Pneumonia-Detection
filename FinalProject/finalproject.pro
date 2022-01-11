#-------------------------------------------------
#
# Project created by QtCreator 2018-08-06T01:21:19
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = qt-opencv-cpp-project
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

#CONFIG += link_pkgconfig
#PKGCONFIG += opencv

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += "F:\opencv\build\include"

LIBS += "F:\opencv-build\bin\libopencv_core454.dll"
LIBS += "F:\opencv-build\bin\libopencv_highgui454.dll"
LIBS += "F:\opencv-build\bin\libopencv_imgcodecs454.dll"
LIBS += "F:\opencv-build\bin\libopencv_imgproc454.dll"
LIBS += "F:\opencv-build\bin\libopencv_objdetect454.dll"
LIBS += "F:\opencv-build\bin\libopencv_video454.dll"
LIBS += "F:\opencv-build\bin\libopencv_videoio454.dll"
LIBS += "F:\opencv-build\bin\libopencv_features2d454.dll"
LIBS += "F:\opencv-build\bin\libopencv_calib3d454.dll"
LIBS += "F:\opencv-build\bin\libopencv_features2d454.dll"
LIBS += "F:\opencv-build\bin\libopencv_flann454.dll"
