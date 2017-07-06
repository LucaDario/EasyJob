#include "Gestionale_lite/HeaderGrafica/navbarsuperioreSpese.h"

NavBarSuperioreSpese::NavBarSuperioreSpese(QWidget *parent) : QWidget(parent){

    ButtonSpesaGenerle=new QPushButton();
    ButtonSpesaGenerle->setText("Spesa Generale");
    ButtonSpesaGenerle->setParent(this);
    ButtonSpesaGenerle->setFont(QFont("MV Boli",10,QFont::Black));
    ButtonSpesaGenerle->setGeometry(130,30,156.6,30);
    ButtonSpesaGenerle->setStyleSheet("background-color:#36648b;");

    ButtonSpesaKm=new QPushButton();
    ButtonSpesaKm->setText("Spesa Viaggio");
    ButtonSpesaKm->setParent(this);
    ButtonSpesaKm->setFont(QFont("MV Boli",10,QFont::Black));
    ButtonSpesaKm->setGeometry(286.6,30,156.6,30);

    ButtonSpesaDipendente=new QPushButton();
    ButtonSpesaDipendente->setText("Spese Dipendente");
    ButtonSpesaDipendente->setParent(this);
    ButtonSpesaDipendente->setFont(QFont("MV Boli",10,QFont::Black));
    ButtonSpesaDipendente->setGeometry(443.3,30,156.6,30);

    LineaDx=new QLabel();
    LineaDx->setParent(this);
    LineaDx->setStyleSheet("background-color:black;");
    LineaDx->setGeometry(599,30,1,30);

    LineaUp=new QLabel();
    LineaUp->setParent(this);
    LineaUp->setStyleSheet("background-color:black;");
    LineaUp->setGeometry(130,60,470,1);

    //connect

    connect(ButtonSpesaGenerle,SIGNAL(clicked(bool)),this,SLOT(GeneraleClicked()),Qt::UniqueConnection);
    connect(ButtonSpesaKm,SIGNAL(clicked(bool)),this,SLOT(SpesaKmClicked()),Qt::UniqueConnection);
    connect(ButtonSpesaDipendente,SIGNAL(clicked(bool)),this,SLOT(SpesaDipendenteClicked()),Qt::UniqueConnection);
}

void NavBarSuperioreSpese::GeneraleClicked(){
    emit PressGenerali();
    ButtonSpesaGenerle->setStyleSheet("background-color:#36648b;");
    ButtonSpesaDipendente->setStyleSheet("");
    ButtonSpesaKm->setStyleSheet("");
}
void NavBarSuperioreSpese::SpesaKmClicked(){
    emit PressSpesaKm();
    ButtonSpesaGenerle->setStyleSheet("");
    ButtonSpesaDipendente->setStyleSheet("");
    ButtonSpesaKm->setStyleSheet("background-color:#36648b;");
}
void NavBarSuperioreSpese::SpesaDipendenteClicked(){
    emit PressSpesaDipendente();
    ButtonSpesaGenerle->setStyleSheet("");
    ButtonSpesaDipendente->setStyleSheet("background-color:#36648b;");
    ButtonSpesaKm->setStyleSheet("");
}

void NavBarSuperioreSpese::buttonColorDefaut(){
    ButtonSpesaGenerle->setStyleSheet("background-color:#36648b;");
    ButtonSpesaDipendente->setStyleSheet("");
    ButtonSpesaKm->setStyleSheet("");

}

