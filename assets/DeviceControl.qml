import QtQuick 2.0

Rectangle {
    width: 300
    height: 600
    Header {
        id: header
        anchors.top: parent.top
        headerText: "设备"
    }

    Dialog {
        id: info
        anchors.centerIn: parent
        visible: false
        dialogText: "执行中...";
    }

    Connections {
        target: device
//        onCharacteristicsUpdated: {
//            menu.menuText = "Back"
//            if (characteristicview.count === 0) {
//                info.dialogText = "No characteristic found"
//                info.busyImage = false
//            } else {
//                info.visible = false
//                info.busyImage = true
//            }
//        }

        onDisconnected: {
            pageLoader.source = "main.qml"
        }
    }
    Row {
        spacing: 6
        Button {
            id: sendButton
            width: 100; height: 20
            text: "Send"
            onClicked: { status.text = "Send" }
            KeyNavigation.tab: discardButton
        }
        Button { id: discardButton
            width: 100; height: 20
            text: "Discard"
            onClicked: { status.text = "Discard" }
            KeyNavigation.tab: checkBox
        }
    }

    Menu {
        id: menu
        anchors.bottom: parent.bottom
        menuWidth: parent.width
        menuText: device.update
        menuHeight: (parent.height/6)
        onButtonClick: {
            pageLoader.source = "Services.qml"
            device.update = "Back"
        }
    }

}
