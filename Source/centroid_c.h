#ifndef CENTROID_C_H
#define CENTROID_C_H

#include <QDialog>

namespace Ui {
class Centroid_c;
}

class Centroid_c : public QDialog
{
    Q_OBJECT

public:
    explicit Centroid_c(QWidget *parent = 0);
    ~Centroid_c();

    void addPoint(double x, double y);
    void clearData();
    void plot();
    void plotrect(double A1, double A2,double B1, double B2,double C1, double C2,double D1, double D2);


private slots:
    void on_btn_findC_centroid_clicked();

private:
    Ui::Centroid_c *ui;

    QVector<double> qv_x, qv_y;
    double Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
};

#endif // CENTROID_C_H
