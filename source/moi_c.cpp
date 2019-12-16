#include "moi_c.h"
#include "ui_moi_c.h"

Moi_C::Moi_C(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Moi_C)
{
    ui->setupUi(this);

    ui->cmoiplot->setInteraction(QCP::iRangeDrag,true);
    ui->cmoiplot->setInteraction(QCP::iRangeZoom,true);
    ui->cmoiplot->addGraph();
    ui->cmoiplot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->cmoiplot->graph(0)->setLineStyle(QCPGraph::lsNone);

   // ui->moi_Cx->setStyleSheet("QLabel { background-color : red; color : blue; }");

    this->setStyleSheet("QLineEdit { border: 2px solid black; background-color : white; color : black } QLabel { color : white } QPushButton{background:rgb(153,255,153); color : red }");
    // this->setStyleSheet("color: black; background-color: green; selection-color: red");
}

Moi_C::~Moi_C()
{
    delete ui;
}

void Moi_C::addPoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
}

void Moi_C::plot()
{
    ui->cmoiplot->graph(0)->setData(qv_x,qv_y);
    ui->cmoiplot->replot();
    ui->cmoiplot->update();
}

void Moi_C::plotMoiC(double A1m, double A2m, double B1m, double B2m, double C1m, double C2m, double D1m, double D2m)
{

    //rectangle1
    QCPItemLine *line1 = new QCPItemLine(ui->cmoiplot);
    line1->setPen(QPen(Qt::green));
    line1->start->setCoords(A1m,A2m);
    line1->end->setCoords(B1m,A2m);
    QCPItemLine *line2 = new QCPItemLine(ui->cmoiplot);
    line2->setPen(QPen(Qt::blue));
    line2->start->setCoords(B1m,A2m);
    line2->end->setCoords(B1m,B2m);
    QCPItemLine *line3 = new QCPItemLine(ui->cmoiplot);
    line3->setPen(QPen(Qt::red));
    line3->start->setCoords(B1m,B2m);
    line3->end->setCoords(A1m,B2m);
    QCPItemLine *line4 = new QCPItemLine(ui->cmoiplot);
    line4->setPen(QPen(Qt::black));
    line4->start->setCoords(A1m,B2m);
    line4->end->setCoords(A1m,A2m);


    //rectangle2
    QCPItemLine *line5 = new QCPItemLine(ui->cmoiplot);
    line5->setPen(QPen(Qt::green));
    line5->start->setCoords(C1m,B2m);
    line5->end->setCoords(B1m,B2m);
    QCPItemLine *line6 = new QCPItemLine(ui->cmoiplot);
    line6->setPen(QPen(Qt::blue));
    line6->start->setCoords(B1m,B2m);
    line6->end->setCoords(B1m,C2m);
    QCPItemLine *line7 = new QCPItemLine(ui->cmoiplot);
    line7->setPen(QPen(Qt::red));
    line7->start->setCoords(B1m,C2m);
    line7->end->setCoords(C1m,C2m);
    QCPItemLine *line8 = new QCPItemLine(ui->cmoiplot);
    line8->setPen(QPen(Qt::black));
    line8->start->setCoords(C1m,C2m);
    line8->end->setCoords(C1m,B2m);

    //rectangle3
    QCPItemLine *line9 = new QCPItemLine(ui->cmoiplot);
    line9->setPen(QPen(Qt::green));
    line9->start->setCoords(D1m,D2m);
    line9->end->setCoords(C1m,D2m);
    QCPItemLine *line10 = new QCPItemLine(ui->cmoiplot);
    line10->setPen(QPen(Qt::blue));
    line10->start->setCoords(C1m,D2m);
    line10->end->setCoords(C1m,C2m);
    QCPItemLine *line11 = new QCPItemLine(ui->cmoiplot);
    line11->setPen(QPen(Qt::red));
    line11->start->setCoords(C1m,C2m);
    line11->end->setCoords(D1m,C2m);
    QCPItemLine *line12 = new QCPItemLine(ui->cmoiplot);
    line12->setPen(QPen(Qt::black));
    line12->start->setCoords(D1m,C2m);
    line12->end->setCoords(D1m,D2m);

 }


