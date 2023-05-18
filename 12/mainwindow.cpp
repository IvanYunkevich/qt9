#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    downloader = new Downloader(this);
    ppb = new QProgressBar(this);
    txt = new QLineEdit(this);
    button = new QPushButton("Search",this);
    col = new int(0);
    row = new int(2);

    connect(button, SIGNAL(clicked()), SLOT(slotGo()));
    connect(downloader, SIGNAL(downloadProgress(qint64,qint64)), SLOT(slotDownloadProgress(qint64, qint64)));
    connect(downloader, SIGNAL(done(QUrl,QByteArray)), SLOT(slotDone(const QUrl &, const QByteArray &)));

    layout = new QGridLayout(this);
    layout->addWidget(txt,0,0);
    layout->addWidget(button,0,1);
    layout->addWidget(ppb,1,0,1,2);

    wgt = new QWidget(this);
    setCentralWidget(wgt);
    wgt->setLayout(layout);
}

MainWindow::~MainWindow()
{
    deleteObj();
}

void MainWindow::showPic(const QString &path)
{
    QPixmap pix(path);
    if(pix.isNull())
        return;
    pix = pix.scaled(pix.size() / 3);
    QLabel * label = new QLabel();
    label->setPixmap(pix);
    layout->addWidget(label,*row,*col);
    (*col)++;
    if(*col%3 == 0){
        (*row)++;
        *col = 0;
    }
}

void MainWindow::deleteObj()
{
    delete downloader;
    delete ppb;
    delete button;
    delete layout;
    delete wgt;
    delete col;
    delete row;
}

void MainWindow::slotGo()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("https://yandex.ru/images/search?text=" + txt->text()));
    QNetworkReply *reply = manager->get(request);
    QEventLoop event;
    connect(reply,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    QString s = reply->readAll();

    qint32 ind1 = s.indexOf("<img", 0);
    qint32 ind2 = s.indexOf("<img", ind1+5);
    qint32 ind3 = s.indexOf("src=",ind2);

    qint32 i = 0;
    for(int x =0;x<3;x++){
        QString lnk;
        i=ind3+5;
        do{
            lnk+=s.at(i);
            i++;
        }while(s.at(i) != '"');
        lnk.remove("amp;");
        downloader->download(QUrl("http:" + lnk));
        ind2 = s.indexOf("<img", ind3);
        ind3 = s.indexOf("src=",ind2);
    }
}

void MainWindow::slotError()
{
    QMessageBox::critical(this, "Error", "Error!");
}

void MainWindow::slotDownloadProgress(qint64 received, qint64 total)
{
    if(total <=0){
        slotError();
        return;
    }
    ppb->setValue(100*received / total);
}

void MainWindow::slotDone(const QUrl &url, const QByteArray &ba)
{
    QFile file(url.path().section('/', -1));
    if(file.open(QIODevice::WriteOnly)){
        file.write(ba);
    }
    showPic(file.fileName());
}
