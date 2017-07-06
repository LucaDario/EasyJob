#ifndef TITOLOSUPERIORE_H
#define TITOLOSUPERIORE_H

#include <QWidget>
#include <QString>
#include <QLabel>

class TitoloSuperiore : public QWidget
{
    Q_OBJECT
private:
    QString NomeInt;
    QLabel* Nome;
    QLabel* LineaDown;
    QLabel* LineaSx;
    QLabel* LineaUp;
    QLabel* LineaDx;

public:
    explicit TitoloSuperiore(QString a=0,QWidget *parent = 0);

signals:

public slots:
};

#endif // TITOLOSUPERIORE_H
