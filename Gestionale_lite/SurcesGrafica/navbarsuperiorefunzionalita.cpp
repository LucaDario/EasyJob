#include "Gestionale_lite/HeaderGrafica/navbarsuperiorefunzionalita.h"

NavBarSuperioreFunzionalita::NavBarSuperioreFunzionalita(QWidget *parent) : QWidget(parent){
    ButtonSpesa=new QPushButton();
    ButtonSpesa->setText("Spesa");
    ButtonSpesa->setParent(this);
    ButtonSpesa->setFont(QFont("MV Boli",10,QFont::Black));
    ButtonSpesa->setGeometry(130,30,156.6,30);
    ButtonSpesa->setStyleSheet("background-color:#36648b;");

    ButtonIntroiti=new QPushButton();
    ButtonIntroiti->setText("Introiti");
    ButtonIntroiti->setParent(this);
    ButtonIntroiti->setFont(QFont("MV Boli",10,QFont::Black));
    ButtonIntroiti->setGeometry(286.6,30,156.6,30);

    ButtonVario=new QPushButton();
    ButtonVario->setText("Vario");
    ButtonVario->setParent(this);
    ButtonVario->setFont(QFont("MV Boli",10,QFont::Black));
    ButtonVario->setGeometry(443.3,30,156.6,30);

    LineaUp=new QLabel();
    LineaUp->setParent(this);
    LineaUp->setStyleSheet("background-color:black;");
    LineaUp->setGeometry(130,60,470,1);

    LineaDx=new QLabel();
    LineaDx->setParent(this);
    LineaDx->setStyleSheet("background-color:black;");
    LineaDx->setGeometry(599,30,1,30);


    //connect

    connect(ButtonSpesa,SIGNAL(clicked(bool)),this,SLOT(SpesaClicked()),Qt::UniqueConnection);
    connect(ButtonIntroiti,SIGNAL(clicked(bool)),this,SLOT(IntroitiClicked()),Qt::UniqueConnection);
    connect(ButtonVario,SIGNAL(clicked(bool)),this,SLOT(VarioClicked()),Qt::UniqueConnection);
}

void NavBarSuperioreFunzionalita::SpesaClicked(){
    emit PressSpese();
    ButtonSpesa->setStyleSheet("background-color:#36648b;");
    ButtonIntroiti->setStyleSheet("");
    ButtonVario->setStyleSheet("");
}
void NavBarSuperioreFunzionalita::IntroitiClicked(){
    emit PressIntroiti();
    ButtonSpesa->setStyleSheet("");
    ButtonIntroiti->setStyleSheet("background-color:#36648b;");
    ButtonVario->setStyleSheet("");
}
void NavBarSuperioreFunzionalita::VarioClicked(){
    emit PressVario();
    ButtonSpesa->setStyleSheet("");
    ButtonIntroiti->setStyleSheet("");
    ButtonVario->setStyleSheet("background-color:#36648b;");
}

void NavBarSuperioreFunzionalita::ButtonColorDefault(){
    ButtonSpesa->setStyleSheet("background-color:#36648b;");
    ButtonIntroiti->setStyleSheet("");
    ButtonVario->setStyleSheet("");

}

