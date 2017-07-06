#include "Gestionale_lite/HeaderGrafica/navbarsuperioreinfo.h"

NavBarSuperioreInfo::NavBarSuperioreInfo(QWidget *parent) : QWidget(parent)
{

    Info=new QPushButton;
    Info->setText("Informazioni");
    Info->setParent(this);
    Info->setStyleSheet("background-color:#36648b;");



    Info->setFont(QFont("MV Boli",10,QFont::Black));
    Info->setGeometry(130,30,470,30);

    LineaUp=new QLabel();
    LineaUp->setParent(this);
    LineaUp->setStyleSheet("background-color:black;");
    LineaUp->setGeometry(130,60,470,1);

    LineaDx=new QLabel();
    LineaDx->setParent(this);
    LineaDx->setStyleSheet("background-color:black;");
    LineaDx->setGeometry(599,30,1,30);


    connect(Info,SIGNAL(clicked(bool)),this,SLOT(InfoClicked()),Qt::UniqueConnection);



}



void NavBarSuperioreInfo::InfoClicked(){

    emit PressInfo();
}
