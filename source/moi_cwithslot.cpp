#include "moi_cwithslot.h"
#include "ui_moi_cwithslot.h"

Moi_cwithslot::Moi_cwithslot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Moi_cwithslot)
{
    ui->setupUi(this);

    ui->moislotplot->setInteraction(QCP::iRangeDrag,true);
    ui->moislotplot->setInteraction(QCP::iRangeZoom,true);
    ui->moislotplot->addGraph();
    ui->moislotplot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->moislotplot->graph(0)->setLineStyle(QCPGraph::lsNone);

    this->setStyleSheet("QLineEdit { border: 2px solid black; background-color : white; color : black } QLabel { color : white } QPushButton{background:rgb(153,255,153); color : red }");

}

Moi_cwithslot::~Moi_cwithslot()
{
    delete ui;
}

void Moi_cwithslot::addPoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
}

void Moi_cwithslot::plot()
{
    ui->moislotplot->graph(0)->setData(qv_x,qv_y);
    ui->moislotplot->replot();
    ui->moislotplot->update();
}

void Moi_cwithslot::plotMoislot(double A1m, double A2m, double B1m, double B2m, double C1m, double C2m, double D1m, double D2m, double M1m, double M2m, double N1m, double N2m)
{

    //rectangle1
    QCPItemLine *line1 = new QCPItemLine(ui->moislotplot);
    line1->setPen(QPen(Qt::green));
    line1->start->setCoords(A1m,A2m);
    line1->end->setCoords(B1m,A2m);
    QCPItemLine *line2 = new QCPItemLine(ui->moislotplot);
    line2->setPen(QPen(Qt::blue));
    line2->start->setCoords(B1m,A2m);
    line2->end->setCoords(B1m,B2m);
    QCPItemLine *line3 = new QCPItemLine(ui->moislotplot);
    line3->setPen(QPen(Qt::red));
    line3->start->setCoords(B1m,B2m);
    line3->end->setCoords(A1m,B2m);
    QCPItemLine *line4 = new QCPItemLine(ui->moislotplot);
    line4->setPen(QPen(Qt::black));
    line4->start->setCoords(A1m,B2m);
    line4->end->setCoords(A1m,A2m);


    //rectangle2
    QCPItemLine *line5 = new QCPItemLine(ui->moislotplot);
    line5->setPen(QPen(Qt::green));
    line5->start->setCoords(C1m,B2m);
    line5->end->setCoords(B1m,B2m);
    QCPItemLine *line6 = new QCPItemLine(ui->moislotplot);
    line6->setPen(QPen(Qt::blue));
    line6->start->setCoords(B1m,B2m);
    line6->end->setCoords(B1m,C2m);
    QCPItemLine *line7 = new QCPItemLine(ui->moislotplot);
    line7->setPen(QPen(Qt::red));
    line7->start->setCoords(B1m,C2m);
    line7->end->setCoords(C1m,C2m);
    QCPItemLine *line8 = new QCPItemLine(ui->moislotplot);
    line8->setPen(QPen(Qt::black));
    line8->start->setCoords(C1m,C2m);
    line8->end->setCoords(C1m,B2m);

    //rectangle3
    QCPItemLine *line9 = new QCPItemLine(ui->moislotplot);
    line9->setPen(QPen(Qt::green));
    line9->start->setCoords(D1m,D2m);
    line9->end->setCoords(C1m,D2m);
    QCPItemLine *line10 = new QCPItemLine(ui->moislotplot);
    line10->setPen(QPen(Qt::blue));
    line10->start->setCoords(C1m,D2m);
    line10->end->setCoords(C1m,C2m);
    QCPItemLine *line11 = new QCPItemLine(ui->moislotplot);
    line11->setPen(QPen(Qt::red));
    line11->start->setCoords(C1m,C2m);
    line11->end->setCoords(D1m,C2m);
    QCPItemLine *line12 = new QCPItemLine(ui->moislotplot);
    line12->setPen(QPen(Qt::black));
    line12->start->setCoords(D1m,C2m);
    line12->end->setCoords(D1m,D2m);

    //slot
    QCPItemLine *line13 = new QCPItemLine(ui->moislotplot);
    line13->setPen(QPen(Qt::green));
    line13->start->setCoords(M1m,M2m);
    line13->end->setCoords(N1m,M2m);
    QCPItemLine *line14 = new QCPItemLine(ui->moislotplot);
    line14->setPen(QPen(Qt::blue));
    line14->start->setCoords(N1m,M2m);
    line14->end->setCoords(N1m,N2m);
    QCPItemLine *line15 = new QCPItemLine(ui->moislotplot);
    line15->setPen(QPen(Qt::red));
    line15->start->setCoords(N1m,N2m);
    line15->end->setCoords(M1m,N2m);
    QCPItemLine *line16 = new QCPItemLine(ui->moislotplot);
    line16->setPen(QPen(Qt::black));
    line16->start->setCoords(M1m,N2m);
    line16->end->setCoords(M1m,M2m);

}

