#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // w.setStyleSheet("QMainWindow {background-color: rgb(170, 170, 125);font: 700 10pt \"Consolas\";}");

    return a.exec();
}