void Moi_C::on_btn_findC_moi_clicked()
{
    QString Oxtext =ui->OriginCm_x->text();
     double Omx= Oxtext.toDouble();
    QString Oytext =ui->OriginCm_y->text();
     double Omy=Oytext.toDouble();
    QString Axtext =ui->Am_x->text();
    Amoix= Axtext.toDouble()-Omx;
    QString Aytext =ui->Am_y->text();
    Amoiy=Aytext.toDouble()-Omy;
    QString Bxtext =ui->Bm_x->text();
    Bmoix= Bxtext.toDouble()-Omx;
    QString Bytext =ui->Bm_y->text();
    Bmoiy=Bytext.toDouble()-Omy;
    QString Cxtext =ui->Cm_x->text();
    Cmoix= Cxtext.toDouble()-Omx;
    QString Cytext =ui->Cm_y->text();
    Cmoiy=Cytext.toDouble()-Omy;
    QString Dxtext =ui->Dm_x->text();
    Dmoix= Dxtext.toDouble()-Omx;
    QString Dytext =ui->Dm_y->text();
    Dmoiy=Dytext.toDouble()-Omy;




    addPoint(Amoix,Amoiy);
    addPoint(Bmoix,Bmoiy);
    addPoint(Cmoix,Cmoiy);
    addPoint(Dmoix,Dmoiy);
    addPoint(Omx,Omy);


    plot();
    plotMoiC(Amoix,Amoiy,Bmoix,Bmoiy,Cmoix,Cmoiy,Dmoix,Dmoiy);



    //rectangle1
    double breadth1=Amoix-Bmoix;
    double length1= Amoiy-Bmoiy;

    double area1;
    area1=length1*breadth1;

   double x1centroid;
   double y1centroid;
    if (breadth1<0)
           { breadth1=-breadth1;
           x1centroid=(breadth1/2)+Amoix;}
    else
        x1centroid=(breadth1/2)+Bmoix;

    if (length1<0)
           { length1=-length1;
           y1centroid=(length1/2)+Amoiy;}
    else
        y1centroid=(length1/2)+Bmoiy;
    addPoint(x1centroid,y1centroid);
    plot();
    double dx1= y1centroid-Omy;
    double dy1= x1centroid-Omx;
    double Ix1= (breadth1*length1*length1*length1)/12;
    double Iy1= (length1*breadth1*breadth1*breadth1)/12;
    double IX1 =  Ix1+(area1*(dx1 * dx1));
    double IY1=    Iy1+(area1*(dy1*dy1));



    //rectangle2

    double breadth2=Cmoix-Bmoix;
    double length2= Bmoiy-Cmoiy;

    double area2=length2*breadth2;

   double x2centroid;
   double y2centroid;
    if (breadth2<0)
           { breadth2=-breadth2;
           x2centroid=(breadth2/2)+Cmoix;}
    else
        x2centroid=(breadth2/2)+Bmoix;

    if (length2<0)
           { length2=-length2;
           y2centroid=(length2/2)+Bmoiy;}
    else
        y2centroid=(length2/2)+Cmoiy;
    addPoint(x2centroid,y2centroid);
    plot();

    double dx2= y2centroid-Omy;
    double dy2= x2centroid-Omx;
    double Ix2= (breadth2*length2*length2*length2)/12;
    double Iy2= (length2*breadth2*breadth2*breadth2)/12;
    double IX2 =  Ix2+(area2*(dx2 * dx2));
    double IY2=    Iy2+(area2*(dy2*dy2));


    //rectangle3



    double breadth3=Dmoix-Cmoix;
    double length3= Dmoiy-Cmoiy;

    double area3=length3*breadth3;

   double x3centroid;
   double y3centroid;
    if (breadth3<0)
           { breadth3=-breadth3;
           x3centroid=(breadth3/2)+Dmoix;}
    else
        x3centroid=(breadth3/2)+Cmoix;

    if (length3<0)
           { length3=-length3;
           y3centroid=(length3/2)+Dmoiy;}
    else
        y3centroid=(length3/2)+Cmoiy;
    addPoint(x3centroid,y3centroid);
    plot();

    double dx3= y3centroid-Omy;
    double dy3= x3centroid-Omx;
    double Ix3= (breadth3*length3*length3*length3)/12;
    double Iy3= (length3*breadth3*breadth3*breadth3)/12;
    double IX3 =  Ix3+(area3*(dx3 * dx3));
    double IY3=    Iy3+(area3*(dy3*dy3));


    //double CentroidX = ((x1centroid*area1)+(x2centroid*area2)+(x3centroid*area3))/(area1+area2+area3);
    //double CentroidY = ((y1centroid*area1)+(y2centroid*area2)+(y3centroid*area3))/(area1+area2+area3);
    double IX = IX1+IX2+IX3;
    double IY = IY1+IY2+IY3;

    QString resultString = "";
    ui->moi_Cx->setText(resultString.setNum(IX));
    ui->moi_Cy->setText(resultString.setNum(IY));
}


