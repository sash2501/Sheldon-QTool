#include "centroid_c.h"
#include "ui_centroid_c.h"

Centroid_c::Centroid_c(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Centroid_c)
{
    ui->setupUi(this);
    ui->plot->setInteraction(QCP::iRangeDrag,true);
    ui->plot->setInteraction(QCP::iRangeZoom,true);
    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);

    this->setStyleSheet("QLineEdit { border: 2px solid black; background-color : white; color : black } QLabel { color : white } QPushButton{background:rgb(153,255,255); color : red }");



}

Centroid_c::~Centroid_c()
{
    delete ui;
}

void Centroid_c::addPoint(double x, double y)
{

        qv_x.append(x);
        qv_y.append(y);

}

void Centroid_c::clearData()
{
    qv_x.clear();
    qv_y.clear();
}

void Centroid_c::plot()
{
    ui->plot->graph(0)->setData(qv_x,qv_y);
    ui->plot->replot();
    ui->plot->update();
}

void Centroid_c::plotrect(double A1, double A2, double B1, double B2, double C1, double C2, double D1, double D2)
{
    //rectangle1
    QCPItemLine *line1 = new QCPItemLine(ui->plot);
    line1->setPen(QPen(Qt::green));
    line1->start->setCoords(A1,A2);
    line1->end->setCoords(B1,A2);
    QCPItemLine *line2 = new QCPItemLine(ui->plot);
    line2->setPen(QPen(Qt::blue));
    line2->start->setCoords(B1,A2);
    line2->end->setCoords(B1,B2);
    QCPItemLine *line3 = new QCPItemLine(ui->plot);
    line3->setPen(QPen(Qt::red));
    line3->start->setCoords(B1,B2);
    line3->end->setCoords(A1,B2);
    QCPItemLine *line4 = new QCPItemLine(ui->plot);
    line4->setPen(QPen(Qt::black));
    line4->start->setCoords(A1,B2);
    line4->end->setCoords(A1,A2);


    //rectangle2
    QCPItemLine *line5 = new QCPItemLine(ui->plot);
    line5->setPen(QPen(Qt::green));
    line5->start->setCoords(C1,B2);
    line5->end->setCoords(B1,B2);
    QCPItemLine *line6 = new QCPItemLine(ui->plot);
    line6->setPen(QPen(Qt::blue));
    line6->start->setCoords(B1,B2);
    line6->end->setCoords(B1,C2);
    QCPItemLine *line7 = new QCPItemLine(ui->plot);
    line7->setPen(QPen(Qt::red));
    line7->start->setCoords(B1,C2);
    line7->end->setCoords(C1,C2);
    QCPItemLine *line8 = new QCPItemLine(ui->plot);
    line8->setPen(QPen(Qt::black));
    line8->start->setCoords(C1,C2);
    line8->end->setCoords(C1,B2);

    //rectangle3
    QCPItemLine *line9 = new QCPItemLine(ui->plot);
    line9->setPen(QPen(Qt::green));
    line9->start->setCoords(D1,D2);
    line9->end->setCoords(C1,D2);
    QCPItemLine *line10 = new QCPItemLine(ui->plot);
    line10->setPen(QPen(Qt::blue));
    line10->start->setCoords(C1,D2);
    line10->end->setCoords(C1,C2);
    QCPItemLine *line11 = new QCPItemLine(ui->plot);
    line11->setPen(QPen(Qt::red));
    line11->start->setCoords(C1,C2);
    line11->end->setCoords(D1,C2);
    QCPItemLine *line12 = new QCPItemLine(ui->plot);
    line12->setPen(QPen(Qt::black));
    line12->start->setCoords(D1,C2);
    line12->end->setCoords(D1,D2);
}



void Centroid_c::on_btn_findC_centroid_clicked()
{
    QString Oxtext =ui->OriginC_x->text();
     double Ox= Oxtext.toDouble();
    QString Oytext =ui->OriginC_y->text();
     double Oy=Oytext.toDouble();
    QString Axtext =ui->A_x->text();
    Ax= Axtext.toDouble()-Ox;
    QString Aytext =ui->A_y->text();
    Ay=Aytext.toDouble()-Oy;
    QString Bxtext =ui->B_x->text();
    Bx= Bxtext.toDouble()-Ox;
    QString Bytext =ui->B_y->text();
    By=Bytext.toDouble()-Oy;
    QString Cxtext =ui->C_x->text();
    Cx= Cxtext.toDouble()-Ox;
    QString Cytext =ui->C_y->text();
    Cy=Cytext.toDouble()-Oy;
    QString Dxtext =ui->D_x->text();
    Dx= Dxtext.toDouble()-Ox;
    QString Dytext =ui->D_y->text();
    Dy=Dytext.toDouble()-Oy;

    addPoint(Ax,Ay);
    addPoint(Bx,By);
    addPoint(Cx,Cy);
    addPoint(Dx,Dy);
    addPoint(Ox,Oy);
    plot();
    plotrect(Ax,Ay,Bx,By,Cx,Cy,Dx,Dy);


    //rectangle1
    double breadth1=Ax-Bx;
    double length1= Ay-By;

   double x1centroid;
   double y1centroid;
    if (breadth1<0)
           { breadth1=-breadth1;
           x1centroid=(breadth1/2)+Ax;}
    else
        x1centroid=(breadth1/2)+Bx;

    if (length1<0)
           { length1=-length1;
           y1centroid=(length1/2)+Ay;}
    else
        y1centroid=(length1/2)+By;
    addPoint(x1centroid,y1centroid);
    plot();

    //rectangle2

    double breadth2=Cx-Bx;
    double length2= By-Cy;

   double x2centroid;
   double y2centroid;
    if (breadth2<0)
           { breadth2=-breadth2;
           x2centroid=(breadth2/2)+Cx;}
    else
        x2centroid=(breadth2/2)+Bx;

    if (length2<0)
           { length2=-length2;
           y2centroid=(length2/2)+By;}
    else
        y2centroid=(length2/2)+Cy;
    addPoint(x2centroid,y2centroid);
    plot();

    //rectangle3

    double breadth3=Dx-Cx;
    double length3= Dy-Cy;

   double x3centroid;
   double y3centroid;
    if (breadth3<0)
           { breadth3=-breadth3;
           x3centroid=(breadth3/2)+Dx;}
    else
        x3centroid=(breadth3/2)+Cx;

    if (length3<0)
           { length3=-length3;
           y3centroid=(length3/2)+Dy;}
    else
        y3centroid=(length3/2)+Cy;
    addPoint(x3centroid,y3centroid);
    plot();

//finding total centroid
    double area1, area2, area3;
    area1=length1*breadth1;
    area2=length2*breadth2;
    area3=length3*breadth3;
    double totalCx= ((x1centroid*area1)+(x2centroid*area2)+(x3centroid*area3))/(area1+area2+area3);
    double totalCy= ((y1centroid*area1)+(y2centroid*area2)+(y3centroid*area3))/(area1+area2+area3);

    addPoint(totalCx,totalCy);
    plot();

    QString resultString = "";
    ui->print_Cx->setText(resultString.setNum(totalCx));
    ui->print_Cy->setText(resultString.setNum(totalCy));






}
