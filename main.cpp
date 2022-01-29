#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setStyleSheet("QMainWindow {background: 'lime';}");

    return a.exec();
}
