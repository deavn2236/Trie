#include "mainwindow.h"
#include <QApplication>
#include "welcomedialog.h"
#include <QThread>
#include<QTimer>
#include <QEventLoop>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    WelcomeDialog wel;
    wel.show();
    QEventLoop eventloop;
    QTimer::singleShot(2000, &eventloop, SLOT(quit())); //wait 2s
    eventloop.exec();
    wel.close();
    w.show();

    return a.exec();
}
