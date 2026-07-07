import QtQuick
import QtQuick.Controls.Basic

TextField {
    id: searchInput
    leftPadding: 30
    verticalAlignment: Text.AlignVCenter
    placeholderText: "Search cities or countries"
    font.pixelSize: 16
    background: Rectangle {
        radius: 15
        color: "#322D45"

        CustomImage{
            width: parent.width * 0.04
            height: width
            opacity: 1
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/Png/search.png"

        }
    }
}
