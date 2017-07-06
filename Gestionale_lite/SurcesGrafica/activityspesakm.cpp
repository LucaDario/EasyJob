
#include "Gestionale_lite/HeaderGrafica/activityspesakm.h"

ActivitySpesaKm::ActivitySpesaKm(Societa *a, QWidget *parent) : QWidget(parent){
    SocietaPropria=a;

    ButtonInserisci=new QPushButton();
    ButtonInserisci->setText("Inserisci");
    ButtonInserisci->setParent(this);
    ButtonInserisci->setGeometry(450,450,100,30);
    ButtonInserisci->setFont(QFont("MV Boli",8,QFont::Black));

    //Label
    LabelLuogo=new QLabel();
    LabelLuogo->setParent(this);
    LabelLuogo->setText("LUOGO RAGGIUNTO:");
    LabelLuogo->setGeometry(140,70,400,30);
    LabelLuogo->setFont(QFont("arial black",14,QFont::Black));




    LabelKm=new QLabel("KM PERCORSI:",this);
    LabelKm->setGeometry(140,166,400,30);
    LabelKm->setFont(QFont("arial black",14,QFont::Black));

    LabelKMLMezzo=new QLabel("Km/l DEL MEZZO:",this);
    LabelKMLMezzo->setGeometry(140,262,400,30);
    LabelKMLMezzo->setFont(QFont("arial black",14,QFont::Black));

    LabelPrezzoCarburante=new QLabel("PREZZO CARBURANTE:",this);
    LabelPrezzoCarburante->setGeometry(140,358,400,30);
    LabelPrezzoCarburante->setFont(QFont("arial black",14,QFont::Black));

    //QLineEdit
    TextLuogo=new QLineEdit();
    TextLuogo->setParent(this);
    TextLuogo->setGeometry(140,105,150,20);
    TextLuogo->setMaxLength(10);

    TextKMPercorsi=new QLineEdit(this);
    TextKMPercorsi->setGeometry(140,201,40,20);
    TextKMPercorsi->setValidator(new QDoubleValidator(this));

    TextKMlitro=new QLineEdit(this);
    TextKMlitro->setGeometry(140,297,40,20);
    TextKMlitro->setMaxLength(10);
   TextKMlitro->setValidator(new QDoubleValidator(this));

    TextPrezzoGasolio=new QLineEdit(this);
    TextPrezzoGasolio->setGeometry(140,393,40,20);
    TextPrezzoGasolio->setValidator(new QDoubleValidator(this));


    LabelData=new QLabel("DATA:",this);
    LabelData->setGeometry(450,70,80,30);
    LabelData->setFont(QFont("arial black",14,QFont::Black));



    DataEdit=new QDateEdit(this);
    DataEdit->setDate(QDate::currentDate());
    DataEdit->setGeometry(450,105,100,30);
    DataEdit->setDisplayFormat("dd.MM.yyyy");
    DataEdit->adjustSize();

    //CheckBox

    Pagato=new QCheckBox("Pagato?",this);
    Pagato->setGeometry(140,425,120,30);
   Pagato->setFont(QFont("arial black",14,QFont::Black));

    connect(ButtonInserisci,SIGNAL(clicked(bool)),this,SLOT(AggiungiSpesaKm()));

}

void ActivitySpesaKm::AggiungiSpesaKm(){
    bool BoolPagato=false;
    if(Pagato->isChecked()) BoolPagato=true;
    Spesa_Km* nuovaSpesa=new Spesa_Km(DataEdit->dateTime(),TextKMPercorsi->text().toDouble()
                                      ,TextPrezzoGasolio->text().toDouble(),TextKMlitro->text().toDouble(),
                                      TextLuogo->text(),BoolPagato);
    Spesa* SpesaPolimorfa=nuovaSpesa;
    SocietaPropria->AggiuntaSpesaOrdinata(SpesaPolimorfa);

    TextKMlitro->setText(NULL);
    TextKMPercorsi->setText(NULL);
    TextLuogo->setText(NULL);
    TextPrezzoGasolio->setText(NULL);




}


