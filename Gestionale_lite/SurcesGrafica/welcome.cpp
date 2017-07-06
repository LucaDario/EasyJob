#include "Gestionale_lite/HeaderGrafica/welcome.h"




Welcome::Welcome(QWidget *parent) : QWidget(parent){

    PrimoErrore=false;
    resize(400,500);
    setMinimumHeight(500);
    setMaximumHeight(500);
    setMinimumWidth(400);
    setMaximumWidth(400);
    setWindowTitle("Welcome");






//riga titolo
    Titolo=new QLabel("Easy JOB");
    Titolo->setParent(this);





    Titolo->setFont(QFont("MV Boli",32,QFont::Bold));
    Titolo->setGeometry(85,10,231,71);




    //riga Nome societa
    TextDescrizione=new QTextEdit();
    LabelNomeSocieta=new QLabel();
    TextNomeSocieta=new QLineEdit();
    TextNomeSocieta->setParent(this);
    LabelNomeSocieta->setParent(this);
    LabelNomeSocieta->setFont(QFont("arial black",14,QFont::Black));

    LabelNomeSocieta->setText("WELCOME:");
    LabelNomeSocieta->setGeometry(10,140,120,16);

    TextNomeSocieta->setGeometry(140,140,211,20);
    TextNomeSocieta->setMaxLength(17);

    //riga Partita iva
    TextNazionalita=new QLineEdit();
    TextPiva=new QLineEdit();
    PartitaIva=new QLabel();
    TextNazionalita->setParent(this);
    TextPiva->setParent(this);

    PartitaIva->setText("N. pIva:");
    PartitaIva->setParent(this);
    PartitaIva->setFont(QFont("arial black",14,QFont::Black));
    PartitaIva->setGeometry(10,220,91,21);

    TextNazionalita->setGeometry(140,220,31,20);
    TextNazionalita->setMaxLength(2);




    TextPiva->setGeometry(180,220,171,20);
    TextPiva->setMaxLength(11);
    TextPiva->setValidator(new QDoubleValidator(this));

    //linea descrizione societa


    TextDescrizione=new QTextEdit();
    Descrizione=new QLabel();
    TextDescrizione->setParent(this);

    Descrizione->setText("Descrizione");
    Descrizione->setParent(this);

    NomeSocieta=new QLabel();
    NomeSocieta->setText("Societa':");
    NomeSocieta->setParent(this);
    Descrizione->setFont(QFont("arial black",14,QFont::Black));
    NomeSocieta->setFont(QFont("arial black",14,QFont::Black));
    Descrizione->setGeometry(10,290,131,31);
    NomeSocieta->setGeometry(10,320,91,16);

    TextDescrizione->setGeometry(140,300,211,71);

    //Button Inserisci
    inserisci=new QPushButton();
    inserisci->setText("Inserisci");
    inserisci->setParent(this);

    inserisci->setGeometry(290,440,91,41);



    connect(inserisci,SIGNAL(clicked(bool)),this,
            SLOT(WhenClickedInserisci()));









}
Societa* Welcome::VerificaDati(){
    QString Descrizione=TextDescrizione->toPlainText();

       QString Nazionalita(TextNazionalita->text());

       QString NomeSocieta=TextNomeSocieta->text();

       QString PIva=TextPiva->text();
      if(Descrizione.length()<30 && Nazionalita.length()==2 &&
              NomeSocieta.length()>3 && PIva.length()==11){
          PrimoErrore=1;
          Lista_Spese* P=new Lista_Spese;
          Lista_introiti* l=new Lista_introiti;
          Societa* temp=new Societa(QDateTime::currentDateTime(),NomeSocieta
                                    ,PIva,Descrizione,P,l,Nazionalita);
          return temp;
      }
      return NULL;

}
void Welcome::WhenClickedInserisci(){
    Societa* NuovaSocieta=VerificaDati();
    if(!NuovaSocieta){
        if(!PrimoErrore){
            PrimoErrore=true;
            InserisciErrore();
        }
    }
    else{
        MainActivity* AttivitaPrincipale=new MainActivity(NuovaSocieta,NULL);
        connect(AttivitaPrincipale,SIGNAL(ApriNuovaWelcome()),this,SLOT(WhenElimina()));
        AttivitaPrincipale->show();
        this->close();

    }

}
void Welcome::InserisciErrore(){
    Avviso1=new QLabel();
    Avviso1->setParent(this);
    Avviso1->setText("Errore,ricontrollare i dati immessi");

    Avviso1->setGeometry(10,425,200,15);
    Avviso2=new QLabel();
    Avviso2->setText("Nome Società>3, Partita Iva 2 lettere e 11 numeri");
    Avviso2->setParent(this);
    Avviso3=new QLabel();
    Avviso3->setText("Descrizione<30");
    Avviso3->setParent(this);
    Avviso3->setGeometry(10,440,300,15);
    Avviso2->setGeometry(10,455,300,15);
    Avviso1->setStyleSheet("QLabel{color:red;}");
     Avviso2->setStyleSheet("QLabel{color:red;}");
     Avviso3->setStyleSheet("QLabel{color:red;}");
     Avviso1->setFont(QFont("MV Boli",8,QFont::Normal));
     Avviso2->setFont(QFont("MV Boli",8,QFont::Normal));
     Avviso3->setFont(QFont("MV Boli",8,QFont::Normal));
     Avviso1->show();
     Avviso2->show();
     Avviso3->show();


}

void Welcome::WhenElimina(){
    this->show();
    TextDescrizione->setText(NULL);
    TextNazionalita->setText(NULL);
    TextNomeSocieta->setText(NULL);
    TextPiva->setText(NULL);
}
