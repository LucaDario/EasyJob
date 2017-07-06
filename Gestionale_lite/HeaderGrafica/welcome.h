#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include "Gestionale_lite/HeaderLogica/societa.h"
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include "Gestionale_lite/HeaderGrafica/mainactivity.h"
#include "Gestionale_lite/HeaderGrafica/infosocieta.h"
#include<QRect>


class Welcome : public QWidget
{
    Q_OBJECT
private:
    QLabel* Titolo;

      QLabel* PartitaIva;
      QLabel* Descrizione;
    QLabel* NomeSocieta;
    QLabel* LabelNomeSocieta;
    QLineEdit* TextPiva;
    QLineEdit* TextNazionalita;
    QLineEdit* TextNomeSocieta;
    QTextEdit* TextDescrizione;
    QPushButton* inserisci;
    QLabel* Avviso1;
    QLabel* Avviso2;
     QLabel* Avviso3;
    bool PrimoErrore;
public:
    explicit Welcome(QWidget *parent = 0);
    Societa* VerificaDati();
    Societa* ScaricaDati() const;
    void InserisciErrore();


signals:

public slots:
    void WhenElimina();

    void WhenClickedInserisci();
};

#endif // WELCOME_H
