import QtQuick 2.15
import QtQuick.Controls 2.12

BorderImage {
    width: _txt+15
    height: _txt+12
    source: "qrc:///res/button_s.png"
    id: _button
    Text{
        id: _txt
        color: "White"
        anchors.centerIn: _button
        text: "Save"
        font.pixelSize: 13
    }
    MouseArea{
        anchors.fill: _button
        onClicked: {
            _organizer.setDay(_o_day.value)
            _organizer.setMonth(_o_month.value)
            _organizer.setYear(_o_year.value)
            _organizer.setProcess(_o_process.value)
            _organizer.setWorkName(_textEdit.text)
            if(!_organizer.saveWork()){
                err_mess.text = "Please Write Task Name"
            }
            else{
                numb_txt.text = Number(_organizer.getCount());
                err_mess.text = ""
            }
        }
        onPressed: {
            _button.width = 75
            _button.height = 25
            _txt.font.pixelSize = 11
        }
        onReleased: {
            _button.width = 80
            _button.height = 30
            _txt.font.pixelSize = 13
        }
    }
}
