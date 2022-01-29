#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // double sa, sb, sc, h, area, perimeter, semiper;

protected slots:
    void on_btnA_clicked();

    void on_btnB_clicked();

    void on_btnC_clicked();

    void on_btnH_clicked();

    void on_btnCalc_clicked();

    void on_btnClr_clicked();

private:
    Ui::MainWindow *ui;

protected:
    double sa, sb, sc, h, area, semiper;
    uint32_t precision, uses;
    QString type;
};
#endif // MAINWINDOW_H
