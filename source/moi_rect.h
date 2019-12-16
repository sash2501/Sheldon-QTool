#ifndef MOI_RECT_H
#define MOI_RECT_H

#include <QDialog>

namespace Ui {
class moi_rect;
}

class moi_rect : public QDialog
{
    Q_OBJECT

public:
    explicit moi_rect(QWidget *parent = 0);
    ~moi_rect();

    void addPoint(double x, double y);
    void plot();
    void drawrect();

private slots:
    void on_btn_findRect_moi_clicked();

private:
    Ui::moi_rect *ui;

    QVector<double> qv_x, qv_y;
    double Bx,By,Dx,Dy;
};

#endif // MOI_RECT_H
