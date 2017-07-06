#include "Gestionale_lite/HeaderGrafica/activityspesagenerale.h"

ActivitySpesaGenerale::ActivitySpesaGenerale(Societa* a, QWidget *parent) : QWidget(parent){
    SocietaPropria=a;
    LabelText1=new QLabel();
    LabelText1->setParent(this);
    LabelText1->setText("DESCRIZIONE SPESA:");
    LabelText1->setGeometry(140,70,400,30);
    LabelText1->setFont(QFont("arial black",14,QFont::Black));

    Descrizione=new QLineEdit();
    Descrizione->setParent(this);
    Descrizione->setGeometry(140,105,150,20);
    Descrizione->setMaxLength(11);

    LabelText2=new QLabel();
    LabelText2->setParent(this);
    LabelText2->setText("SPESA DA EMETTERE (IVA ESCUSA):");
    LabelText2->setGeometry(140,190,400,30);
    LabelText2->setFont(QFont("arial black",14,QFont::Black));

    LabelTExt3=new QLabel("DATA:",this);
    LabelTExt3->setGeometry(140,305,400,30);
    LabelTExt3->setFont(QFont("arial black",14,QFont::Black));

    DataEdit=new QDateEdit(this);
    DataEdit->setDate(QDate::currentDate());
    DataEdit->setGeometry(140,340,90,30);
    DataEdit->setDisplayFormat("dd.MM.yyyy");
    DataEdit->adjustSize();




    QuantitaSpesa=new QLineEdit();
    QuantitaSpesa->setParent(this);
    QuantitaSpesa->setGeometry(140,225,40,20);
   QuantitaSpesa->setValidator(new QDoubleValidator(this));

    ButtonInserisci=new QPushButton();
    ButtonInserisci->setText("Inserisci");
    ButtonInserisci->setParent(this);
    ButtonInserisci->setGeometry(450,450,100,30);
    ButtonInserisci->setFont(QFont("MV Boli",8,QFont::Black));

    Pagato=new QCheckBox("Pagato?",this);
    Pagato->setGeometry(140,415,120,30);
   Pagato->setFont(QFont("arial black",14,QFont::Black));

    connect(ButtonInserisci,SIGNAL(clicked(bool)),this,SLOT(aggiungiSpesaGenerale()));






}


void ActivitySpesaGenerale::aggiungiSpesaGenerale(){

    bool BoolPagato=false;
    if(Pagato->isChecked()) BoolPagato=true;

    Spesa_generale* nuovaSpesa=new Spesa_generale(DataEdit->dateTime(),QuantitaSpesa->text().toDouble()
                                                 ,Descrizione->text(),BoolPagato);


    Spesa* SpesaPolimorfa=nuovaSpesa;

    SocietaPropria->AggiuntaSpesaOrdinata(SpesaPolimorfa);
    Descrizione->setText(NULL);
    QuantitaSpesa->setText(NULL);







}
