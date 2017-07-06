#include "Gestionale_lite/HeaderGrafica/mainactivity.h"

MainActivity::MainActivity(Societa* a, QWidget *parent) : QWidget(parent){

    resize(600,500);
    setMinimumHeight(500);
    setMaximumHeight(500);
    setMinimumWidth(600);
    setMaximumWidth(600);
    SocietaPropria=a;
    setWindowTitle("Easy Job");




    //costruzione campi dati graficibutton


    titolo=new TitoloSuperiore(SocietaPropria->GetNomeSocieta(),this);

    TabInfo=new InfoSocieta(SocietaPropria,this);
    TabSpesaKm=new ActivitySpesaKm(SocietaPropria,this);
    TabSpesaDipendente=new ActivitySpesaDipendente(SocietaPropria,this);
    TabOreIntroiti=new ActivityOreIntroiti(SocietaPropria,this);
    TabFunzionalitaSpese=new ActivityFunzionalitaSpese(SocietaPropria,this);
    TabFunzionalitaIntroiti=new ActivityFunzionalitaIntroiti(SocietaPropria,this);
    TabFunzionalitaVario=new ActivityFunzionalitaVario(SocietaPropria,this);

    TabSpesaGenerale=new ActivitySpesaGenerale(SocietaPropria,this);


    buttonSuperioriInfo=new NavBarSuperioreInfo(this);

    ButtonSuperioriSpese=new NavBarSuperioreSpese(this);
    ButtonSuperioriIntroiti=new NavBarSuperioreIntroiti(this);
    buttonSuperioriFunzionalita=new NavBarSuperioreFunzionalita(this);
    TabFunzionalitaVario->hide();
     buttonLaterali=new NavBarLAterale(this);


     //HideGrafici
     TabSpesaGenerale->hide();
     TabSpesaKm->hide();
      ButtonSuperioriSpese->hide();
      ButtonSuperioriIntroiti->hide();
      TabSpesaDipendente->hide();
      TabOreIntroiti->hide();
      TabFunzionalitaSpese->hide();
      TabFunzionalitaIntroiti->hide();
      buttonSuperioriFunzionalita->hide();






    //connect BottonInserisciSpesaSuperiore
    connect(ButtonSuperioriSpese,SIGNAL(PressGenerali()),this,SLOT(PressGeneraliDiSpese()));
    connect(ButtonSuperioriSpese,SIGNAL(PressSpesaKm()),this,SLOT(PressKmDiSpese()));
    connect(ButtonSuperioriSpese,SIGNAL(PressSpesaDipendente()),this,SLOT(PressDipenenteDiSpesa()));
    //connect NavBar
       connect(buttonLaterali,SIGNAL(PressInformazioni()),this,SLOT(PressInfo()));
       connect(buttonLaterali,SIGNAL(PressInserisciSpese()),this,SLOT(PressInserisciSpese()));
       connect(buttonLaterali,SIGNAL(PressInserisciEntrata()),this,SLOT(PressInserisciIntroiti()));
       connect(buttonLaterali,SIGNAL(PressFunzionalita()),this,SLOT(PressFunzionalita()));
    //connect NAvBarSuperioreInfo
       connect(buttonSuperioriInfo,SIGNAL(PressInfo()),this,SLOT(PressInformazioniDiInfo()));
    //connect NavBarSuperioreEntrate
       connect(ButtonSuperioriIntroiti,SIGNAL(PressLavoratoreOre()),this,SLOT(PressOreDiEntrata()));
       //connect NavBArSuperioreFunzionalita
       connect(buttonSuperioriFunzionalita,SIGNAL(PressSpese()),this,SLOT(PressSpeseDiFunzionalita()));
       connect(buttonSuperioriFunzionalita,SIGNAL(PressIntroiti()),this,SLOT(PressIntroitiDiFunzionalita()));
       connect(buttonSuperioriFunzionalita,SIGNAL(PressVario()),this,SLOT(PressVarioDiFunzionalita()));

       connect(TabInfo,SIGNAL(ApriNuovaSessione()),this,SLOT(ApriNuovaSessione()));

}
 //Slot NavigationBar

