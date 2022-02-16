#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <infowindow.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
    void on_btnA_clicked();
    void on_btnB_clicked();
    void on_btnC_clicked();
    void on_btnH_clicked();
    void on_btnCalc_clicked();
    void on_btnClr_clicked();
    void saveDataToFile();

private:
    Ui::MainWindow *ui;
    InfoWindow *infW;

protected:
    double sa, sb, sc, h, area, semiper;
    uint32_t precision, uses;
    QString type;

private slots:
    void on_actionLearn_about_the_developer_triggered();
    void on_actionQuit_triggered();
    void on_actionView_Data_triggered();
    void on_actionSave_triggered();
};
#endif // MAINWINDOW_H
