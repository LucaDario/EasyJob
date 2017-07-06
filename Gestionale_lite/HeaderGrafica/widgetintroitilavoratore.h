#ifndef WIDGETINTROITILAVORATORE_H
#define WIDGETINTROITILAVORATORE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "Gestionale_lite/HeaderLogica/societa.h"

class WidgetIntroitiLavoratore : public QWidget
{
    Q_OBJECT
private:
    Societa* SocietaPropria;
    Introiti_LavoratoreOre* PointerIntroiti;
    QLabel* LabelTipo;
    QLabel* LabelImporto;
    QLabel* LabelIva;
    QLabel* LabelNome;
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
    explicit WidgetIntroitiLavoratore(Societa* a,Introiti_LavoratoreOre* b,QWidget *parent = 0);

signals:
    void PressElimina();


public slots:
    void SetPagato();
    void Elimina();
};

#endif // WIDGETINTROITILAVORATORE_H
