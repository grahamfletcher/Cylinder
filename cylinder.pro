QT += opengl
TEMPLATE = app
TARGET =
DEPENDPATH +=
INCLUDEPATH += ./src
DESTDIR = bin
OBJECTS_DIR = obj
MOC_DIR = moc

# Input
HEADERS += src/Cylinder.h \
           src/CylinderGLWidget.h \
           src/MainWindow.h
SOURCES += src/main.cpp \
           src/Cylinder.cpp \
           src/CylinderGLWidget.cpp \
           src/MainWindow.cpp

test.target = test
test.commands = ./test.sh;
test.depends =

QMAKE_EXTRA_TARGETS += test
