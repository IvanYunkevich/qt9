#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>
#include <QLabel>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include "downloader.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Downloader* downloader;
    QProgressBar *ppb;
    QLineEdit *txt;
    QPushButton *button;
    QGridLayout * layout;
    QWidget *wgt;
    int *col;
    int *row;

    void showPic(const QString&);
    void deleteObj();
private slots:
    void slotGo();
    void slotError();
    void slotDownloadProgress(qint64, qint64);
    void slotDone(const QUrl&, const QByteArray&);
};
#endif // MAINWINDOW_H
