#ifndef ACTIVITYFUNZIONALITAINTROITI_H
#define ACTIVITYFUNZIONALITAINTROITI_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include "Gestionale_lite/HeaderGrafica/widgetspesagenerale.h"
#include "Gestionale_lite/HeaderLogica/societa.h"
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include "Gestionale_lite/HeaderGrafica/widgetspesakm.h"
#include "Gestionale_lite/HeaderGrafica/widgetintroitilavoratore.h"

class ActivityFunzionalitaIntroiti : public QWidget
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
    explicit ActivityFunzionalitaIntroiti(Societa* a=0,QWidget *parent = 0);

signals:

private slots:
    void Estrazione();
};

#endif // ACTIVITYFUNZIONALITAINTROITI_H
