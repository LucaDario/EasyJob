#ifndef WIDGETSPESAKM_H
#define WIDGETSPESAKM_H

#include <QWidget>
#include "Gestionale_lite/HeaderLogica/societa.h"
#include <QLabel>
#include <QPushButton>

class WidgetSpesaKm : public QWidget
{
    Q_OBJECT
private:
    Societa* SocietaPropria;
    Spesa_Km* PointerSpesa;
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
    explicit WidgetSpesaKm(Societa* a, Spesa_Km *b, QWidget *parent = 0);

signals:
    void PressElimina();

private slots:
    void SetPagato();
    void Elimina();
};

#endif // WIDGETSPESAKM_H
