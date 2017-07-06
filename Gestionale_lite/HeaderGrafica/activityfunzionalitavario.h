#ifndef ACTIVITYFUNZIONALITAVARIO_H
#define ACTIVITYFUNZIONALITAVARIO_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include "Gestionale_lite/HeaderLogica/societa.h"

class ActivityFunzionalitaVario : public QWidget
{
    Q_OBJECT
private:
    Societa* SocietaPropria;

    QLabel* LabelImporto;
    QLabel* LabelIva;
    QLabel* LabelSpeseTot;
    QLabel* LabelGuadagno;
    QLabel* LabelIvaAlloStato;

    QLabel* SoldiImporto;
    QLabel* SoldiIva;
    QLabel* SoldiSpeseTot;
    QLabel* SoldiGuadagno;
    QLabel* SoldiIvaAlloStato;

    QSpinBox* AnnoImporto;
    QSpinBox* AnnoIva;
    QSpinBox* AnnoGuadagno;
    QSpinBox* AnnoIvaStato;
    QSpinBox* AnnoSpese;

    QPushButton* CalcolaImporto;
    QPushButton* CalcolaIva;
    QPushButton* CalcolaSpese;

    QPushButton* CalcolaGuadagno;
    QPushButton* CalcolaIvaStato;
    QLabel* Legenda;


public:
    explicit ActivityFunzionalitaVario(Societa* a,QWidget *parent = 0);

signals:

public slots:
    void PressCalcolaImporto();
    void PressCalcolaIva();
    void PressCalcolaSpese();
    void PressCalcolaGuadagno();
    void PressCalcolaIvaStato();
};

#endif // ACTIVITYFUNZIONALITAVARIO_H
