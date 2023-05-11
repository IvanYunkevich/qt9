#include "workclass.h"

WorkClass::WorkClass(QObject *parent)
    : QObject{parent}
{
    file = new QFile("../9/res/tasks.txt");
    file->open(QIODevice::ReadWrite);
    QTextStream stream(file);
    QString file_data = stream.readAll();
    count = file_data.count("Work");
}

WorkClass::~WorkClass(){
    if(file){
        file->close();
    }
    delete file;
}

bool WorkClass::saveWork()
{
    if(WorkName.size() != 0){
        QTextStream stream(file);
        QString data = "Task Name: " + WorkName + ", Process: " + QString::number(process) + ", End Date: " + QString::number(day) + "." + QString::number(month) + "." + QString::number(year) + "\n";
        stream << data;
        (count)++;
        return true;
    }    else{
        return false;
    }
}

void WorkClass::setDay(int newDay)
{
    day = newDay;
}

void WorkClass::setMonth(int newMonth)
{
    month = newMonth;
}

void WorkClass::setYear(int newYear)
{
    year = newYear;
}

void WorkClass::setProcess(int newProcess)
{
    process = newProcess;
}

void WorkClass::setWorkName(const QString &newWorkName)
{
    WorkName = newWorkName;
}

int WorkClass::getCount() const
{
    return count;
}
