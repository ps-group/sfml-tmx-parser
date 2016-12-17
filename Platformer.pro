TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

# Sets target destination dir - platform independent
win32 {
    build_pass: CONFIG(debug, debug|release) {
        DESTDIR = $$OUT_PWD/debug
    }
    else: build_pass {
        DESTDIR = $$OUT_PWD/release
    }
}

unix {
    DESTDIR = $$OUT_PWD
}

# Create 'copy' commands for $DIRS
CP_CMD += $(COPY) -r $$system_quote($$PWD/res) $$system_quote($$DESTDIR)

create.commands = $(MKDIR) $$system_quote($$DESTDIR/res);

QMAKE_EXTRA_TARGETS += create
POST_TARGETDEPS += create

QMAKE_POST_LINK += $$CP_CMD

LIBS += -lsfml-system -lsfml-window -lsfml-graphics

SOURCES += src/main.cpp \
    lib/tinyxml2/tinyxml2.cpp \
    src/TmxLevel.cpp \
    src/GameView.cpp \
    src/GameScene.cpp

HEADERS += \
    lib/tinyxml2/tinyxml2.h \
    src/TmxLevel.h \
    src/GameView.h \
    src/GameScene.h
