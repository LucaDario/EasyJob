#ifndef NAVBARSUPERIOREINFO_H
#define NAVBARSUPERIOREINFO_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>


class NavBarSuperioreInfo : public QWidget
{
    Q_OBJECT
private:


    QPushButton* Info;
    QLabel* LineaUp;
    QLabel* LineaDx;

public:
    explicit NavBarSuperioreInfo(QWidget *parent = 0);


signals:
    void PressInfo();



public slots:
    void InfoClicked();

};

#endif // NAVBARSUPERIOREINFO_H
