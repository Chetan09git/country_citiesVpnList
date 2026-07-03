import QtQuick
import QtQuick.Layouts

Column {
    id: root
    width: ListView.view.width
    property bool expanded: false

    Rectangle {
        id: dataRect
        width: parent.width
        height: 50
        color: "#28223C"


        BorderComponent {
            width: parent.width * 0.85
            anchors.horizontalCenter: parent.horizontalCenter
        }

        RowLayout {
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.right: parent.right
            spacing: 12

            Item {
                id: emptyArea
                width: 18
                height: 1
            }
            CustomImage {
                id: downButton
                imageSource: "qrc:/Png/downArrow.png"
                opacity: cities.length > 0 ? 2.0 : 0.0
                Layout.preferredWidth: 12

                rotation: expanded ? 180 : 0
                Layout.preferredHeight: 24

                MouseArea {
                    anchors.fill: parent
                    enabled: cities.length > 0
                    onClicked: root.expanded = !root.expanded
                }
            }
            CustomImage {
                source: CountryImage
                Layout.preferredWidth: 20
                Layout.preferredHeight: 18
            }

            Text {
                text: CountryName
                color: "white"
                font.pixelSize: 15
                font.bold: true
            }

            Text {
                text: "(" + cities.length + ")"
                color: "#9CA3AF"
                font.pixelSize: 14
                visible: cities.length > 0
            }

            Item {
                Layout.fillWidth: true
            }
        }
        Text {
            id: name
            text: RandomNumber+ " ms"
            font.pixelSize: 14
            color: "#9CA3AF"
            anchors.right: parent.right
            anchors.rightMargin: 27
            anchors.verticalCenter: parent.verticalCenter
        }
    }
    CitiesListViewComponent{

    }



}