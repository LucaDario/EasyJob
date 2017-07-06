#include "Gestionale_lite/HeaderGrafica/widgetintroitilavoratore.h"

WidgetIntroitiLavoratore::WidgetIntroitiLavoratore(Societa* a, Introiti_LavoratoreOre* b,QWidget *parent) : QWidget(parent){
    SocietaPropria=a;
    PointerIntroiti=b;


    resize(300,68.5);
    setMinimumHeight(78.5);
    setMaximumHeight(78.5);
    setMinimumWidth(300);
    setMaximumWidth(300);

    //LAbel Grafici
    up=new QLabel(this);
    up->setGeometry(0,0,300,1);
    up->setStyleSheet("background-color:black;");

    down=new QLabel(this);
    down->setGeometry(0,77.5,300,1);
    down->setStyleSheet("background-color:black;");

    left=new QLabel(this);
    left->setGeometry(0,0,1,78.5);
    left->setStyleSheet("background-color:black;");

    right=new QLabel(this);
    right->setGeometry(299,0,1,77.5);
    right->setStyleSheet("background-color:black;");

    //Label

    LabelTipo=new QLabel(this);
    LabelTipo->setText("Introito Intestatario");
    LabelTipo->setGeometry(5,5,295,14);
    LabelTipo->setAlignment(Qt::AlignCenter);
    LabelTipo->setFont(QFont("MV Boli",10,QFont::Black));

    QString temp="Importo: "+ QString::number(PointerIntroiti->GetTotaleIvaEsclusa());
    LabelImporto=new QLabel(temp,this);
    LabelImporto->setGeometry(5,21,120,15);

    temp="IVA: "+ QString::number(PointerIntroiti->GetIva());
    LabelIva=new QLabel(temp,this);
    LabelIva->setGeometry(5,37,120,15);

    LabelNome=new QLabel("Nome: "+PointerIntroiti->GetCliente()+"("+PointerIntroiti->GetLuogo()+")",this);
    LabelNome->setGeometry(126,21,170,15);

    temp="Data: "+ PointerIntroiti->GetData_Lavoro().date().toString("dd/MM/yyyy");
    LabelData=new QLabel(temp,this);
    LabelData->setGeometry(5,53,120,15);

    if(PointerIntroiti->GetPagato()) temp="SI";
    else temp="NO";

    LabelPagato=new QLabel("Pagato: "+temp,this);
    LabelPagato->setGeometry(126,37,170,15);

    if(PointerIntroiti->GetPagato()) temp="Set Non Pagato";
    else temp="Set Pagato";
    ButtonSetPagato=new QPushButton(temp,this);
    ButtonSetPagato->setGeometry(132,57.5,85,21);
    ButtonSetPagato->setFont(QFont("MV Boli",6,QFont::Black));

    ButtonElimina=new QPushButton("Elimina",this);
    ButtonElimina->setGeometry(215,57.5,85,21);
    ButtonElimina->setFont(QFont("MV Boli",6,QFont::Black));

    connect(ButtonSetPagato,SIGNAL(clicked(bool)),this,SLOT(SetPagato()));
    connect(ButtonElimina,SIGNAL(clicked(bool)),this,SLOT(Elimina()));

}


void WidgetIntroitiLavoratore::SetPagato(){
    PointerIntroiti->changePagato();

    QString temp;
    if(PointerIntroiti->GetPagato()) temp="Set Non Pagato";
    else temp="Set Pagato";
    ButtonSetPagato->setText(temp);
    if(PointerIntroiti->GetPagato()) temp="SI";
    else temp="NO";
    LabelPagato->setText("Pagato: "+temp);



}

void WidgetIntroitiLavoratore::Elimina(){
    SocietaPropria->EliminaIntroito(PointerIntroiti);

    emit PressElimina();



}



