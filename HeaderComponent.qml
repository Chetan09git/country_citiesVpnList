import QtQuick

Item {
    id: searchField
    width: parent.width
    height: parent.height * 0.1

    property alias searchText: searchInput.text

    Row {
        id: searchRow
        anchors.fill: parent
        leftPadding: 16
        topPadding: 16
        spacing: 20

        CustomImage{
            id: backButton
            width: parent.width * 0.06
            height: searchInput.height
            imageSource: "qrc:/Png/left.png"
            anchors.verticalCenter: parent.verticalCenter
            MouseArea {anchors.fill: parent; onClicked: Window.window.close()
            }
        }

        SearchFieldComponent{
            id: searchInput
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width - backButton.width * 3.7
            height: parent.height * 0.48

            onTextChanged:
                countryModel.setFilterString(text)
        }
    }
}
