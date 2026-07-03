import QtQuick
import QtQuick.Controls

ListView {
    id: rootListView
    clip: true
    model: countryModel
    header: ListviewHeaderComponent {
        width: ListView.view.width
        height: 40
        headerTitle: rootListView.model === countryModel ? "All location" : "Search results"
        comboBoxIsEnable: rootListView.model === countryModel
        models: ["Fastest","A-Z","Z-A"]
    }

    ScrollBar.vertical: ScrollBar {
        id: verticalScrollBar
        policy: ScrollBar.AlwaysOn
        width: parent.width * 0.03
        opacity: 1
        rightPadding: 10
        
        contentItem: Rectangle {
            implicitWidth: parent.width * 0.3
            radius: implicitWidth / 2
            color: "white"
        }
        
        background: Rectangle {
            color: "transparent"
        }
    }
}
