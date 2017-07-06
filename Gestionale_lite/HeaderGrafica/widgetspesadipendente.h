#ifndef WIDGETSPESADIPENDENTE_H
#define WIDGETSPESADIPENDENTE_H

#include <QWidget>
#include "Gestionale_lite/HeaderLogica/societa.h"
#include <QLabel>
#include <QPushButton>

class WidgetSpesaDipendente : public QWidget
{
    Q_OBJECT
private:
    Societa* SocietaPropria;
    Spese_Dipendente* PointerSpesa;
    QLabel* LabelTipo;
    QLabel* LabelImporto;
    QLabel* LabelIva;
    QLabel* LabelCausale;
    QLabel* LabelPagato;
    QLabel* LabelData;
    QPushButton* ButtonElimina;
    QPushButton* ButtonSetPagato;
    QWidget* ActivityPadre;

    //LabelGrafici
    QLabel* up;
    QLabel* down;
    QLabel* left;
    QLabel* right;
public:
    explicit WidgetSpesaDipendente(Societa* a, Spese_Dipendente* b,QWidget *parent = 0);

signals:
    void PressElimina();


private slots:
    void SetPagato();
    void Elimina();
};

#endif // WIDGETSPESADIPENDENTE_H
