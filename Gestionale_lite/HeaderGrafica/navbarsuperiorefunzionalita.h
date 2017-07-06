#ifndef NAVBARSUPERIOREFUNZIONALITA_H
#define NAVBARSUPERIOREFUNZIONALITA_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class NavBarSuperioreFunzionalita : public QWidget
{
    Q_OBJECT
private:


    QPushButton* ButtonSpesa;
    QPushButton* ButtonIntroiti;
    QPushButton* ButtonVario;
    QLabel* LineaUp;
    QLabel* LineaDx;

public:
    explicit NavBarSuperioreFunzionalita(QWidget *parent = 0);



public slots:
    void ButtonColorDefault();
private slots:
    void SpesaClicked();   //Slot intermediari per ovviare al private
    void IntroitiClicked();
    void VarioClicked();


signals:
    void PressSpese();
    void PressIntroiti();
    void PressVario();


};

#endif // NAVBARSUPERIOREFUNZIONALITA_H
