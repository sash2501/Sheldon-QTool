#ifndef MOI_C_H
#define MOI_C_H

#include <QDialog>

namespace Ui {
class Moi_C;
}

class Moi_C : public QDialog
{
    Q_OBJECT

public:
    explicit Moi_C(QWidget *parent = 0);
    ~Moi_C();

private slots:

    void on_btn_findC_moi_clicked();

    void addPoint(double x, double y);
    void plot();
    void plotMoiC(double A1m, double A2m, double B1m, double B2m, double C1m, double C2m, double D1m, double D2m);


private:
    Ui::Moi_C *ui;
    QVector<double> qv_x, qv_y;
    double Amoix,Amoiy,Bmoix,Bmoiy,Cmoix,Cmoiy,Dmoix,Dmoiy,Mmoix,Mmoiy,Nmoix,Nmoiy;
};

#endif // MOI_C_H
