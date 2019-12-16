#ifndef MOI_H
#define MOI_H

#include <QDialog>
#include"moi_cwithslot.h"
#include "moi_composite.h"
#include "moi_rect.h"
#include "moi_c.h"

namespace Ui {
class MOI;
}

class MOI : public QDialog
{
    Q_OBJECT

public:
    explicit MOI(QWidget *parent = 0);
    ~MOI();

    void addPoint(double x, double y);
    void plot();
    void plotCslot(double A1s, double A2s,double B1s, double B2s,double C1s, double C2s,double D1s, double D2s, double M1,double M2 , double N1 , double N2);


private slots:
    void on_btn_Cslotmoi_clicked();

    void on_btn_composit_clicked();

    void on_btn_rectangle_clicked();

    void on_btn_C_clicked();

private:
    Ui::MOI *ui;

    Moi_cwithslot *moi_cwithslot;
    Moi_composite *moi_composite;
    moi_rect *moirect;
    Moi_C *moi_c;
};

#endif // MOI_H
