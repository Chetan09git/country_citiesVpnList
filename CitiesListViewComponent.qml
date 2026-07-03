import QtQuick

ListView {
    id: citiesListView
    width: parent.width
    visible: root.expanded
    height: root.expanded ? contentHeight : 0
    model: cities

    delegate: Rectangle {
        width: parent.width
        height: 50
        color: "#28223C"

        BorderComponent{
            width: parent.width * 0.85
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: cityText
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.18
            font.pixelSize: 15
            font.bold: true
            anchors.verticalCenter: parent.verticalCenter
            text: modelData.name
            color: "white"
        }

        Text {
            font.pixelSize: 14
            anchors.right: parent.right
            anchors.rightMargin: 27
            anchors.verticalCenter: parent.verticalCenter
            color: "#9CA3AF"
            text: modelData.randomNumber + " ms"
        }
    }
}
