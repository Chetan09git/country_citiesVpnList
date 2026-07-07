import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: window
    minimumHeight: 600
    maximumHeight: minimumHeight
    minimumWidth: 390
    maximumWidth: minimumWidth
    visible: true
    title: qsTr("VPN - Super Unlimited Proxy")
    color: "#28223C"
    // ListviewHeaderComponent{

    // }
    CountryViewPage{
        anchors.fill: parent
    }
}
