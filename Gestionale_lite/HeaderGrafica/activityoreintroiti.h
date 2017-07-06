#ifndef ACTIVITYOREINTROITI_H
#define ACTIVITYOREINTROITI_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QTimeEdit>
#include <Gestionale_lite/HeaderLogica/societa.h>
#include <QCheckBox>

class ActivityOreIntroiti : public QWidget
{
    Q_OBJECT
private:
    Societa* SocietaPropria;

    QLabel* LabelNome;
    QLabel* LabelData;
    QLabel* LabelLuogo;
    QLabel* LabelRetribuzione;
    QLabel* LabelRetribuzione2;
    QLabel* LabelInizio;
    QLabel* LabelFine;
    QLabel* LabelPranzo;
    QLabel* LabelDurataTitolo;
    //Date
    QTimeEdit* Inizio;
    QTimeEdit* Fine;
    QTimeEdit* Pranzo;
    //Data
    QDateEdit* Data;


    //LabelGrafifi
    QLabel* LabelUp;
    QLabel* LabelLeft;
    QLabel* LabelDown;

    //LineEdit
    QLineEdit* Nome;
    QLineEdit* Luogo;
    QLineEdit* Retribuzione;

    QCheckBox* Pagato;

    QPushButton* ButtonInserisci;

public:
    explicit ActivityOreIntroiti(Societa* a,QWidget *parent = 0);

signals:

private slots:
    void WhenPressInserisci();
};

#endif // ACTIVITYOREINTROITI_H
