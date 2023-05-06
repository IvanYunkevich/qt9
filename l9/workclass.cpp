#include "workclass.h"

WorkClass::WorkClass(QObject *parent)
    : QObject{parent}
{
    file = new QFile("../9/res/tasks.txt");
    file->open(QIODevice::ReadWrite);
}

WorkClass::~WorkClass(){
    if(file){
        file->close();
    }
    delete file;
}

void WorkClass::saveWork()
{
    QTextStream stream(file);
    QString data = "Task Name: " + WorkName + ", Process: " + QString::number(process) + ", End Date: " + QString::number(day) + "." + QString::number(month) + "." + QString::number(year) + "\n";
    stream << data;
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

