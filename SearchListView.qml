import QtQuick

Rectangle {
    width: ListView.view.width
    height: 50
    color: "#28223C"

    BorderComponent {
        width: parent.width * 0.9
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Row {
        anchors.fill: parent
        anchors.leftMargin: 10
        spacing: 12

        CustomImage {
            width: 18
            height: 18
            anchors.verticalCenter: parent.verticalCenter
            source: modelData.image
        }

        Text {
            anchors.verticalCenter: parent.verticalCenter
            text: modelData.name
            color: "white"
            font.pixelSize: 18
        }
    }

    Text {
        anchors.right: parent.right
        anchors.rightMargin: 27
        anchors.verticalCenter: parent.verticalCenter
        color: "#9CA3AF"
        text: modelData.randomNumber + " ms"
        font.pixelSize: 14
    }
}