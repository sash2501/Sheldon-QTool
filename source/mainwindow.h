#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "centroid.h"
#include "moi.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_centroid_clicked();

    void on_btn_MOI_clicked();

private:
    Ui::MainWindow *ui;
    Centroid *centroid;
    MOI *moi;
};

#endif // MAINWINDOW_H
