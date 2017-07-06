#include "Gestionale_lite/HeaderGrafica/infosocieta.h"



InfoSocieta::InfoSocieta(Societa *a, QWidget *parent) : QWidget(parent){
    SocietaPropria=a;

   //gettiLabel
    LabelDataCreazione=new QLabel();
    LabelDataCreazione->setText("DATA CREAZIONE:");
    LabelDataCreazione->setParent(this);

    LabelNome=new QLabel();
   LabelNome->setText("NOME SOCIETA':");
   LabelNome->setParent(this);

   LabelNazionalita=new QLabel();
   LabelNazionalita->setText("NAZIONE:");
   LabelNazionalita->setParent(this);

   LabelPiva=new QLabel();
   LabelPiva->setText("N. PARTITA IVA:");
   LabelPiva->setParent(this);

   LabelDescrizione=new QLabel();
   LabelDescrizione->setText("DESCRIZIONE SOCIETA':");
   LabelDescrizione->setParent(this);

   LabelDataCreazione->setFont(QFont("arial black",14,QFont::Black));
  LabelDataCreazione->setStyleSheet("QLabel{color:red;}");
   LabelNome->setFont(QFont("arial black",14,QFont::Black));
  LabelNome->setStyleSheet("QLabel{color:red;}");
   LabelNazionalita->setFont(QFont("arial black",14,QFont::Black));
   LabelNazionalita->setStyleSheet("QLabel{color:red;}");
   LabelDescrizione->setFont(QFont("arial black",14,QFont::Black));
   LabelDescrizione->setStyleSheet("QLabel{color:red;}");
   LabelPiva->setFont(QFont("arial black",14,QFont::Black));
   LabelPiva->setStyleSheet("QLabel{color:red;}");

   //QLabelStampe
   DataCreazione=new QLabel();
   DataCreazione->setText(SocietaPropria->GetDataCreazione().toString());
   DataCreazione->setParent(this);
   NomeSocieta=new QLabel();
   NomeSocieta->setText(SocietaPropria->GetNomeSocieta());
   NomeSocieta->setParent(this);
   Nazionalita=new QLabel();
   Nazionalita->setText(VerificaNazionlita(SocietaPropria->GetNazionalita()));
   Nazionalita->setParent(this);
   NPiva=new QLabel();
   NPiva->setText(SocietaPropria->GetPiva());
   NPiva->setParent(this);

   //GEometry & Font stampe
   DataCreazione->setFont(QFont("arial black",11,QFont::Times));
   NomeSocieta->setFont(QFont("arial black",12,QFont::Times));
   Nazionalita->setFont(QFont("arial black",12,QFont::Times));
   NPiva->setFont(QFont("arial black",12,QFont::Times));
   DataCreazione->setGeometry(350,69,220,30);
   NomeSocieta->setGeometry(330,129,240,30);
   Nazionalita->setGeometry(250,189,320,30);
   NPiva->setGeometry(320,249,240,30);

   LabelDescrizione1=new QLabel(this);
   LabelDescrizione1->setWordWrap(true);
   LabelDescrizione1->setText(SocietaPropria->GetDescrizioneSocieta());
   LabelDescrizione1->setGeometry(140,350,300,30);
   LabelDescrizione1->setFont((QFont("arial black",12,QFont::Times)));




   //QLAbelGeometry

   LabelDataCreazione->setGeometry(140,70,200,30);
   LabelNome->setGeometry(140,130,200,30);
   LabelNazionalita->setGeometry(140,190,200,30);
   LabelPiva->setGeometry(140,250,200,30);
   LabelDescrizione->setGeometry(140,310,300,30);





    //button elimina
   ButtonElimina=new QPushButton();
   ButtonElimina->setText("Elimina Societa'");
   ButtonElimina->setParent(this);
   ButtonElimina->setGeometry(450,450,100,30);
   ButtonElimina->setFont(QFont("MV Boli",8,QFont::Black));

   connect(ButtonElimina,SIGNAL(clicked(bool)),this,SLOT(EliminaSocieta()));


}







QString InfoSocieta::VerificaNazionlita(QString a) const{
if(a=="IT" || a=="it" ||a=="It" || a=="iT")
    return "ITALIA";
 return "NAZIONALITA' SCONOSCIUTA";

}

void InfoSocieta::EliminaSocieta(){
    delete SocietaPropria;

    emit ApriNuovaSessione();




}
