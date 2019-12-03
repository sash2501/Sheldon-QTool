#include "centroid_cwithslot.h"
#include "ui_centroid_cwithslot.h"

Centroid_Cwithslot::Centroid_Cwithslot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Centroid_Cwithslot)
{
    ui->setupUi(this);

    ui->Cslotplot->setInteraction(QCP::iRangeDrag,true);
    ui->Cslotplot->setInteraction(QCP::iRangeZoom,true);
    ui->Cslotplot->addGraph();
    ui->Cslotplot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->Cslotplot->graph(0)->setLineStyle(QCPGraph::lsNone);

    this->setStyleSheet("QLineEdit { border: 2px solid black; background-color : white; color : black } QLabel { color : white } QPushButton{background:rgb(153,255,255); color : red }");


}

Centroid_Cwithslot::~Centroid_Cwithslot()
{
    delete ui;
}

void Centroid_Cwithslot::addPoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
}

void Centroid_Cwithslot::plot()
{
    ui->Cslotplot->graph(0)->setData(qv_x,qv_y);
    ui->Cslotplot->replot();
    ui->Cslotplot->update();
}

void Centroid_Cwithslot::plotCslot(double A1s, double A2s, double B1s, double B2s, double C1s, double C2s, double D1s, double D2s, double M1, double M2, double N1, double N2)
{
    {
        //rectangle1
        QCPItemLine *line1 = new QCPItemLine(ui->Cslotplot);
        line1->setPen(QPen(Qt::green));
        line1->start->setCoords(A1s,A2s);
        line1->end->setCoords(B1s,A2s);
        QCPItemLine *line2 = new QCPItemLine(ui->Cslotplot);
        line2->setPen(QPen(Qt::blue));
        line2->start->setCoords(B1s,A2s);
        line2->end->setCoords(B1s,B2s);
        QCPItemLine *line3 = new QCPItemLine(ui->Cslotplot);
        line3->setPen(QPen(Qt::red));
        line3->start->setCoords(B1s,B2s);
        line3->end->setCoords(A1s,B2s);
        QCPItemLine *line4 = new QCPItemLine(ui->Cslotplot);
        line4->setPen(QPen(Qt::black));
        line4->start->setCoords(A1s,B2s);
        line4->end->setCoords(A1s,A2s);


        //rectangle2
        QCPItemLine *line5 = new QCPItemLine(ui->Cslotplot);
        line5->setPen(QPen(Qt::green));
        line5->start->setCoords(C1s,B2s);
        line5->end->setCoords(B1s,B2s);
        QCPItemLine *line6 = new QCPItemLine(ui->Cslotplot);
        line6->setPen(QPen(Qt::blue));
        line6->start->setCoords(B1s,B2s);
        line6->end->setCoords(B1s,C2s);
        QCPItemLine *line7 = new QCPItemLine(ui->Cslotplot);
        line7->setPen(QPen(Qt::red));
        line7->start->setCoords(B1s,C2s);
        line7->end->setCoords(C1s,C2s);
        QCPItemLine *line8 = new QCPItemLine(ui->Cslotplot);
        line8->setPen(QPen(Qt::black));
        line8->start->setCoords(C1s,C2s);
        line8->end->setCoords(C1s,B2s);

        //rectangle3
        QCPItemLine *line9 = new QCPItemLine(ui->Cslotplot);
        line9->setPen(QPen(Qt::green));
        line9->start->setCoords(D1s,D2s);
        line9->end->setCoords(C1s,D2s);
        QCPItemLine *line10 = new QCPItemLine(ui->Cslotplot);
        line10->setPen(QPen(Qt::blue));
        line10->start->setCoords(C1s,D2s);
        line10->end->setCoords(C1s,C2s);
        QCPItemLine *line11 = new QCPItemLine(ui->Cslotplot);
        line11->setPen(QPen(Qt::red));
        line11->start->setCoords(C1s,C2s);
        line11->end->setCoords(D1s,C2s);
        QCPItemLine *line12 = new QCPItemLine(ui->Cslotplot);
        line12->setPen(QPen(Qt::black));
        line12->start->setCoords(D1s,C2s);
        line12->end->setCoords(D1s,D2s);

        //slot
        QCPItemLine *line13 = new QCPItemLine(ui->Cslotplot);
        line13->setPen(QPen(Qt::green));
        line13->start->setCoords(M1,M2);
        line13->end->setCoords(N1,M2);
        QCPItemLine *line14 = new QCPItemLine(ui->Cslotplot);
        line14->setPen(QPen(Qt::blue));
        line14->start->setCoords(N1,M2);
        line14->end->setCoords(N1,N2);
        QCPItemLine *line15 = new QCPItemLine(ui->Cslotplot);
        line15->setPen(QPen(Qt::red));
        line15->start->setCoords(N1,N2);
        line15->end->setCoords(M1,N2);
        QCPItemLine *line16 = new QCPItemLine(ui->Cslotplot);
        line16->setPen(QPen(Qt::black));
        line16->start->setCoords(M1,N2);
        line16->end->setCoords(M1,M2);

    }
}

