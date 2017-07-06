#include "Gestionale_lite/HeaderGrafica/activityspesadipendente.h"

ActivitySpesaDipendente::ActivitySpesaDipendente(Societa *a, QWidget *parent) : QWidget(parent){
    SocietaPropria=a;
    //Label
    LabelNome=new QLabel("NOME DIPENDENTE:",this);
    LabelNome->setGeometry(140,70,230,30);
    LabelNome->setFont(QFont("arial black",14,QFont::Black));

    LabelData=new QLabel("DATA LAVORO:",this);
    LabelData->setGeometry(140,165,230,30);
    LabelData->setFont(QFont("arial black",14,QFont::Black));

    LabelLuogo=new QLabel("LUOGO:",this);
    LabelLuogo->setGeometry(140,245,230,30);
    LabelLuogo->setFont(QFont("arial black",14,QFont::Black));


    LabelRetribuzione=new QLabel("RETRIBUZIONE",this);
    LabelRetribuzione->setGeometry(140,325,230,30);
    LabelRetribuzione->setFont(QFont("arial black",14,QFont::Black));

    LabelRetribuzione2=new QLabel("ORARIA:",this);
    LabelRetribuzione2->setGeometry(140,340,200,30);
    LabelRetribuzione2->setFont(QFont("arial black",14,QFont::Black));

    LabelDurataTitolo=new QLabel("DURATA LAVORO",this);
    LabelDurataTitolo->setFont(QFont("arial black",14,QFont::Black));
    LabelDurataTitolo->setGeometry(400,110,200,30);





    //LabelDurata

    LabelInizio=new QLabel("Inizio Lavoro:",this);
    LabelInizio->setFont(QFont("arial black",12,QFont::Black));
    LabelInizio->setGeometry(380,140,180,20);

    LabelFine=new QLabel("Fine Lavoro:",this);
    LabelFine->setFont(QFont("arial black",12,QFont::Black));
    LabelFine->setGeometry(380,220,180,20);

    LabelPranzo=new QLabel("Durata Pranzo:", this);
    LabelPranzo->setFont(QFont("arial black",12,QFont::Black));
    LabelPranzo->setGeometry(380,300,180,20);





    //QLabelGrafici
    LabelUp=new QLabel (this);
    LabelUp->setStyleSheet("background-color:black;");
    LabelUp->setGeometry(370,140,230,1);

    LabelLeft=new QLabel(this);
    LabelLeft->setStyleSheet("background-color:black;");
    LabelLeft->setGeometry(370,140,1,220);

    LabelDown=new QLabel(this);
    LabelDown->setStyleSheet("background-color:black;");
    LabelDown->setGeometry(370,360,230,1);

    //QLIneEdit

    Nome=new QLineEdit(this);
    Nome->setGeometry(140,100,120,20);
    Nome->setMaxLength(10);

    Luogo=new QLineEdit(this);
    Luogo->setGeometry(140,275,120,20);
    Luogo->setMaxLength(10);


    Retribuzione=new QLineEdit(this);
    Retribuzione->setGeometry(140,370,30,20);
    Retribuzione->setValidator(new QDoubleValidator(this));




    //CheckBox

    Pagato=new QCheckBox("Pagato?",this);
    Pagato->setGeometry(140,415,120,30);
   Pagato->setFont(QFont("arial black",14,QFont::Black));

   //QDateEdit

   Data=new QDateEdit(this);
   Data->setGeometry(140,195,85,20);
   Data->setDate(QDate::currentDate());
   Data->setDisplayFormat("dd:MM:yyyy");
   Data->adjustSize();

   Inizio=new QTimeEdit(this);
   Inizio->setGeometry(380,165,65,20);
   Inizio->setDisplayFormat("hh:mm");
   Inizio->adjustSize();

   Fine=new QTimeEdit(this);
   Fine->setGeometry(380,245,65,20);
   Fine->setDisplayFormat("hh:mm");
   Fine->adjustSize();

   Pranzo=new QTimeEdit(this);
   Pranzo->setGeometry(380,325,65,20);
   Pranzo->setDisplayFormat("hh:mm");
   Pranzo->adjustSize();


   ButtonInserisci=new QPushButton("Inserisci",this);
   ButtonInserisci->setGeometry(450,450,100,30);
   ButtonInserisci->setFont(QFont("MV Boli",8,QFont::Black));

   connect(ButtonInserisci,SIGNAL(clicked(bool)),this,SLOT(AggiungiSpesa()));

}

void ActivitySpesaDipendente::AggiungiSpesa(){
    QTime j(Inizio->time());
    QTime n(Fine->time());
    QTime m(Pranzo->time());
    Durata g(j,n,m);
    bool BoolPagato=false;
    if(Pagato->isChecked()) BoolPagato=true;

    Spese_Dipendente* nuovaSpesa=new Spese_Dipendente(Data->dateTime(),Nome->text(),Luogo->text(),g,
                                                      Retribuzione->text().toDouble(),BoolPagato);
    Spesa* SpesaPolimorfa=nuovaSpesa;
    SocietaPropria->AggiuntaSpesaOrdinata(SpesaPolimorfa);
    Luogo->setText(NULL);
    Nome->setText(NULL);
    Retribuzione->setText(NULL);
    Data->setDate(QDate::currentDate());


    QTime temp1(0,0,0);
    Data->setDate(QDate::currentDate());
    Inizio->setTime(temp1);
    Fine->setTime(temp1);
    Pranzo->setTime(temp1);


}

