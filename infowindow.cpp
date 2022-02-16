#include "infowindow.h"
#include "ui_infowindow.h"
#include "QPixmap"


InfoWindow::InfoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoWindow){
        ui -> setupUi(this);

        QPixmap img("infoImg.jpg");
        ui -> lblImg -> setPixmap(img);
}

InfoWindow::~InfoWindow(){
    delete ui;
}
