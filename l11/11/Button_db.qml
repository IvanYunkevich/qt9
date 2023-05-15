import QtQuick 2.15
import QtQuick.Controls 2.12

BorderImage {
    width: 120
    height: 30
    source: "qrc:///res/button_s.png"
    id: _button_db
    Text{
        id: _txtdb
        color: "White"
        anchors.centerIn: _button_db
        text: "Show Tasks"
        font.pixelSize: 13
    }
    MouseArea{
        anchors.fill: _button_db
        onClicked: {
            _organizer.openEx()
        }
        onPressed: {
            _button_db.width = 95
            _button_db.height = 25
            _txtdb.font.pixelSize = 11
        }
        onReleased: {
            _button_db.width = 120
            _button_db.height = 30
            _txtdb.font.pixelSize = 13
        }
    }
}
