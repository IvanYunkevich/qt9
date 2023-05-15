import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import com.workclass 1.0

Rectangle {
    width: 450
    height: 270
    visible: true
    id: root

    WorkClass{
        id:_organizer
    }

    GridLayout{
        rows: 9
        columns: 2
        Text{
            Layout.row: 0
            Layout.column: 0
            text: "Task Name:"
            color: "Black"
            font.family: "Helvetica"
            font.pointSize: 14
        }
        Text{
            Layout.row: 1
            Layout.column: 1
            text: "End Date"
            color: "Black"
            font.family: "Helvetica"
            font.pointSize: 14
        }
        Text{
            Layout.row: 2
            Layout.column: 0
            text: "Day:"
            color: "Black"
            font.family: "Helvetica"
            font.pointSize: 14
        }
        Text{
            Layout.row: 3
            Layout.column: 0
            text: "Month:"
            color: "Black"
            font.family: "Helvetica"
            font.pointSize: 14
        }
        Text{
            Layout.row: 4
            Layout.column: 0
            text: "Year:"
            color: "Black"
            font.family: "Helvetica"
            font.pointSize: 14
        }
        Text{
            Layout.row: 5
            Layout.column: 0
            text: "Current Progress:"
            color: "Black"
            font.family: "Helvetica"
            font.pointSize: 14
        }
        Text{
            Layout.row: 6
            Layout.column: 0
            text: "number of tasks in file:"
            color: "Black"
            font.family: "Helvetica"
            font.pointSize: 14
        }
        Text{
            Layout.row: 6
            Layout.column: 1
            text: Number(_organizer.getCount())
            color: "Black"
            font.family: "Helvetica"
            font.pointSize: 14
            id: numb_txt
        }
        Text{
            Layout.row: 8
            Layout.column: 1
            text: ""
            color: "Black"
            font.family: "Helvetica"
            font.pointSize: 14
            id: err_mess
        }
        TextField{
            Layout.row: 0
            Layout.column: 1
            width: 240
            height: 60
            id:_textEdit
        }
        SpinBox{
            Layout.row: 2
            Layout.column: 1
            id: _o_day
            value: 1
            from: 1
            to: 31
        }
        SpinBox{
            Layout.row: 3
            Layout.column: 1
            id: _o_month
            value: 1
            from: 1
            to: 12
        }
        SpinBox{
            Layout.row: 4
            Layout.column: 1
            id: _o_year
            value: 2023
            from: 2023
            to: 2100
        }
        SpinBox{
            Layout.row: 5
            Layout.column: 1
            id: _o_process
            value: 1
            to: 10
        }
        Button_s{
            width: 80
            height: 30
            Layout.row: 7
            Layout.column: 1
        }
        Button_db{
            width: 120
            height: 30
            Layout.row: 7
            Layout.column: 0
        }
    }
}