void Centroid_Cwithslot::on_btn_findCslot_centroid_clicked()
{
    QString Oxtext =ui->OriginCslot_x->text();
     double Osx= Oxtext.toDouble();
    QString Oytext =ui->OriginCslot_y->text();
     double Osy=Oytext.toDouble();
    QString Axtext =ui->Aslot_x->text();
    Asx= Axtext.toDouble()-Osx;
    QString Aytext =ui->Aslot_y->text();
    Asy=Aytext.toDouble()-Osy;
    QString Bxtext =ui->Bslot_x->text();
    Bsx= Bxtext.toDouble()-Osx;
    QString Bytext =ui->Bslot_y->text();
    Bsy=Bytext.toDouble()-Osy;
    QString Cxtext =ui->Cslot_x->text();
    Csx= Cxtext.toDouble()-Osx;
    QString Cytext =ui->Cslot_y->text();
    Csy=Cytext.toDouble()-Osy;
    QString Dxtext =ui->Dslot_x->text();
    Dsx= Dxtext.toDouble()-Osx;
    QString Dytext =ui->Dslot_y->text();
    Dsy=Dytext.toDouble()-Osy;


    QString Mxtext =ui->M_x->text();
     Mx= Mxtext.toDouble()-Osx;
    QString Mytext =ui->M_y->text();
     My=Mytext.toDouble()-Osy;
    QString Nxtext =ui->N_x->text();
     Nx= Nxtext.toDouble()-Osx;
    QString Nytext =ui->N_y->text();
     Ny=Nytext.toDouble()-Osy;

    addPoint(Asx,Asy);
    addPoint(Bsx,Bsy);
    addPoint(Csx,Csy);
    addPoint(Dsx,Dsy);
    addPoint(Osx,Osy);
    addPoint(Mx,My);
    addPoint(Nx,Ny);

    plot();
    plotCslot(Asx,Asy,Bsx,Bsy,Csx,Csy,Dsx,Dsy,Mx,My,Nx,Ny);






    //rectangle1
    double breadth1=Asx-Bsx;
    double length1= Asy-Bsy;

    double area1;
    area1=length1*breadth1;

   double x1centroid;
   double y1centroid;
    if (breadth1<0)
           { breadth1=-breadth1;
           x1centroid=(breadth1/2)+Asx;}
    else
        x1centroid=(breadth1/2)+Bsx;

    if (length1<0)
           { length1=-length1;
           y1centroid=(length1/2)+Asy;}
    else
        y1centroid=(length1/2)+Bsy;
    addPoint(x1centroid,y1centroid);
    plot();



    //rectangle2

    double breadth2=Csx-Bsx;
    double length2= Bsy-Csy;

    double area2=length2*breadth2;

   double x2centroid;
   double y2centroid;
    if (breadth2<0)
           { breadth2=-breadth2;
           x2centroid=(breadth2/2)+Csx;}
    else
        x2centroid=(breadth2/2)+Bsx;

    if (length2<0)
           { length2=-length2;
           y2centroid=(length2/2)+Bsy;}
    else
        y2centroid=(length2/2)+Csy;
    addPoint(x2centroid,y2centroid);
    plot();




    //rectangle3



    double breadth3=Dsx-Csx;
    double length3= Dsy-Csy;

    double area3=length3*breadth3;

   double x3centroid;
   double y3centroid;
    if (breadth3<0)
           { breadth3=-breadth3;
           x3centroid=(breadth3/2)+Dsx;}
    else
        x3centroid=(breadth3/2)+Csx;

    if (length3<0)
           { length3=-length3;
           y3centroid=(length3/2)+Dsy;}
    else
        y3centroid=(length3/2)+Csy;
    addPoint(x3centroid,y3centroid);
    plot();

    //finding centroid of slot


    //finding total centroid

    double breadth4=Mx-Nx;
    double length4= My-Ny;

    double area4;
    area4=length4*breadth4;

   double x4centroid;
   double y4centroid;
    if (breadth4<0)
           { breadth4=-breadth4;
           x4centroid=(breadth4/2)+Mx;}
    else
        x4centroid=(breadth4/2)+Nx;

    if (length4<0)
           { length4=-length4;
           y4centroid=(length4/2)+My;}
    else
        y4centroid=(length4/2)+Ny;
    addPoint(x4centroid,y4centroid);
    plot();


    double totalCslotx = ((x1centroid*area1)+(x2centroid*area2)+(x3centroid*area3)-(x4centroid*area4))/(area1+area2+area3-area4);
    double totalCsloty = ((y1centroid*area1)+(y2centroid*area2)+(y3centroid*area3)-(y4centroid*area4))/(area1+area2+area3-area4);


    addPoint(totalCslotx,totalCsloty);
    plot();


    QString resultString = "";
    ui->print_Cslotx->setText(resultString.setNum(totalCslotx));
    ui->print_Csloty->setText(resultString.setNum(totalCsloty));

}
