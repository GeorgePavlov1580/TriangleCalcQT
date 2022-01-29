#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
#include <cmath>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    ui -> tick1 -> setEnabled(false);
    ui -> tick2 -> setEnabled(false);
    ui -> tick3 -> setEnabled(false);
    ui -> tick4 -> setEnabled(false);

    uses = 0;
//    QLabel label;
//    label.setText("we");
//    label.setStyleSheet("background-image: url(:/images/assets/your.png)");
//    label.show();
}


MainWindow::~MainWindow(){
    delete ui;
}


std::string determineType(double a, double b, double c){
    double tmp(pow(a, 2) + pow(b, 2)), newC(pow(c, 2));

    if(newC == tmp)
        return "Rectangular";
    else if(newC < tmp)
        return "Acute-angled";
    else if(newC > tmp)
        return "Obtuse";
}


double calcArea(double a, double b, double c){
    double semiper = (a + b + c) / 2.0;
    return sqrt(semiper * (semiper - a) * (semiper - b) * (semiper - c));
}


double calcPerimeter(double a, double b, double c){return a + b + c;}


bool preCheckAll(double a, double b, double c){
    if((a + b > c) &&
       (a + c > b) &&
       (b + c > a) &&
       (a && b && c)) return true;
               else return false;
}


bool preCheckSide(double side){return side <= 0 ? false : true;}


bool preCheckPrecision(uint32_t p){return !p ? false : true;}


void MainWindow::on_btnA_clicked(){
    sa = ui -> entr1 -> value();

    if(preCheckSide(sa)){
        ui -> tick1 -> setEnabled(true);
        ui -> tick1 -> setChecked(true);
        ui -> tick1 -> setEnabled(false);
    }else{
        ui -> tick1 -> setEnabled(true);
        ui -> tick1 -> setChecked(false);
        ui -> tick1 -> setEnabled(false);
    }
}


void MainWindow::on_btnB_clicked(){
    sb = ui -> entr2 -> value();
    if(preCheckSide(sb)){
        ui -> tick2 -> setEnabled(true);
        ui -> tick2 -> setChecked(true);
        ui -> tick2 -> setEnabled(false);
    }else{
        ui -> tick2 -> setEnabled(true);
        ui -> tick2 -> setChecked(false);
        ui -> tick2 -> setEnabled(false);
    }
}


void MainWindow::on_btnC_clicked(){
    sc = ui -> entr3 -> value();

    if(preCheckSide(sc)){
        ui -> tick3 -> setEnabled(true);
        ui -> tick3 -> setChecked(true);
        ui -> tick3 -> setEnabled(false);
    }else{
        ui -> tick3 -> setEnabled(true);
        ui -> tick3 -> setChecked(false);
        ui -> tick3 -> setEnabled(false);
    }
}


void MainWindow::on_btnH_clicked(){
    precision = ui -> entr4 -> value();

    //if(preCheckPrecision(precision)){
    ui -> tick4 -> setEnabled(true);
    ui -> tick4 -> setChecked(true);
    ui -> tick4 -> setEnabled(false);
//    }else{
//        ui -> tick4 -> setEnabled(true);
//        ui -> tick4 -> setChecked(false);
//        ui -> tick4 -> setEnabled(false);
//    }
}


void MainWindow::on_btnCalc_clicked(){
    if(preCheckAll(sa, sb, sc)){
        ui -> lblPer -> setText(QString::number(calcPerimeter(sa, sb, sc), 'f', precision));
        ui -> lblAr  -> setText(QString::number(calcArea(sa, sb, sc), 'f', precision));
        ui -> lblTp  -> setText(QString::fromStdString(determineType(sa, sb, sc)));
        ++ uses;
        ui -> lblUses -> setText(QString("Successful calculations: %1").arg(uses));
    }else{
        ui -> lblTp -> setText("Impossible");
        QMessageBox::critical(this, " Error", "Triangle with such sides is impossible!");
    }
}


void MainWindow::on_btnClr_clicked(){
    sa = 0.0;
    sb = 0.0;
    sc = 0.0;
    h  = 0.0;
    precision = 4;

    ui -> entr1  -> setValue(0.0);
    ui -> entr2  -> setValue(0.0);
    ui -> entr3  -> setValue(0.0);
    ui -> entr4  -> setValue(4);
    ui -> lblPer -> setText("No data");
    ui -> lblAr  -> setText("No data");
    ui -> lblTp  -> setText("No data");

    ui -> tick1 -> setEnabled(true);
    ui -> tick1 -> setChecked(false);
    ui -> tick1 -> setEnabled(false);

    ui -> tick2 -> setEnabled(true);
    ui -> tick2 -> setChecked(false);
    ui -> tick2 -> setEnabled(false);

    ui -> tick3 -> setEnabled(true);
    ui -> tick3 -> setChecked(false);
    ui -> tick3 -> setEnabled(false);

    ui -> tick4 -> setEnabled(true);
    ui -> tick4 -> setChecked(false);
    ui -> tick4 -> setEnabled(false);
}

