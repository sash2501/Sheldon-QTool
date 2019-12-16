#include "centoid_rect.h"
#include "ui_centoid_rect.h"

Centoid_rect::Centoid_rect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Centoid_rect)
{
    ui->setupUi(this);

    ui->rectplot->setInteraction(QCP::iRangeDrag,true);
    ui->rectplot->setInteraction(QCP::iRangeZoom,true);
    ui->rectplot->addGraph();
    ui->rectplot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->rectplot->graph(0)->setLineStyle(QCPGraph::lsNone);

    this->setStyleSheet("QLineEdit { border: 2px solid black; background-color : white; color : black } QLabel { color : white } QPushButton{background:rgb(153,255,255); color : red }");


}

Centoid_rect::~Centoid_rect()
{
    delete ui;
}

void Centoid_rect::addPoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);

}

void Centoid_rect::clearData()
{
    Bx=0;
    By=0;
    Dx=0;
    Dy=0;
    qv_x.clear();
    qv_y.clear();


}

void Centoid_rect::plot()
{
    ui->rectplot->graph(0)->setData(qv_x,qv_y);
    ui->rectplot->replot();
    ui->rectplot->update();



}

void Centoid_rect::drawrect()
{

    QCPItemLine *linea = new QCPItemLine(ui->rectplot);
    linea->setPen(QPen(Qt::blue));
    linea->start->setCoords(Bx,Dy);
    linea->end->setCoords(Bx,By);
    QCPItemLine *lineb = new QCPItemLine(ui->rectplot);
    lineb->setPen(QPen(Qt::red));
    lineb->start->setCoords(Bx,By);
    lineb->end->setCoords(Dx,By);
    QCPItemLine *linec = new QCPItemLine(ui->rectplot);
    linec->setPen(QPen(Qt::black));
    linec->start->setCoords(Dx,By);
    linec->end->setCoords(Dx,Dy);
    QCPItemLine *lined = new QCPItemLine(ui->rectplot);
    lined->setPen(QPen(Qt::green));
    lined->start->setCoords(Dx,Dy);
    lined->end->setCoords(Bx,Dy);
}



void Centoid_rect::on_btn_findRect_centroid_clicked()
{
    QString Oxtext =ui->Originrect_x->text();
     double Ox= Oxtext.toDouble();
    QString Oytext =ui->Originrect_y->text();
     double Oy=Oytext.toDouble();
    QString Bxtext =ui->Brect_x->text();
     Bx= Bxtext.toDouble()-Ox;
    QString Bytext =ui->Brect_y->text();
     By=Bytext.toDouble()-Oy;
    QString Dxtext =ui->Drect_x->text();
     Dx= Dxtext.toDouble()-Ox;
    QString Dytext =ui->Drect_y->text();
     Dy=Dytext.toDouble()-Oy;



     addPoint(Bx,By);
     addPoint(Dx,Dy);
     addPoint(Ox,Oy);
     plot();
     drawrect();



     double length=Bx-Dx;

     double breadth= By-Dy;



    double xcentroid;
    double ycentroid;
     if (breadth<0)
            { breadth=-breadth;
            ycentroid=(breadth/2)+By;}
     else
         ycentroid=(breadth/2)+Dy;

     if (length<0)
            { length=-length;
            xcentroid=(length/2)+Bx;}
     else
         xcentroid=(length/2)+Dx;

     addPoint(xcentroid,ycentroid);
     plot();

     QString resultString = "";
     ui->print_rectx->setText(resultString.setNum(xcentroid));
     ui->print_recty->setText(resultString.setNum(ycentroid));

}


