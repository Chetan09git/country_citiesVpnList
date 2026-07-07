import QtQuick 2.15
import QtQuick.Controls

Item {
    width: parent.width
    height: 40
    property bool comboBoxIsEnable: false
    property alias models: comboBox.model
    property string headerTitle: "All location"

    Text {
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.verticalCenter: parent.verticalCenter
        text: headerTitle
        font.bold: true
        font.family: "Inter"
        color: "#ffffff"
        font.pixelSize: 17
    }

    ComboBox {
        id:comboBox
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        visible: comboBoxIsEnable

        contentItem:Text {
            text: comboBox.displayText
            color: "#1e90ff"
            anchors.fill: parent
            anchors.rightMargin: parent.width * 0.3
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
        }
        onCurrentIndexChanged: {
            countryModel.setSortType(currentIndex)
        }
        background: Rectangle{
            color: "Transparent"
        }

    }
}