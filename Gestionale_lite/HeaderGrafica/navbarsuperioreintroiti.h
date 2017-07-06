#ifndef NAVBARSUPERIOREINTROITI_H
#define NAVBARSUPERIOREINTROITI_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class NavBarSuperioreIntroiti : public QWidget
{
    Q_OBJECT
private:
    QPushButton* ButtonEntrataIntestatario;
    QLabel* LineaUp;
    QLabel* LineaDx;
public:
    explicit NavBarSuperioreIntroiti(QWidget *parent = 0);

signals:
    void PressLavoratoreOre();

private slots:
    void EntrataIntestatarioClicked();
};

#endif // NAVBARSUPERIOREINTROITI_H
