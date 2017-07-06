#include "Gestionale_lite/HeaderGrafica/titolosuperiore.h"

TitoloSuperiore::TitoloSuperiore(QString a, QWidget *parent) : QWidget(parent), NomeInt(a){

    NomeInt=a;

    QString Temp("Gestionale di ");
    NomeInt=a;
    QString StringaCompleta=Temp+NomeInt;
    Nome=new QLabel;
   Nome->setText(StringaCompleta);
   Nome->setAlignment(Qt::AlignCenter);
   Nome->setParent(this);



    Nome->setFont(QFont("MV Boli",18,QFont::Black));

    Nome->setGeometry(50,6,500,20);

    LineaDown=new QLabel();
    LineaSx=new QLabel();
    LineaUp=new QLabel();
    LineaDx=new QLabel();
    LineaDown->setParent(this);
    LineaDown->setStyleSheet("background-color:black;");
    LineaDown->setGeometry(0,30,600,1);
    LineaSx->setParent(this);
    LineaSx->setStyleSheet("background-color:black;");
     LineaSx->setGeometry(0,0,1,30);
     LineaUp->setParent(this);
     LineaUp->setStyleSheet("background-color:black;");
     LineaUp->setGeometry(0,0,600,1);
     LineaDx->setParent(this);
     LineaDx->setStyleSheet("background-color:black;");
     LineaDx->setGeometry(599,0,1,30);





}






