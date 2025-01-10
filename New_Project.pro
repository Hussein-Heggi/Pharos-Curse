QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arrow.cpp \
    boss.cpp \
    bullet.cpp \
    enemy1.cpp \
    enemy2.cpp \
    fireball.cpp \
    health.cpp \
    login.cpp \
    loss.cpp \
    main.cpp \
    mainwindow.cpp \
    play.cpp \
    player.cpp \
    poisonball.cpp \
    score.cpp \
    shop.cpp \
    win.cpp

HEADERS += \
    arrow.h \
    boss.h \
    bullet.h \
    enemy1.h \
    enemy2.h \
    fireball.h \
    health.h \
    login.h \
    loss.h \
    mainwindow.h \
    play.h \
    player.h \
    poisonball.h \
    score.h \
    shop.h \
    win.h

FORMS += \
    login.ui \
    loss.ui \
    mainwindow.ui \
    play.ui \
    shop.ui \
    win.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
