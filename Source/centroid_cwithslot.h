#ifndef CENTROID_CWITHSLOT_H
#define CENTROID_CWITHSLOT_H

#include <QDialog>

namespace Ui {
class Centroid_Cwithslot;
}

class Centroid_Cwithslot : public QDialog
{
    Q_OBJECT

public:
    explicit Centroid_Cwithslot(QWidget *parent = 0);
    ~Centroid_Cwithslot();

    void addPoint(double x, double y);
    void plot();
    void plotCslot(double A1s, double A2s,double B1s, double B2s,double C1s, double C2s,double D1s, double D2s, double M1,double M2 , double N1 , double N2);

private slots:
    void on_btn_findCslot_centroid_clicked();

private:
    Ui::Centroid_Cwithslot *ui;

     QVector<double> qv_x, qv_y;
     double Asx,Asy,Bsx,Bsy,Csx,Csy,Dsx,Dsy,Mx,My,Nx,Ny;
};

#endif // CENTROID_CWITHSLOT_H