void Moi_cwithslot::on_btn_findCslot_moi_clicked()
{
    QString Oxtext =ui->OriginCslotm_x->text();
     double Omx= Oxtext.toDouble();
    QString Oytext =ui->OriginCslotm_y->text();
     double Omy=Oytext.toDouble();
    QString Axtext =ui->Amslot_x->text();
    Amx= Axtext.toDouble()-Omx;
    QString Aytext =ui->Amslot_y->text();
    Amy=Aytext.toDouble()-Omy;
    QString Bxtext =ui->Bmslot_x->text();
    Bmx= Bxtext.toDouble()-Omx;
    QString Bytext =ui->Bmslot_y->text();
    Bmy=Bytext.toDouble()-Omy;
    QString Cxtext =ui->Cmslot_x->text();
    Cmx= Cxtext.toDouble()-Omx;
    QString Cytext =ui->Cmslot_y->text();
    Cmy=Cytext.toDouble()-Omy;
    QString Dxtext =ui->Dmslot_x->text();
    Dmx= Dxtext.toDouble()-Omx;
    QString Dytext =ui->Dmslot_y->text();
    Dmy=Dytext.toDouble()-Omy;


    QString Mxtext =ui->Mm_x->text();
     Mmx= Mxtext.toDouble()-Omx;
    QString Mytext =ui->Mm_y->text();
     Mmy=Mytext.toDouble()-Omy;
    QString Nxtext =ui->Nm_x->text();
     Nmx= Nxtext.toDouble()-Omx;
    QString Nytext =ui->Nm_y->text();
     Nmy=Nytext.toDouble()-Omy;

    addPoint(Amx,Amy);
    addPoint(Bmx,Bmy);
    addPoint(Cmx,Cmy);
    addPoint(Dmx,Dmy);
    addPoint(Omx,Omy);
    addPoint(Mmx,Mmy);
    addPoint(Nmx,Nmy);

    plot();
    plotMoislot(Amx,Amy,Bmx,Bmy,Cmx,Cmy,Dmx,Dmy,Mmx,Mmy,Nmx,Nmy);

    //finding centroid of slot


    //finding total centroid

    double breadth4=Mmx-Nmx;
    double length4= Mmy-Nmy;

    double area4;
    area4=length4*breadth4;

   double x4centroid;
   double y4centroid;
    if (breadth4<0)
           { breadth4=-breadth4;
           x4centroid=(breadth4/2)+Mmx;}
    else
        x4centroid=(breadth4/2)+Nmx;

    if (length4<0)
           { length4=-length4;
           y4centroid=(length4/2)+Mmy;}
    else
        y4centroid=(length4/2)+Nmy;
    addPoint(x4centroid,y4centroid);
    plot();
    double dx4= y4centroid-Omy;
    double dy4= x4centroid-Omx;
    double Ix4= (breadth4*length4*length4*length4)/12;
    double Iy4= (length4*breadth4*breadth4*breadth4)/12;
    double IX4 =  Ix4+(area4*(dx4 * dx4));
    double IY4=    Iy4+(area4*(dy4*dy4));




        //double totalCslotx= ((x1centroid*area1)+(x2centroid*area2)+(x3centroid*area3))/(area1+area2+area3);
        //double totalCsloty= ((y1centroid*area1)+(y2centroid*area2)+(y3centroid*area3))/(area1+area2+area3);

        //addPoint(totalCslotx,totalCsloty);
        //plot();

    //rectangle1
    double breadth1=Amx-Bmx;
    double length1= Amy-Bmy;

    double area1;
    area1=length1*breadth1;

   double x1centroid;
   double y1centroid;
    if (breadth1<0)
           { breadth1=-breadth1;
           x1centroid=(breadth1/2)+Amx;}
    else
        x1centroid=(breadth1/2)+Bmx;

    if (length1<0)
           { length1=-length1;
           y1centroid=(length1/2)+Amy;}
    else
        y1centroid=(length1/2)+Bmy;
    addPoint(x1centroid,y1centroid);
    plot();
    double dx1= y1centroid-Omy;
    double dy1= x1centroid-Omx;
    double Ix1= (breadth1*length1*length1*length1)/12;
    double Iy1= (length1*breadth1*breadth1*breadth1)/12;
    double IX1 =  Ix1+(area1*(dx1 * dx1));
    double IY1=    Iy1+(area1*(dy1*dy1));

    /*%MOI1:
        dx=g1-y;
        dy=h1-x;
        Ix1 = [l1*(b1)^3]/12;
        Iy1 = [l1*(b1)^3]/12;
        IX1 = Ix1+[A1*(dx1)^2]
        IY1 = Iy1+[A1*(dy1)^2]*/

    //rectangle2

    double breadth2=Cmx-Bmx;
    double length2= Bmy-Cmy;

    double area2=length2*breadth2;

   double x2centroid;
   double y2centroid;
    if (breadth2<0)
           { breadth2=-breadth2;
           x2centroid=(breadth2/2)+Cmx;}
    else
        x2centroid=(breadth2/2)+Bmx;

    if (length2<0)
           { length2=-length2;
           y2centroid=(length2/2)+Bmy;}
    else
        y2centroid=(length2/2)+Cmy;
    addPoint(x2centroid,y2centroid);
    plot();

    double dx2= y2centroid-Omy;
    double dy2= x2centroid-Omx;
    double Ix2= (breadth2*length2*length2*length2)/12;
    double Iy2= (length2*breadth2*breadth2*breadth2)/12;
    double IX2 =  Ix2+(area2*(dx2 * dx2));
    double IY2=    Iy2+(area2*(dy2*dy2));


    //rectangle3



    double breadth3=Dmx-Cmx;
    double length3= Dmy-Cmy;

    double area3=length3*breadth3;

   double x3centroid;
   double y3centroid;
    if (breadth3<0)
           { breadth3=-breadth3;
           x3centroid=(breadth3/2)+Dmx;}
    else
        x3centroid=(breadth3/2)+Cmx;

    if (length3<0)
           { length3=-length3;
           y3centroid=(length3/2)+Dmy;}
    else
        y3centroid=(length3/2)+Cmy;
    addPoint(x3centroid,y3centroid);
    plot();

    double dx3= y3centroid-Omy;
    double dy3= x3centroid-Omx;
    double Ix3= (breadth3*length3*length3*length3)/12;
    double Iy3= (length3*breadth3*breadth3*breadth3)/12;
    double IX3 =  Ix3+(area3*(dx3 * dx3));
    double IY3=    Iy3+(area3*(dy3*dy3));


    //double CentroidX = ((x1centroid*area1)+(x2centroid*area2)+(x3centroid*area3)-(x4centroid*area4))/(area1+area2+area3-area4);
    //double CentroidY = ((y1centroid*area1)+(y2centroid*area2)+(y3centroid*area3)-(y4centroid*area4))/(area1+area2+area3-area4);

    double IX = IX1+IX2+IX3-IX4;
    double IY = IY1+IY2+IY3-IY4;

    QString resultString = "";
    ui->print_Cslotmx->setText(resultString.setNum(IX));
    ui->print_Cslotmy->setText(resultString.setNum(IY));

}
