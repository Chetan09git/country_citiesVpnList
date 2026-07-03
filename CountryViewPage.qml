import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

ColumnLayout {
    id: rootPage

    HeaderComponent {
        id: header
        Layout.fillWidth: true
        Layout.preferredHeight: 75
    }
    ListViewComponent {
        id: listView

        Layout.fillWidth: true
        Layout.fillHeight: true

        model: header.searchText !== ""
               ? countryModel.sourceModel.getSearchResults(header.searchText)
               : countryModel

        delegate: header.searchText !== ""
                  ? searchDelegate
                  : countryDelegate
    }

    Component {
        id: countryDelegate

        CountryListDelegate {
        }
    }

    Component {
        id: searchDelegate

        SearchListView {

        }
    }
}
