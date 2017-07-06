#ifndef NAVBARLATERALE_H
#define NAVBARLATERALE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>




class NavBarLAterale : public QWidget
{


    Q_OBJECT
private:

    QLabel* LineaDx;
    QLabel* LineaDown;
    QLabel* LineaSx;
    QPushButton* informazioni;
    QPushButton* InserisciSpese;
    QPushButton* InserisciEntrata;

    QPushButton* Funzionalita;
public:
    explicit NavBarLAterale(QWidget *parent = 0);

private slots:  //slot intermediari
    void InformazioniClicked();
    void InserisciSpeseClicked();
    void InserisciEntrataClicked();
    void FunzionalitaClicked();

signals:
    void PressInformazioni();
    void PressInserisciSpese();
    void PressInserisciEntrata();
    void PressFunzionalita();








public slots:
    void ChangeInformazioni();
    void ChangeInserisciSpese();
    void ChangeInsrisciEntrata();
    void ChangeFunzionalita();
};

#endif // NAVBARLATERALE_H
