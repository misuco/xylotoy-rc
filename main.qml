import QtQuick 2.6
import QtQuick.Window 2.2

import "lib/misulib/qml/elements"

Window {
    property bool portrait: height > width

    property int fontSize1: portrait ? height / 25 : width / 20
    property int fontSize3: portrait ? height / 48 : width / 48

    property int buttonSize: portrait ? width/4 :  height/4

    property int buttonRadius: buttonSize/5
    property int borderWidth: 1+buttonSize/50
    property color borderColor: "#333333"

    property color llColor: "#000000"
    property color bgColor: "#333333"
    property color fgColor: "#CCCCCC"
    property color hlColor: "#CC0000"

    visible: true
    width: 640
    height: 480
    title: qsTr("xylotoy remote control")
    color: bgColor

    RootNoteSetter {
        id: rootNoteSetterRow
        model: app.rootNoteSetter
        pitchColors: app.pitchColors
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }
        height: buttonSize * 2
    }

    ScaleSelect {
        id: scaleSelect
        model: app.scaleSelect
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        height: parent.height / 2
    }
}
