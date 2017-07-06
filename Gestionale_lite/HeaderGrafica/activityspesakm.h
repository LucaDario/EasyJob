#ifndef ACTIVITYSPESAKM_H
#define ACTIVITYSPESAKM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "Gestionale_lite/HeaderLogica/societa.h"
#include <QDateEdit>
#include <QCheckBox>


class ActivitySpesaKm : public QWidget
{
    Q_OBJECT
private:
    Societa* SocietaPropria;

    QLabel* LabelLuogo;
    QLabel* LabelKm;
    QLabel* LabelKMLMezzo;
    QLabel* LabelPrezzoCarburante;
    QLabel* LabelData;

    QDateEdit* DataEdit;
    QPushButton* ButtonInserisci;
    QLineEdit* TextKMPercorsi;
    QLineEdit* TextKMlitro;
    QLineEdit* TextPrezzoGasolio;
    QLineEdit* TextLuogo;
    QCheckBox* Pagato;

public:
    explicit ActivitySpesaKm(Societa* a,QWidget *parent = 0);

signals:

private slots:
    void AggiungiSpesaKm();
};

#endif // ACTIVITYSPESAKM_H
