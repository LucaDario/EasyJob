#ifndef WIDGETSPESAGENERALE_H
#define WIDGETSPESAGENERALE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <Gestionale_lite/HeaderLogica/societa.h>
#include <QWidget>


class WidgetSpesaGenerale : public QWidget
{
    Q_OBJECT
private:
    Societa* SocietaPropria;
    Spesa_generale* PointerSpesa;
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
    explicit WidgetSpesaGenerale(Societa* a, Spesa_generale* b,QWidget *parent = 0);

signals:
    void PressElimina();


private slots:
    void SetPagato();
    void Elimina();
};

#endif // WIDGETSPESAGENERALE_H
