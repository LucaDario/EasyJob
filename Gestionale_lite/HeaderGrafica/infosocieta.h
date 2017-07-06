#ifndef INFOSOCIETA_H
#define INFOSOCIETA_H

#include <QWidget>


#include "Gestionale_lite/HeaderGrafica/navbarlaterale.h"
#include <QPushButton>

#include "Gestionale_lite/HeaderLogica/societa.h"


class InfoSocieta : public QWidget
{
    Q_OBJECT
    friend class NavBarLAterale;

private:


    QPushButton* ButtonElimina;
    QLabel* DataCreazione;
    QLabel* NomeSocieta;
    QLabel* Nazionalita;
    QLabel* NPiva;
    QLabel* Descrizione;
    QString VerificaNazionlita(QString a) const;

    Societa* SocietaPropria;
    QLabel* LabelDataCreazione;
    QLabel* LabelNome;
    QLabel* LabelNazionalita;
    QLabel* LabelPiva;
    QLabel* LabelDescrizione1;
    QLabel* LabelDescrizione;





public:
    explicit InfoSocieta(Societa* a,QWidget *parent = 0);


signals:
    void ApriNuovaSessione();

private slots:
    void EliminaSocieta();

};

#endif // INFOSOCIETA_H