void MainActivity::PressInserisciSpese(){
    TabInfo->hide();
    buttonSuperioriInfo->hide();
    ButtonSuperioriSpese->show();
    ButtonSuperioriIntroiti->hide();
    TabSpesaGenerale->show();
    TabSpesaKm->hide();
    TabSpesaDipendente->hide();
    TabOreIntroiti->hide();
    TabFunzionalitaSpese->hide();
    TabFunzionalitaIntroiti->hide();
    buttonSuperioriFunzionalita->hide();
    TabFunzionalitaVario->hide();
     buttonSuperioriFunzionalita->ButtonColorDefault();
}
void MainActivity::PressInfo(){
    TabInfo->show();
    buttonSuperioriInfo->show();
    ButtonSuperioriSpese->hide();
    ButtonSuperioriIntroiti->hide();
    TabSpesaGenerale->hide();
    TabSpesaKm->hide();
    TabSpesaDipendente->hide();
    TabOreIntroiti->hide();
    TabFunzionalitaSpese->hide();
    TabFunzionalitaIntroiti->hide();
    buttonSuperioriFunzionalita->hide();
    TabFunzionalitaVario->hide();
     buttonSuperioriFunzionalita->ButtonColorDefault();
     ButtonSuperioriSpese->buttonColorDefaut();
}

void MainActivity::PressInserisciIntroiti(){
    TabInfo->hide();
    buttonSuperioriInfo->hide();
    ButtonSuperioriSpese->hide();

    ButtonSuperioriIntroiti->show();
    TabSpesaGenerale->hide();
    TabSpesaKm->hide();
    TabSpesaDipendente->hide();
    TabOreIntroiti->show();
    TabFunzionalitaSpese->hide();
    TabFunzionalitaIntroiti->hide();
    buttonSuperioriFunzionalita->hide();
    TabFunzionalitaVario->hide();
    buttonSuperioriFunzionalita->ButtonColorDefault();
    ButtonSuperioriSpese->buttonColorDefaut();

}
void MainActivity::PressFunzionalita(){
    TabInfo->hide();
    buttonSuperioriInfo->hide();
    ButtonSuperioriSpese->hide();

    ButtonSuperioriIntroiti->hide();
    TabSpesaGenerale->hide();
    TabSpesaKm->hide();
    TabSpesaDipendente->hide();
    TabOreIntroiti->hide();
    TabFunzionalitaSpese->show();
    TabFunzionalitaIntroiti->hide();
    TabFunzionalitaVario->hide();
    buttonSuperioriFunzionalita->show();
    ButtonSuperioriSpese->buttonColorDefaut();

}

//SLot Info
    void MainActivity::PressInformazioniDiInfo(){
        TabInfo->show();


    }

//Slot GraficiSpese

void MainActivity::PressGeneraliDiSpese(){
    TabSpesaGenerale->show();
    TabSpesaKm->hide();
    TabSpesaDipendente->hide();
}

void MainActivity::PressKmDiSpese(){
    TabSpesaGenerale->hide();
    TabSpesaKm->show();
    TabSpesaDipendente->hide();
}
void MainActivity::PressDipenenteDiSpesa(){
    TabSpesaGenerale->hide();
    TabSpesaKm->hide();
    TabSpesaDipendente->show();

}

//Slot Grafiche Entrata
void MainActivity::PressOreDiEntrata(){
    TabOreIntroiti->show();


}

//Slot Grafiche Funzionalita
void MainActivity::PressSpeseDiFunzionalita(){
    TabFunzionalitaSpese->show();
    TabFunzionalitaIntroiti->hide();
    TabFunzionalitaVario->hide();

}
void MainActivity::PressIntroitiDiFunzionalita(){
    TabFunzionalitaSpese->hide();
    TabFunzionalitaIntroiti->show();
    TabFunzionalitaVario->hide();

}

void MainActivity::PressVarioDiFunzionalita(){
    TabFunzionalitaSpese->hide();
    TabFunzionalitaIntroiti->hide();
    TabFunzionalitaVario->show();
}


void MainActivity::ApriNuovaSessione(){

    emit ApriNuovaWelcome();
    delete this;
}
