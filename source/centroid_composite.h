#ifndef CENTROID_COMPOSITE_H
#define CENTROID_COMPOSITE_H

#include <QDialog>

namespace Ui {
class Centroid_composite;
}

class Centroid_composite : public QDialog
{
    Q_OBJECT

public:
    explicit Centroid_composite(QWidget *parent = 0);
    ~Centroid_composite();

private slots:
    void on_btn_centroid_cmpst_clicked();

private:
    Ui::Centroid_composite *ui;

    double A1,A2,B1,B2,C1,C2,D1,D2,E1,E2,F1,F2,G1,G2,H1,H2,O1,O2,r;

};

#endif // CENTROID_COMPOSITE_H
