#ifndef ACTIVITYSPESADIPENDENTE_H
#define ACTIVITYSPESADIPENDENTE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTimeEdit>
#include <QPushButton>
#include <QCheckBox>
#include "Gestionale_lite/HeaderLogica/societa.h"

class ActivitySpesaDipendente : public QWidget
{
    Q_OBJECT
private:
    Societa* SocietaPropria;
    QLabel* LabelNome;
    QLabel* LabelData;
    QLabel* LabelLuogo;
    QLabel* LabelRetribuzione;
    QLabel* LabelRetribuzione2;
    QLabel* LabelDurataTitolo;
    QLabel* LabelInizio;
    QLabel* LabelFine;
    QLabel* LabelPranzo;
    //QLabel* LabelButton;

    QLineEdit* Nome;
    QLineEdit* Luogo;
    QLineEdit* Retribuzione;

    QCheckBox* Pagato;

    QTimeEdit* Inizio;
    QTimeEdit* Fine;
    QTimeEdit* Pranzo;
    QDateEdit* Data;

    QPushButton* ButtonInserisci;

    //QLabelGrafici
    QLabel* LabelUp;
    QLabel* LabelLeft;
    QLabel* LabelDown;



public:
    explicit ActivitySpesaDipendente(Societa* a,QWidget *parent = 0);

signals:

public slots:
    void AggiungiSpesa();
};

#endif // ACTIVITYSPESADIPENDENTE_H
