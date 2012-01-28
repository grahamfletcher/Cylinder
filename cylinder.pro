TEMPLATE = app
TARGET =
DEPENDPATH +=
INCLUDEPATH += ./src
DESTDIR = bin
OBJECTS_DIR = obj
MOC_DIR = moc

# Input
HEADERS += src/Cylinder.h \
           src/MainWindow.h \
           src/VideoSelectDialog.h
SOURCES += src/main.cpp \
           src/Cylinder.cpp \
           src/MainWindow.cpp \
           src/VideoSelectDialog.cpp

LIBS +=
