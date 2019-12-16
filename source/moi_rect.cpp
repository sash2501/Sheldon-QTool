#include "moi_rect.h"
#include "ui_moi_rect.h"

moi_rect::moi_rect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::moi_rect)
{
    ui->setupUi(this);

    this->setStyleSheet("QLineEdit { border: 2px solid black; background-color : white; color : black } QLabel { color : white } QPushButton{background:rgb(153,255,153); color : red }");
   //ui->moi_rectx->setStyleSheet();

    ui->rectplotm->setInteraction(QCP::iRangeDrag,true);
    ui->rectplotm->setInteraction(QCP::iRangeZoom,true);
    ui->rectplotm->addGraph();
    ui->rectplotm->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->rectplotm->graph(0)->setLineStyle(QCPGraph::lsNone);


}

moi_rect::~moi_rect()
{
    delete ui;
}

void moi_rect::addPoint(double x, double y)
{

    qv_x.append(x);
    qv_y.append(y);
}

void moi_rect::plot()
{
    ui->rectplotm->graph(0)->setData(qv_x,qv_y);
    ui->rectplotm->replot();
    ui->rectplotm->update();
}

void moi_rect::drawrect()
{
    QCPItemLine *linea = new QCPItemLine(ui->rectplotm);
    linea->setPen(QPen(Qt::blue));
    linea->start->setCoords(Bx,Dy);
    linea->end->setCoords(Bx,By);
    QCPItemLine *lineb = new QCPItemLine(ui->rectplotm);
    lineb->setPen(QPen(Qt::red));
    lineb->start->setCoords(Bx,By);
    lineb->end->setCoords(Dx,By);
    QCPItemLine *linec = new QCPItemLine(ui->rectplotm);
    linec->setPen(QPen(Qt::black));
    linec->start->setCoords(Dx,By);
    linec->end->setCoords(Dx,Dy);
    QCPItemLine *lined = new QCPItemLine(ui->rectplotm);
    lined->setPen(QPen(Qt::green));
    lined->start->setCoords(Dx,Dy);
    lined->end->setCoords(Bx,Dy);
}

void moi_rect::on_btn_findRect_moi_clicked()
{
    QString Oxtext =ui->Originrectm_x->text();
     double Ox= Oxtext.toDouble();
    QString Oytext =ui->Originrectm_y->text();
     double Oy=Oytext.toDouble();
    QString Bxtext =ui->Brectm_x->text();
     Bx= Bxtext.toDouble()-Ox;
    QString Bytext =ui->Brectm_y->text();
     By=Bytext.toDouble()-Oy;
    QString Dxtext =ui->Drectm_x->text();
     Dx= Dxtext.toDouble()-Ox;
    QString Dytext =ui->Drectm_y->text();
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

     double area= length*breadth;

     double dx= ycentroid-Oy;
     double dy= xcentroid-Ox;
     double Ix= (breadth*length*length*length)/12;
     double Iy= (length*breadth*breadth*breadth)/12;
     double IX =  Ix+(area*(dx * dx));
     double IY=    Iy+(area*(dy*dy));

     QString resultString = "";
     ui->moi_rectx->setText(resultString.setNum(IX));
     ui->moi_recty->setText(resultString.setNum(IY));
}
