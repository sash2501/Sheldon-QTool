#ifndef CENTOID_RECT_H
#define CENTOID_RECT_H

#include <QDialog>
#include<QPainter>

namespace Ui {
class Centoid_rect;
}

class Centoid_rect : public QDialog
{
    Q_OBJECT

public:
    explicit Centoid_rect(QWidget *parent = 0);
    ~Centoid_rect();

    void addPoint(double x, double y);
    void clearData();
    void plot();
    void drawrect();


private slots:
    void on_btn_findRect_centroid_clicked();


private:
    Ui::Centoid_rect *ui;

    QVector<double> qv_x, qv_y;
    double Bx,By,Dx,Dy;
};

#endif // CENTOID_RECT_H
