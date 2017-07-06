#include "Gestionale_lite/HeaderGrafica/activityfunzionalitaintroiti.h"

ActivityFunzionalitaIntroiti::ActivityFunzionalitaIntroiti(Societa *a, QWidget *parent) : QWidget(parent){
    SocietaPropria=a;

        ScrollaArea=new QScrollArea(this);
        ScrollaArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ScrollaArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ScrollaArea->setWidgetResizable(true);
        ScrollaArea->setGeometry(140,150,340,310);

        widget=new QWidget();
        ScrollaArea->setWidget(widget);


        Layout=new QVBoxLayout();
        widget->setLayout(Layout);


        //Estrazione
        LabelMese=new QLabel("Numero Mese:",this);
        LabelMese->setGeometry(140,100,230,30);
        LabelMese->setFont(QFont("arial black",12,QFont::Black));

        Mese=new QSpinBox(this);

        Mese->setGeometry(278,100,40,30);
        Mese->setRange(1,12);

        Anno=new QSpinBox(this);
        Anno->setRange(2001,2038);
        Anno->setGeometry(338,100,60,30);
        Anno->setValue(QDate::currentDate().year());

        Estrai=new QPushButton("Estrazione",this);
        Estrai->setFont(QFont("MV Boli",8,QFont::Black));
        Estrai->setGeometry(470,100,80,30);

        TotImporto=new QLabel("TOT importo:---",this);
        TotImporto->setGeometry(140,450,180,30);
        TotImporto->setFont(QFont("MV Boli",6,QFont::Black));

        TotIva=new QLabel("TOT Iva:---",this);
        TotIva->setGeometry(415,450,180,30);
        TotIva->setFont(QFont("MV Boli",6,QFont::Black));

        TotNonPagato=new QLabel("TOT Non Pagato:---",this);
        TotNonPagato->setGeometry(250,450,200,30);
        TotNonPagato->setFont(QFont("MV Boli",6,QFont::Black));


        connect(Estrai,SIGNAL(clicked(bool)),this,SLOT(Estrazione()));


    }

    void ActivityFunzionalitaIntroiti::Estrazione(){



        double Iva=0;
        double Importo=0;
        double ImportoNonPagato=0;
        //delete

        for(int i=0;i<ListaWidget.size();i++){
           delete ListaWidget[i];                                   //rimuovo dallo heap
        }
        ListaWidget.clear();                        //svuoto il Qvector
        bool esci=0;
        QLayoutItem* a=0;


       while(!esci){

            a= Layout->takeAt(0);
            if(!a){esci=1;}
            if(a){delete a->widget();}


        }





        QVector<Introiti_Lavoratore*> temp=SocietaPropria->EstraiIntroitoByMese(Mese->value(),Anno->value());



        for(int i=0;i<temp.size();i++){
            Iva=Iva+temp[i]->GetIva();
            Importo=Importo+temp[i]->GetTotaleIvaEsclusa();
            if(temp[i]->GetPagato()==0) ImportoNonPagato=ImportoNonPagato+temp[i]->GetTotaleIvaEsclusa();

            Introiti_LavoratoreOre* a=dynamic_cast<Introiti_LavoratoreOre*>(temp[i]);


           if(a){

               ListaWidget.prepend(new WidgetIntroitiLavoratore(SocietaPropria,a,this));

               connect(ListaWidget[0],SIGNAL(PressElimina()),this,SLOT(Estrazione()));


            Layout->addWidget(ListaWidget[0]);
           }
        }


        TotImporto->setText("TOT importo: "+QString::number(Importo,'f',2));
        TotIva->setText("TOT Iva: "+QString::number(Iva,'f',2));
        TotNonPagato->setText("TOT Non Pagato: "+QString::number(ImportoNonPagato,'f',2));
        temp.clear();
  }










