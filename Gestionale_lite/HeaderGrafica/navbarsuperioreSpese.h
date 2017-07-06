#ifndef NAVBARSUPERIORESPESE_H
#define NAVBARSUPERIORESPESE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>


class NavBarSuperioreSpese : public QWidget
{
    Q_OBJECT
private:

    QPushButton* ButtonSpesaGenerle;
    QPushButton* ButtonSpesaKm;
    QPushButton* ButtonSpesaDipendente;
    QLabel* LineaUp;
    QLabel* LineaDx;
public:
    explicit NavBarSuperioreSpese(QWidget *parent = 0);

signals:
   void PressGenerali();
   void PressSpesaKm();
   void PressSpesaDipendente();

public slots:
    void buttonColorDefaut();
private slots:
    void GeneraleClicked();   //Slot intermediari per ovviare al private
    void SpesaKmClicked();
    void SpesaDipendenteClicked();
};

#endif // NAVBARSUPERIORESPESE_H
