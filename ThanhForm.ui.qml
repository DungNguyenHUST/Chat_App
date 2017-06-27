import QtQuick 2.4

Item {
    id: item1
    width: 400
    height: 400
    property alias listView1: listView1

    Row {
        id: row1
        x: 0
        y: 0
        width: 200
        height: 400

        Text {
            id: text1
            width: 54
            height: 49
            color: "#301818"
            text: qsTr("Text")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 7
            styleColor: "#df2020"
            clip: false
            font.pixelSize: 12
        }

        Text {
            id: text2
            text: qsTr("Text")
            font.pixelSize: 12
        }

        Text {
            id: text3
            text: qsTr("Text")
            font.pixelSize: 12
        }
    }

    ListView {
        id: listView1
        width: 110
        height: 160
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.left: row1.right
        anchors.leftMargin: 8
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
        delegate: Item {
            x: 5
            width: 80
            height: 40
            MyComponent1 {
            }
        }
    }
}
