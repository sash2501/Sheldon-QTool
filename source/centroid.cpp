#include "centroid.h"
#include "ui_centroid.h"

Centroid::Centroid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Centroid)
{
    ui->setupUi(this);
    this->setStyleSheet("QWidget{color: black; background-color: orange; selection-color: red} QPushButton{color: black; background-color: white; selection-color: red}");

}

Centroid::~Centroid()
{
    delete ui;
}

void Centroid::on_centroid_c_secn_clicked()
{
    centroid_c = new Centroid_c(this);
    centroid_c->show();
}

void Centroid::on_centroid_rect_clicked()
{
    centroid_rect = new Centoid_rect(this);
    centroid_rect->show();
}

void Centroid::on_centroid_cslot_clicked()
{
    centroid_Cwithslot = new Centroid_Cwithslot(this);
    centroid_Cwithslot->show();
}

void Centroid::on_btn_centroid_composite_clicked()
{
    centroid_composite = new Centroid_composite(this);
    centroid_composite->show();
}
