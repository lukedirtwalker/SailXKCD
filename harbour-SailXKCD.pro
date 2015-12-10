# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = harbour-SailXKCD

CONFIG += sailfishapp c++11

QT += network

SOURCES += \
    src/main.cpp \
    src/xkcdfetcher.cpp \
    src/xkcdcomic.cpp

OTHER_FILES += \
    rpm/harbour-SailXKCD.changes.in \
    rpm/harbour-SailXKCD.spec \
    rpm/harbour-SailXKCD.yaml \
    translations/*.ts \
    harbour-SailXKCD.desktop \
    qml/main.qml

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/harbour-SailXKCD-de.ts

HEADERS += \
    src/xkcdfetcher.h \
    src/xkcdcomic.h

