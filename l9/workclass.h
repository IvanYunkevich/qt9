#ifndef WORKCLASS_H
#define WORKCLASS_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class WorkClass : public QObject
{
    Q_OBJECT

public:
    explicit WorkClass(QObject *parent = nullptr);
    ~WorkClass();
    Q_INVOKABLE
    void saveWork();
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

private:
    int day, month, year, process;
    QString WorkName;
    QFile *file;
};

#endif // WORKCLASS_H
