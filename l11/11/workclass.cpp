#include "workclass.h"
#include <QDebug>

WorkClass::WorkClass(QObject *parent)
    : QObject{parent}
{
    createConnection();
    QSqlQuery query;
    query.exec("SELECT count (*) FROM tasks");
    while(query.next()){
        count = query.value(0).toInt();
    }
    model = new QSqlQueryModel(this);
    view = new QTableView();
    view->setModel(model);
}

WorkClass::~WorkClass(){
    delete model;
    delete view;
}

bool WorkClass::saveWork()
{
    if(WorkName.size() != 0){
        insertRecord(WorkName, process , QString::number(day) + "." + QString::number(month) + "." + QString::number(year));
        count++;
        return true;
    }
    else{
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

void WorkClass::openEx()
{
    model->setQuery("SELECT * FROM tasks");
    view->resize(500,300);
    view->show();
}

bool WorkClass::createConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../11/res/tasks.db");
    if(!db.open()){
        qDebug() << "error";
        return false;
    }
    return true;
}

bool WorkClass::createTable()
{
    QSqlQuery query;
    QString s = "CREATE TABLE tasks ("
                "id INTEGER PRIMARY KEY NOT NULL,"
                "Task_Name VARCHAR(15),"
                "Process INTEGER NOT NULL,"
                "End_Date VARCHAR(10));";
    if(!query.exec(s)){
        qDebug() << "Unable to create a table";
        return false;
    }
    return true;
}

bool WorkClass::insertRecord(QString _name, int _proc, QString _date)
{
    QSqlQuery query;
    QString s = "INSERT INTO tasks (Task_Name, Process, End_Date)"
                "VALUES('%1','%2','%3');";
    QString q = s.arg(_name).arg(_proc).arg(_date);
    if(!query.exec(q)){
        qDebug() << "error";
        return false;
    }
    return true;
}
