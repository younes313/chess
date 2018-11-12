#include "mainwindow.h"
//#include
#include <QApplication>
//#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QDesktopWidget dw;
    MainWindow w;
//    w.centralWidget()->


    w.setFixedSize(1000,900);
    w.show();

    return a.exec();
}
