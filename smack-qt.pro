TEMPLATE = subdirs
SUBDIRS = src doc

QTCONFIGFILES.files = smack-qt.prf
QTCONFIGFILES.path = /usr/share/qt4/mkspecs/features

INSTALLS += QTCONFIGFILES
