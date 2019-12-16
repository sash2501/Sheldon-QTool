#ifndef MOI_CWITHSLOT_H
#define MOI_CWITHSLOT_H

#include <QDialog>

namespace Ui {
class Moi_cwithslot;
}

class Moi_cwithslot : public QDialog
{
    Q_OBJECT

public:
    explicit Moi_cwithslot(QWidget *parent = 0);
    ~Moi_cwithslot();

    void addPoint(double x, double y);
    void plot();
    void plotMoislot(double A1m, double A2m,double B1m, double B2m,double C1m, double C2m,double D1m, double D2m, double M1m,double M2m , double N1m , double N2m);


private slots:
    void on_btn_findCslot_moi_clicked();

private:
    Ui::Moi_cwithslot *ui;

    QVector<double> qv_x, qv_y;
    double Amx,Amy,Bmx,Bmy,Cmx,Cmy,Dmx,Dmy,Mmx,Mmy,Nmx,Nmy;
};

#endif // MOI_CWITHSLOT_H
