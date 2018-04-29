QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    app/xylotoyrc.cpp \
    lib/misulib/comm/heartbeat.cpp \
    lib/misulib/widgets/core/rootnotesetter.cpp \
    lib/misulib/comm/libofqf/qoscclient.cpp \
    lib/misulib/comm/mastersender.cpp \
    lib/misulib/models/freqtriple.cpp \
    lib/misulib/comm/libofqf/qosctypes.cpp \
    lib/misulib/models/pitchcolor.cpp \
    lib/misulib/widgets/core/scaleselect.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    app/xylotoyrc.h \
    lib/misulib/comm/heartbeat.h \
    lib/misulib/widgets/core/rootnotesetter.h \
    lib/misulib/comm/mastersender.h \
    lib/misulib/comm/libofqf/qoscclient.h \
    lib/misulib/models/freqtriple.h \
    lib/misulib/comm/libofqf/qosctypes.h \
    lib/misulib/models/pitchcolor.h \
    lib/misulib/widgets/core/scaleselect.h

DISTFILES +=
