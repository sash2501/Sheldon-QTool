#include "moi_composite.h"
#include "ui_moi_composite.h"

Moi_composite::Moi_composite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Moi_composite)
{
    ui->setupUi(this);
    this->setStyleSheet("QLineEdit { border: 2px solid black; background-color : white; color : black } QLabel { color : white } QPushButton{background:rgb(153,255,153); color : red }");

}

Moi_composite::~Moi_composite()
{
    delete ui;
}

void Moi_composite::on_btn_moi_cmpst_clicked()
{
    //rectangle
    QString oxtext =ui->O1m->text();
    O1m= oxtext.toDouble();
    QString oytext =ui->O2m->text();
    O2m=oytext.toDouble();
    QString Extext =ui->E1m->text();
    E1m= Extext.toDouble()-O1m;
    QString Eytext =ui->E2m->text();
    E2m=Eytext.toDouble()-O2m;
    QString Fxtext =ui->F1m->text();
    F1m= Fxtext.toDouble()-O1m;
    QString Fytext =ui->F2m->text();
    F2m=Fytext.toDouble()-O2m;

//square
    QString Gxtext =ui->G1m->text();
    G1m= Gxtext.toDouble()-O1m;
    QString Gytext =ui->G2m->text();
    G2m=Gytext.toDouble()-O2m;
    QString Hxtext =ui->H1m->text();
    H1m= Hxtext.toDouble()-O1m;
    QString Hytext =ui->H2m->text();
    H2m=Hytext.toDouble()-O2m;

    //circle
    QString radiustext =ui->radius->text();
    rd= radiustext.toDouble()-O1m;
    QString Dytext =ui->D2m->text();
    D2m=Dytext.toDouble()-O2m;
    QString Dxtext =ui->D1m->text();
    D1m= Dxtext.toDouble()-O1m;

    //TRIANGLE

    QString Axtext =ui->A1m->text();
    A1m= Axtext.toDouble()-O1m;
    QString Aytext =ui->A2m->text();
    A2m=Aytext.toDouble()-O2m;
    QString Bxtext =ui->B1m->text();
    B1m= Bxtext.toDouble()-O1m;
    QString Bytext =ui->B2m->text();
    B2m=Bytext.toDouble()-O2m;
    QString Cxtext =ui->C1m->text();
    C1m= Cxtext.toDouble()-O1m;
    QString Cytext =ui->C2m->text();
    C2m=Cytext.toDouble()-O2m;

    //hollows
    QString rectcheck =ui->hollow1m->text();
    QString circlecheck =ui->hollow2m->text();
    QString trianglecheck =ui->hollow3m->text();
    QString squarecheck =ui->hollow4m->text();

    //rectangle CENTROID
    double breadth=E1m-F1m;
    double length= E2m-F2m;

    double area1;
    area1=length*breadth;
    if(rectcheck=="-")
    area1=-area1;


   double x1centroid;
   double y1centroid;
    if (breadth<0)
           { breadth=-breadth;
           x1centroid=(breadth/2)+E1m;}
    else
        x1centroid=(breadth/2)+F1m;

    if (length<0)
           { length=-length;
           y1centroid=(length/2)+E2m;}
    else
        y1centroid=(length/2)+F2m;

    double dx1= y1centroid-O2m;
    double dy1= x1centroid-O1m;
    double Ix1= (breadth*length*length*length)/12;
    double Iy1= (length*breadth*breadth*breadth)/12;
    double IX1 =  Ix1+(area1*(dx1 * dx1));
    double IY1=    Iy1+(area1*(dy1*dy1));

    //SQUARE CENTROID
    double side1=G1m-H1m;
    double side2= G2m-H2m;

    double area2;
    area2=side1*side2;

    if(circlecheck=="-")
    area2=-area2;

   double x2centroid;
   double y2centroid;
    if (side1<0)
           { side1=-side1;
           x2centroid=(side1/2)+G1m;}
    else
        x2centroid=(side1/2)+H1m;

    if (side2<0)
           { side2=-side2;
           y2centroid=(side2/2)+G2m;}
    else
        y2centroid=(side2/2)+H2m;


    double dx2= y2centroid-O2m;
    double dy2= x2centroid-O1m;
    double Ix2= (side1*side2*side2*side2)/12;
    double Iy2= (side2*side1*side1*side1)/12;
    double IX2 =  Ix2+(area2*(dx2 * dx2));
    double IY2=    Iy2+(area2*(dy2*dy2));

    //TRIANGLE CENTROID

    double h= A2m-B2m;
    double b= C1m-B1m;
    double a= A1m-B1m;

    double area3= (h*b)/2;
    if(trianglecheck=="-")
    area3=-area3;

    double x3centroid=(A1m+B1m+C1m)/3;
    double y3centroid=(A2m+B2m+C2m)/3;

    double dx3= y3centroid-O2m;
    double dy3= x3centroid-O1m;

    double Ix3= (b*h*h*h)/36;
    double Iy3= ((b*h*h*h)-(b*b*h*a)+(b*h*a*a))/36;
    double IX3 =  Ix3+(area3*(dx3 * dx3));
    double IY3=   Iy3+(area3*(dy3*dy3));



    //centroid circle

    double x4centroid=D1m;
    double y4centroid=D2m;
    double area4= 3.14*rd*rd;

    if(circlecheck=="-")
    area4=-area4;

    double dx4= y4centroid-O2m;
    double dy4= x4centroid-O1m;
    double Ix4= (3.14*rd*rd*rd*rd)/4;
    double Iy4= Ix4;
    double IX4 =  Ix4+(area4*(dx4*dx4));
    double IY4=   Iy4+(area4*(dy4*dy4));

    //double CentroidX = ((x1centroid*area1)+(x2centroid*area2)+(x3centroid*area3)+(x4centroid*area4))/(area1+area2+area3+area4);
    //double CentroidY = ((y1centroid*area1)+(y2centroid*area2)+(y3centroid*area3)+(y4centroid*area4))/(area1+area2+area3+area4);

    double IX = IX1+IX2+IX3+IX4;
    double IY = IY1+IY2+IY3+IY4;

    QString resultString = "";
    ui->compsxm->setText(resultString.setNum(IX));
    ui->compsym->setText(resultString.setNum(IY));






}
