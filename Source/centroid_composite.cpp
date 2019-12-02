#include "centroid_composite.h"
#include "ui_centroid_composite.h"

Centroid_composite::Centroid_composite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Centroid_composite)
{
    ui->setupUi(this);

    this->setStyleSheet("QLineEdit { border: 2px solid black; background-color : white; color : black } QLabel { color : white } QPushButton{background:rgb(153,255,255); color : red }");

}

Centroid_composite::~Centroid_composite()
{
    delete ui;
}

void Centroid_composite::on_btn_centroid_cmpst_clicked()
{
    //rectangle
    QString oxtext =ui->O1->text();
    O1= oxtext.toDouble();
    QString oytext =ui->O2->text();
    O2=oytext.toDouble();
    QString Extext =ui->E1->text();
    E1= Extext.toDouble()-O1;
    QString Eytext =ui->E2->text();
    E2=Eytext.toDouble()-O2;
    QString Fxtext =ui->F1->text();
    F1= Fxtext.toDouble()-O1;
    QString Fytext =ui->F2->text();
    F2=Fytext.toDouble()-O2;

//square
    QString Gxtext =ui->G1->text();
    G1= Gxtext.toDouble()-O1;
    QString Gytext =ui->G2->text();
    G2=Gytext.toDouble()-O2;
    QString Hxtext =ui->H1->text();
    H1= Hxtext.toDouble()-O1;
    QString Hytext =ui->H2->text();
    H2=Hytext.toDouble()-O2;

    //circle
    QString radiustext =ui->radius->text();
    r= radiustext.toDouble()-O1;
    QString Dytext =ui->D2->text();
    D2=Dytext.toDouble()-O2;
    QString Dxtext =ui->D1->text();
    D1= Dxtext.toDouble()-O1;

    //TRIANGLE

    QString Axtext =ui->A1->text();
    A1= Axtext.toDouble()-O1;
    QString Aytext =ui->A2->text();
    A2=Aytext.toDouble()-O2;
    QString Bxtext =ui->B1->text();
    B1= Bxtext.toDouble()-O1;
    QString Bytext =ui->B2->text();
    B2=Bytext.toDouble()-O2;
    QString Cxtext =ui->C1->text();
    C1= Cxtext.toDouble()-O1;
    QString Cytext =ui->C2->text();
    C2=Cytext.toDouble()-O2;

    //hollows
    QString rectcheck =ui->hollow1->text();
    QString circlecheck =ui->hollow2->text();
    QString trianglecheck =ui->hollow3->text();
    QString squarecheck =ui->hollow4->text();

    //rectangle CENTROID
    double breadth=E1-F1;
    double length= E2-F2;



    double area1;
    area1=length*breadth;
    if(rectcheck=="-")
    area1=-area1;


   double x1centroid;
   double y1centroid;
    if (breadth<0)
           { breadth=-breadth;
           x1centroid=(breadth/2)+E1;}
    else
        x1centroid=(breadth/2)+F1;

    if (length<0)
           { length=-length;
           y1centroid=(length/2)+E2;}
    else
        y1centroid=(length/2)+F2;

    //SQUARE CENTROID
    double side1=G1-H1;
    double side2= G2-H2;

    double area2;
    area2=side1*side2;

    if(circlecheck=="-")
    area2=-area2;

   double x2centroid;
   double y2centroid;
    if (side1<0)
           { side1=-side1;
           x2centroid=(side1/2)+G1;}
    else
        x2centroid=(side1/2)+H1;

    if (side2<0)
           { side2=-side2;
           y2centroid=(side2/2)+G2;}
    else
        y2centroid=(side2/2)+H2;

    //TRIANGLE CENTROID

    double h= A2-B2;
    double b= C1-B1;

    double area3= (h*b)/2;
    if(trianglecheck=="-")
    area3=-area3;

    double x3centroid=(A1+B1+C1)/3;
    double y3centroid=(A2+B2+C2)/3;

    //centroid circle

    double x4centroid=D1;
    double y4centroid=D2;
    double area4= 3.14*r*r;

    if(circlecheck=="-")
    area4=-area4;

    double totalcompstx= ((x1centroid*area1)+(x2centroid*area2)+(x3centroid*area3)+(x4centroid*area4))/(area1+area2+area3+area4);
    double totalcompsty= ((y1centroid*area1)+(y2centroid*area2)+(y3centroid*area3)+(y4centroid*area4))/(area1+area2+area3+area4);

    QString resultString = "";
    ui->compsx->setText(resultString.setNum(totalcompstx));
    ui->compsy->setText(resultString.setNum(totalcompsty));


}
