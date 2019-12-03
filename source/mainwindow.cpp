#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet("QMainWindow{color: white; background-color: black; selection-color: red} QPushButton{color: black; background-color: white; selection-color: red} QLabel { color : white }  ");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_centroid_clicked()
{
    centroid = new Centroid(this);
    centroid->show();
}

void MainWindow::on_btn_MOI_clicked()
{
    moi = new MOI(this);
    moi->show();
}
