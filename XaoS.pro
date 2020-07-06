# -------------------------------------------------
# Project created by QtCreator 2009-10-29T19:21:55
# -------------------------------------------------

lessThan(QT_MAJOR_VERSION, 5): error("requires Qt >= 5")
lessThan(QT_MINOR_VERSION, 6): error("requires Qt >= 5.6")

TEMPLATE = app

QT += widgets

macx {
    TARGET = XaoS
} else {
    TARGET = xaos
}

contains(DEFINES, USE_OPENGL) {
    QT += opengl
    win32:LIBS += -lopengl32
}

contains(DEFINES, USE_FLOAT128) {
    LIBS += -lquadmath
} else {
    LIBS += -lquadmath
    DEFINES += USE_LONG_DOUBLE
}

CONFIG(debug, debug|release) {
    DEFINES += DEBUG
    win32:CONFIG += console
}

CONFIG(release, debug|release) {
    QMAKE_POST_LINK=$(STRIP) $(TARGET)
    linux: {
        # This may help in debugging some odd issues under Debian:
        # QMAKE_CFLAGS   *= $(shell dpkg-buildflags --get CFLAGS)
        # QMAKE_CXXFLAGS *= $(shell dpkg-buildflags --get CXXFLAGS)
        # QMAKE_LFLAGS   *= $(shell dpkg-buildflags --get LDFLAGS)
    }
}

isEmpty(QMAKE_LRELEASE) {
    win32 {
        QMAKE_LRELEASE = $$[QT_INSTALL_BINS]\lrelease.exe
    } else {
        QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease
    }
    unix {
        !exists($$QMAKE_LRELEASE) { QMAKE_LRELEASE = lrelease-qt5 }
    } else {
        !exists($$QMAKE_LRELEASE) { QMAKE_LRELEASE = lrelease }
    }
}

CONFIG += optimize_full
QMAKE_CXXFLAGS += -ffast-math
QMAKE_CFLAGS += -ffast-math

RESOURCES += XaoS.qrc

DESTDIR = $$PWD/bin

include($$PWD/i18n/i18n.pri)
include($$PWD/src/include/include.pri)
include($$PWD/src/ui/ui.pri)
include($$PWD/src/engine/engine.pri)
include($$PWD/src/ui-hlp/ui-hlp.pri)
include($$PWD/src/util/util.pri)
include($$PWD/src/sffe/sffe.pri)
