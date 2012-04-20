TARGET     = smack-qt
TEMPLATE   = lib
QT        += dbus
QT        -= gui
CONFIG    += link_pkgconfig
PKGCONFIG += libsmack

QMAKE_CXXFLAGS += -fvisibility=hidden -fvisibility-inlines-hidden

DEFINES += SMACKQT_LIBRARY

SOURCES += \
    dbussmackcontext.cpp \
    smackqt.cpp \
    connectioncredentialsinterface.cpp

PUBLIC_HEADERS +=\
    dbussmackcontext.h \
    smackqt.h \
    DBusSmackContext \
    SmackQt \
    smack-qt_global.h

HEADERS += $$PUBLIC_HEADERS \
    connectioncredentialsinterface.h

SMACK_LIB_PATH = /usr/lib
SMACK_INCLUDE_PATH = /usr/include/smack-qt

target.path = $${SMACK_LIB_PATH}

headerfiles.files = $$PUBLIC_HEADERS
headerfiles.path = $${SMACK_INCLUDE_PATH}

CONFIG += create_pc create_prl
QMAKE_PKGCONFIG_NAME = lib$$TARGET
QMAKE_PKGCONFIG_DESCRIPTION = lib$$TARGET library
QMAKE_PKGCONFIG_INCDIR = $${SMACK_INCLUDE_PATH}
QMAKE_PKGCONFIG_DESTDIR = pkgconfig

QMAKE_CLEAN += *.pc *.prl

pkgconfig_clean.commands = -$(DEL_FILE) pkgconfig/*
pkgconfig_distclean.commands = -$(DEL_DIR) pkgconfig
pkgconfig_distclean.depends = pkgconfig_clean
clean.depends += pkgconfig_clean
distclean.depends += pkgconfig_distclean

QMAKE_EXTRA_TARGETS += clean distclean pkgconfig_clean pkgconfig_distclean

INSTALLS += target headerfiles
