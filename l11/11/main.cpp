#include "mainwindow.h"
#include <QQmlApplicationEngine>
#include <QApplication>
#include "WorkClass.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<WorkClass>("com.workclass", 1,0, "WorkClass");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
