#ifndef ACTIVITYFUNZIONALITASPESE_H
#define ACTIVITYFUNZIONALITASPESE_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include "Gestionale_lite/HeaderGrafica/widgetspesagenerale.h"
#include "Gestionale_lite/HeaderLogica/societa.h"
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include "Gestionale_lite/HeaderGrafica/widgetspesakm.h"
#include "Gestionale_lite/HeaderGrafica/widgetspesadipendente.h"


class ActivityFunzionalitaSpese : public QWidget
{
    Q_OBJECT
private:
    Societa* SocietaPropria;

    QVBoxLayout* Layout;
    QScrollArea* ScrollaArea;
    QWidget* widget;
    QSpinBox* Mese;
    QSpinBox* Anno;
    QLabel* LabelMese;
    QPushButton* Estrai;
    QVector<QWidget*> ListaWidget;
    QLabel* TotImporto;
    QLabel* TotIva;
    QLabel* TotNonPagato;


public:
    explicit ActivityFunzionalitaSpese(Societa *a, QWidget *parent = 0);

signals:

private slots:
    void Estrazione();
};

#endif // ACTIVITYFUNZIONALITASPESE_H
