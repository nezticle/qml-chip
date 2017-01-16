import QtQuick 2.0
import io.qad.chip 1.0
import QtQuick.Controls 2.0

Rectangle {
    id: viewBackground
    color: "white"

    Flickable {
        anchors.fill: parent
        contentWidth: sceneItem.width
        contentHeight: sceneItem.height

        ScrollBar.horizontal: ScrollBar { id: hbar; active: vbar.active }
        ScrollBar.vertical: ScrollBar { id: vbar; active: hbar.active }

        ChipItem {
            id: sceneItem
            width: 22000
            height: 14000
            model: chipModel

            scale: 2
        }
    }
}
