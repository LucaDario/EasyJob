#include "Gestionale_lite/HeaderGrafica/activityoreintroiti.h"

ActivityOreIntroiti::ActivityOreIntroiti(Societa *a, QWidget *parent) : QWidget(parent){

    SocietaPropria=a;
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

    LabelDurataTitolo=new QLabel("DURATA LAVORO",this);
    LabelDurataTitolo->setFont(QFont("arial black",14,QFont::Black));
    LabelDurataTitolo->setGeometry(400,110,200,30);



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
    //Date Edit & button
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
    Pranzo->setDisplayFormat("hh.mm");
    Pranzo->adjustSize();

    ButtonInserisci=new QPushButton("Inserisci",this);
    ButtonInserisci->setGeometry(450,450,100,30);
    ButtonInserisci->setFont(QFont("MV Boli",8,QFont::Black));


    //LabelParteSinistra

    LabelNome=new QLabel("NOME CLIENTE:",this);
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

    //LineEit
    Nome=new QLineEdit(this);
    Nome->setGeometry(140,100,120,20);
    Nome->setMaxLength(10);

    Luogo=new QLineEdit(this);
    Luogo->setGeometry(140,275,120,20);
    Luogo->setMaxLength(10);

    Retribuzione=new QLineEdit(this);
    Retribuzione->setGeometry(140,370,30,20);
    Retribuzione->setValidator(new QDoubleValidator(this));

    //QDateEdit

    Data=new QDateEdit(this);
    Data->setGeometry(140,195,85,20);
    Data->setDate(QDate::currentDate());
    Data->setDisplayFormat("dd.MM.yyyy");
    Data->adjustSize();

    //CheckBox

    Pagato=new QCheckBox("Pagato?",this);
    Pagato->setGeometry(140,415,120,30);
   Pagato->setFont(QFont("arial black",14,QFont::Black));

   connect(ButtonInserisci,SIGNAL(clicked(bool)),this,SLOT(WhenPressInserisci()));

}

void ActivityOreIntroiti::WhenPressInserisci(){
    bool BoolPagato=false;
    if(Pagato->isChecked()) BoolPagato=true;

    QTime j(Inizio->time());
    QTime n(Fine->time());
    QTime m(Pranzo->time());
    Durata g(j,n,m);

    Introiti_LavoratoreOre* temp=new Introiti_LavoratoreOre(Data->dateTime(),g,Nome->text()
                                                                ,Luogo->text(),BoolPagato,Retribuzione->text().toDouble());
    Introiti_Lavoratore* SpesaPolimorfa=temp;
    SocietaPropria->AggiuntaIntroitoOrdinato(SpesaPolimorfa);
    QString a=QString::number(SocietaPropria->GetIntroitiIvaTotali());

    Nome->setText(NULL);
    Luogo->setText(NULL);
    Retribuzione->setText(NULL);

    QTime temp1(0,0,0);
    Data->setDate(QDate::currentDate());
    Inizio->setTime(temp1);
    Fine->setTime(temp1);
    Pranzo->setTime(temp1);




}

