QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BOARD/block.cpp \
    BOARD/board.cpp \
    CORE/customscene.cpp \
    CORE/customview.cpp \
    FIGURES/elephant.cpp \
    FIGURES/figure.cpp \
    FIGURES/horse.cpp \
    FIGURES/king.cpp \
    FIGURES/pawn.cpp \
    FIGURES/queen.cpp \
    FIGURES/rook.cpp \
    main.cpp

HEADERS += \
	BOARD/block.h \
    BOARD/board.h \
    CORE/customscene.h \
    CORE/customview.h \
	FIGURES/elephant.h \
    FIGURES/figure.h \
	FIGURES/horse.h \
    FIGURES/king.h \
	FIGURES/pawn.h \
	FIGURES/queen.h \
	FIGURES/rook.h \
	STATEMENTS.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
	Figures.qrc
