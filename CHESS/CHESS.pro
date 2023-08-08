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
    FIGURES/figure.cpp \
    FIGURES/king.cpp \
    main.cpp

HEADERS += \
	BOARD/block.h \
    BOARD/board.h \
    CORE/customscene.h \
    CORE/customview.h \
    FIGURES/figure.h \
    FIGURES/king.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
	Figures.qrc
