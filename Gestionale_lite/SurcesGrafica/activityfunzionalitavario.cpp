#include "Gestionale_lite/HeaderGrafica/activityfunzionalitavario.h"

ActivityFunzionalitaVario::ActivityFunzionalitaVario(Societa* a,QWidget *parent) : QWidget(parent){
    SocietaPropria=a;

    LabelImporto=new QLabel("Introiti anno(iva escl):",this);
    LabelImporto->setGeometry(140,100,190,30);
    LabelImporto->setFont(QFont("arial black",12,QFont::Times));

    LabelIva=new QLabel("Introiti Iva anno:",this);
    LabelIva->setGeometry(140,170,150,30);
    LabelIva->setFont(QFont("arial black",12,QFont::Times));

    LabelSpeseTot=new QLabel("Spese Anno:",this);
    LabelSpeseTot->setGeometry(140,240,150,30);
    LabelSpeseTot->setFont(QFont("arial black",12,QFont::Times));

    LabelGuadagno=new QLabel("Guadagno Anno:",this);
    LabelGuadagno->setGeometry(140,310,200,30);
    LabelGuadagno->setFont(QFont("arial black",12,QFont::Times));

    LabelIvaAlloStato=new QLabel("Debito Iva Statale Anno:",this);
    LabelIvaAlloStato->setGeometry(140,380,230,30);
    LabelIvaAlloStato->setFont(QFont("arial black",12,QFont::Times));


    AnnoImporto=new QSpinBox(this);
   AnnoImporto->setRange(2001,2038);
    AnnoImporto->setValue(QDateTime::currentDateTime().date().year());
    AnnoImporto->setGeometry(340,100,60,30);

    AnnoIva=new QSpinBox(this);
    AnnoIva->setRange(2001,2038);
    AnnoIva->setValue(QDateTime::currentDateTime().date().year());
    AnnoIva->setGeometry(291,170,60,30);

    AnnoSpese=new QSpinBox(this);
    AnnoSpese->setRange(2001,2038);
    AnnoSpese->setValue(QDateTime::currentDateTime().date().year());
    AnnoSpese->setGeometry(257,240,60,30);

    AnnoGuadagno=new QSpinBox(this);
    AnnoGuadagno->setRange(2001,2038);
    AnnoGuadagno->setValue(QDateTime::currentDateTime().date().year());
    AnnoGuadagno->setGeometry(291,310,60,30);

    AnnoIvaStato=new QSpinBox(this);
    AnnoIvaStato->setRange(2001,2038);
    AnnoIvaStato->setValue(QDateTime::currentDateTime().date().year());
    AnnoIvaStato->setGeometry(370,380,60,30);

    CalcolaImporto=new QPushButton("Calcola",this);
    CalcolaImporto->setGeometry(410,100,80,30);

    CalcolaIva=new QPushButton("Calcola",this);
    CalcolaIva->setGeometry(360,170,80,30);

    CalcolaSpese=new QPushButton("Calcola",this);
    CalcolaSpese->setGeometry(325,240,80,30);

    CalcolaGuadagno=new QPushButton("Calcola",this);
    CalcolaGuadagno->setGeometry(360,310,80,30);

    CalcolaIvaStato=new QPushButton("Calcola",this);
    CalcolaIvaStato->setGeometry(444,380,80,30);

    SoldiImporto=new QLabel(QChar(8364),this);
    SoldiImporto->setGeometry(500,100,140,30);

    SoldiIva=new QLabel(QChar(8364),this);
    SoldiIva->setGeometry(445,170,140,30);

    SoldiSpeseTot=new QLabel(QChar(8364),this);
    SoldiSpeseTot->setGeometry(415,240,140,30);

    SoldiGuadagno=new QLabel(QChar(8364),this);
    SoldiGuadagno->setGeometry(455,310,140,30);

    SoldiIvaAlloStato=new QLabel(QChar(8364),this);
    SoldiIvaAlloStato->setGeometry(525,380,75,30);

    Legenda=new QLabel("* Negativo:Credito,Positivo:Debito",this);
    Legenda->setGeometry(140,470,200,30);
    Legenda->adjustSize();

    connect(CalcolaImporto,SIGNAL(clicked(bool)),this,SLOT(PressCalcolaImporto()));
    connect(CalcolaIva,SIGNAL(clicked(bool)),this,SLOT(PressCalcolaIva()));
    connect(CalcolaSpese,SIGNAL(clicked(bool)),this,SLOT(PressCalcolaSpese()));
    connect(CalcolaIvaStato,SIGNAL(clicked(bool)),this,SLOT(PressCalcolaIvaStato()));
    connect(CalcolaGuadagno,SIGNAL(clicked(bool)),this,SLOT(PressCalcolaGuadagno()));

}

void ActivityFunzionalitaVario::PressCalcolaImporto(){
    SoldiImporto->setText(QString::number(SocietaPropria->GetIntroitiTotali(AnnoImporto->value()),'f',2)+QChar(8364));
}
void ActivityFunzionalitaVario::PressCalcolaIva(){
    SoldiIva->setText(QString::number(SocietaPropria->GetIvaIntroiti(AnnoIva->value()),'f',2)+QChar(8364));

}

void ActivityFunzionalitaVario::PressCalcolaSpese(){
    SoldiSpeseTot->setText(QString::number(SocietaPropria->GetSoldiSpeseIvaTotali(AnnoSpese->value()),'f',2)+QChar(8364));

}

void ActivityFunzionalitaVario::PressCalcolaGuadagno(){
    SoldiGuadagno->setText(QString::number(SocietaPropria->GetIntroitiIvaTotali(AnnoGuadagno->value())-
                           SocietaPropria->GetSoldiSpeseIvaTotali(AnnoGuadagno->value()),'f',2)+QChar(8364));

}

void ActivityFunzionalitaVario::PressCalcolaIvaStato(){
    SoldiIvaAlloStato->setText(QString::number((SocietaPropria->GetIvaIntroiti(AnnoIvaStato->value()),-
                                       SocietaPropria->GetIvaSpese(AnnoIvaStato->value())),'f',2)+QChar(8364)+"*");

}
