#include "Gestionale_lite/HeaderGrafica/navbarsuperioreintroiti.h"

NavBarSuperioreIntroiti::NavBarSuperioreIntroiti(QWidget *parent) : QWidget(parent){
    ButtonEntrataIntestatario=new QPushButton();
    ButtonEntrataIntestatario->setText("Entrate Intestatario");
    ButtonEntrataIntestatario->setParent(this);
    ButtonEntrataIntestatario->setFont(QFont("MV Boli",10,QFont::Black));
    ButtonEntrataIntestatario->setGeometry(130,30,470,30);
    ButtonEntrataIntestatario->setStyleSheet("background-color:#36648b;");

    LineaUp=new QLabel();
    LineaUp->setParent(this);
    LineaUp->setStyleSheet("background-color:black;");
    LineaUp->setGeometry(130,60,470,1);

    LineaDx=new QLabel();
    LineaDx->setParent(this);
    LineaDx->setStyleSheet("background-color:black;");
    LineaDx->setGeometry(599,30,1,30);

    connect(ButtonEntrataIntestatario,SIGNAL(clicked(bool)),this,SLOT(EntrataIntestatarioClicked()),Qt::UniqueConnection);

}

void NavBarSuperioreIntroiti::EntrataIntestatarioClicked(){
    emit PressLavoratoreOre();
}
