#ifndef MAINACTIVITY_H
#define MAINACTIVITY_H
#include "Gestionale_lite/HeaderGrafica/titolosuperiore.h"
#include "Gestionale_lite/HeaderGrafica/navbarlaterale.h"
#include "Gestionale_lite/HeaderGrafica/navbarsuperioreinfo.h"
#include "Gestionale_lite/HeaderLogica/societa.h"
#include "Gestionale_lite/HeaderGrafica/infosocieta.h"
#include "Gestionale_lite/HeaderGrafica/navbarsuperioreSpese.h"
#include "Gestionale_lite/HeaderGrafica/navbarsuperioreintroiti.h"
#include "Gestionale_lite/HeaderGrafica/activityspesagenerale.h"
#include "Gestionale_lite/HeaderGrafica/activityspesakm.h"
#include "Gestionale_lite/HeaderGrafica/activityspesadipendente.h"
#include "Gestionale_lite/HeaderGrafica/activityoreintroiti.h"
#include "Gestionale_lite/HeaderGrafica/activityfunzionalitaspese.h"
#include "Gestionale_lite/HeaderGrafica/navbarsuperiorefunzionalita.h"
#include "Gestionale_lite/HeaderGrafica/activityfunzionalitaintroiti.h"
#include "Gestionale_lite/HeaderGrafica/activityfunzionalitavario.h"



#include <QWidget>

class MainActivity : public QWidget
{
    Q_OBJECT
private:

    Societa* SocietaPropria;
    TitoloSuperiore* titolo;
    NavBarLAterale* buttonLaterali;
    NavBarSuperioreInfo* buttonSuperioriInfo;
    InfoSocieta* TabInfo;
    NavBarSuperioreSpese* ButtonSuperioriSpese;
    NavBarSuperioreIntroiti* ButtonSuperioriIntroiti;
    ActivitySpesaGenerale* TabSpesaGenerale;
    ActivitySpesaKm* TabSpesaKm;
    ActivitySpesaDipendente* TabSpesaDipendente;
    ActivityOreIntroiti* TabOreIntroiti;
    ActivityFunzionalitaSpese* TabFunzionalitaSpese;
    ActivityFunzionalitaIntroiti* TabFunzionalitaIntroiti;
    ActivityFunzionalitaVario* TabFunzionalitaVario;
    NavBarSuperioreFunzionalita* buttonSuperioriFunzionalita;




public:
    explicit MainActivity( Societa *a,QWidget *parent);

signals:
    void ApriNuovaWelcome();


public slots:
    //Slot navigationBar
    void PressInserisciSpese();
    void PressInfo();
    void PressInserisciIntroiti();
    void PressFunzionalita();
    //Slot GraficiInfo
    void PressInformazioniDiInfo();
    //Slot GraficiSpese
    void PressGeneraliDiSpese();
    void PressKmDiSpese();
    void PressDipenenteDiSpesa();
    //Slot GRafiche Entrata
    void PressOreDiEntrata();
    //Slot Grafiche Funzionalita
    void PressSpeseDiFunzionalita();
    void PressIntroitiDiFunzionalita();
    void PressVarioDiFunzionalita();

    void ApriNuovaSessione();
};

#endif // MAINACTIVITY_H
