#include "Gestionale_lite/HeaderGrafica/navbarlaterale.h"

NavBarLAterale::NavBarLAterale(QWidget *parent) : QWidget(parent){

        LineaDx=new QLabel();
        LineaDx->setParent(this);
        LineaDx->setStyleSheet("background-color:black;");
        LineaDx->setGeometry(130,30,1,570);

        LineaDown=new QLabel(this);
        LineaDown->setGeometry(0,499,130,1);
        LineaDown->setStyleSheet("background-color:black;");

        LineaSx=new QLabel(this);
        LineaSx->setGeometry(0,0,1,500);
        LineaSx->setStyleSheet("background-color:black;");





                informazioni=new QPushButton();
                informazioni->setText("Info Societa");
                informazioni->setParent(this);
                informazioni->setFont(QFont("MV Boli",10,QFont::Black));
                informazioni->setGeometry(0,30,130,117.5);
                informazioni->setStyleSheet("background-color:#36648b;");

                InserisciSpese=new QPushButton();
                InserisciSpese->setText("Inserisci Spese");
                InserisciSpese->setParent(this);
                InserisciSpese->setFont(QFont("MV Boli",10,QFont::Black));
                InserisciSpese->setGeometry(0,147.5,130,117.5);

                InserisciEntrata=new QPushButton();
                InserisciEntrata->setText("Inserisci Entrata");
                InserisciEntrata->setParent(this);
                InserisciEntrata->setFont(QFont("MV Boli",10,QFont::Black));
                InserisciEntrata->setGeometry(0,265,130,117.5);

                Funzionalita=new QPushButton();
                Funzionalita->setText("Funzionalita'");
                Funzionalita->setParent(this);
                Funzionalita->setFont(QFont("MV Boli",10,QFont::Black));
                Funzionalita->setGeometry(0,382.5,130,117.5);

                //connect

                connect(informazioni,SIGNAL(clicked(bool)),this,SLOT(InformazioniClicked()),Qt::UniqueConnection);
                connect(InserisciSpese,SIGNAL(clicked(bool)),this,SLOT(InserisciSpeseClicked()),Qt::UniqueConnection);
                connect(InserisciEntrata,SIGNAL(clicked(bool)),this,SLOT(InserisciEntrataClicked()),Qt::UniqueConnection);
                connect(Funzionalita,SIGNAL(clicked(bool)),this,SLOT(FunzionalitaClicked()),Qt::UniqueConnection);

            }


        void NavBarLAterale::ChangeInformazioni(){
            informazioni->setStyleSheet("background-color: red; color: black");

        }
        void NavBarLAterale::ChangeInserisciSpese(){
            InserisciSpese->setStyleSheet("background-color: red; color: black");

        }
        void NavBarLAterale::ChangeInsrisciEntrata(){
            InserisciEntrata->setStyleSheet("background-color: red; color: black");

        }
        void NavBarLAterale::ChangeFunzionalita(){
            Funzionalita->setStyleSheet("background-color: red; color: black");

        }
        //Signal
        void NavBarLAterale::InformazioniClicked(){

            emit PressInformazioni();
            InserisciEntrata->setStyleSheet("");
            informazioni->setStyleSheet("background-color:#36648b;");
            InserisciSpese->setStyleSheet("");
            Funzionalita->setStyleSheet("");
        }

        void NavBarLAterale::InserisciSpeseClicked(){

            emit PressInserisciSpese();
            InserisciEntrata->setStyleSheet("");
            informazioni->setStyleSheet("");
            InserisciSpese->setStyleSheet("background-color:#36648b;");
            Funzionalita->setStyleSheet("");
        }
        void NavBarLAterale::InserisciEntrataClicked(){
            emit PressInserisciEntrata();
            InserisciEntrata->setStyleSheet("background-color:#36648b;");
            informazioni->setStyleSheet("");
            InserisciSpese->setStyleSheet("");
            Funzionalita->setStyleSheet("");

        }
        void NavBarLAterale::FunzionalitaClicked(){
            emit PressFunzionalita();
            InserisciEntrata->setStyleSheet("");
            informazioni->setStyleSheet("");
            InserisciSpese->setStyleSheet("");
            Funzionalita->setStyleSheet("background-color:#36648b;");
        }
