#ifndef DURATA_H
#define DURATA_H
#include <QTime>



class Durata{
private:
    QTime inizio;
    QTime fine;
    QTime durata_pranzo;

public:

    Durata(QTime a  , QTime b  , QTime c  );

    QTime getInizio() const;
    QTime getFine() const;
    QTime getDurata_pranzo() const;

    QTime getDurata() const;  //ritorna la durata complessiva al nettto della pausa pranzo;

    void setInizio(QTime a);
    void setFine(QTime a);
    void setDurata_pranzo(QTime a);
    QString PrintDurata() const;


};





#endif // DURATA_H
