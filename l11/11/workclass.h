#ifndef WORKCLASS_H
#define WORKCLASS_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QTableView>

class WorkClass : public QObject
{
    Q_OBJECT

public:
    explicit WorkClass(QObject *parent = nullptr);
    ~WorkClass();
    Q_INVOKABLE
    bool saveWork();
    Q_INVOKABLE
    void setDay(int newDay);
    Q_INVOKABLE
    void setMonth(int newMonth);
    Q_INVOKABLE
    void setYear(int newYear);
    Q_INVOKABLE
    void setProcess(int newProcess);
    Q_INVOKABLE
    void setWorkName(const QString &newWorkName);
    Q_INVOKABLE
    int getCount() const;
    Q_INVOKABLE
    void openEx();

private:
    bool createConnection();
    bool createTable();
    bool insertRecord(QString _name, int proc, QString _date);
    int day, month, year, process;
    int count = 0;
    QSqlDatabase db;
    QString WorkName;
    QSqlQueryModel * model;
    QTableView * view;
};

#endif // WORKCLASS_H
