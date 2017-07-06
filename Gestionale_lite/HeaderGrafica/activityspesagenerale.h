#ifndef ACTIVITYSPESAGENERALE_H
#define ACTIVITYSPESAGENERALE_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <Gestionale_lite/HeaderLogica/societa.h>
#include <QDateEdit>
#include <QCheckBox>

class ActivitySpesaGenerale : public QWidget
{
    Q_OBJECT
private:

    Societa* SocietaPropria;
    QLabel* LabelText1;
    QLabel* LabelText2;
    QLabel* LabelTExt3;
    QPushButton* ButtonInserisci;
    QLineEdit* QuantitaSpesa;
    QLineEdit* Descrizione;
    QDateEdit* DataEdit;
    QCheckBox* Pagato;

public:
    explicit ActivitySpesaGenerale(Societa* a,QWidget *parent=0);


signals:

private slots:
    void aggiungiSpesaGenerale();


};

#endif // ACTIVITYSPESAGENERALE_H
