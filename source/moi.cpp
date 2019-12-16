#include "moi.h"
#include "ui_moi.h"

MOI::MOI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MOI)
{
    ui->setupUi(this);

    this->setStyleSheet("QWidget{color: black; background-color: green; selection-color: red} QPushButton{color: black; background-color: white; selection-color: red}");
    //this->setStyleSheet("QPushButton{color: black; background-color: white; selection-color: red}");
}

MOI::~MOI()
{
    delete ui;
}

void MOI::on_btn_Cslotmoi_clicked()
{
    moi_cwithslot = new Moi_cwithslot(this);
    moi_cwithslot->show();

}

void MOI::on_btn_composit_clicked()
{
    moi_composite = new Moi_composite(this);
    moi_composite->show();

}

void MOI::on_btn_rectangle_clicked()
{
    moirect = new moi_rect(this);
    moirect->show();
}

void MOI::on_btn_C_clicked()
{
    moi_c = new Moi_C(this);
    moi_c->show();

}
