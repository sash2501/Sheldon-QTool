#ifndef MOI_COMPOSITE_H
#define MOI_COMPOSITE_H

#include <QDialog>

namespace Ui {
class Moi_composite;
}

class Moi_composite : public QDialog
{
    Q_OBJECT

public:
    explicit Moi_composite(QWidget *parent = 0);
    ~Moi_composite();

private slots:
    void on_btn_moi_cmpst_clicked();

private:
    Ui::Moi_composite *ui;
     double A1m,A2m,B1m,B2m,C1m,C2m,D1m,D2m,E1m,E2m,F1m,F2m,G1m,G2m,H1m,H2m,O1m,O2m,rd;
};

#endif // MOI_COMPOSITE_H
