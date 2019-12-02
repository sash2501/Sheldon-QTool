#ifndef CENTROID_H
#define CENTROID_H

#include <QDialog>
#include "centroid_c.h"
#include "centoid_rect.h"
#include "centroid_cwithslot.h"
#include "centroid_composite.h"

namespace Ui {
class Centroid;
}

class Centroid : public QDialog
{
    Q_OBJECT

public:
    explicit Centroid(QWidget *parent = 0);
    ~Centroid();

private slots:
    void on_centroid_c_secn_clicked();

    void on_centroid_rect_clicked();

    void on_centroid_cslot_clicked();

    void on_btn_centroid_composite_clicked();

private:
    Ui::Centroid *ui;
    Centroid_c *centroid_c;
    Centoid_rect *centroid_rect;
    Centroid_Cwithslot *centroid_Cwithslot;
    Centroid_composite *centroid_composite;
};

#endif // CENTROID_H
