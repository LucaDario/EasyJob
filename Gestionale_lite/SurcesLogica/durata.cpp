#include "Gestionale_lite/HeaderLogica/durata.h"

Durata::Durata(QTime a, QTime b, QTime c): inizio(a),fine(b),durata_pranzo(c){}

QTime Durata ::getInizio() const { return inizio;}

QTime Durata ::getFine() const { return fine;}
QTime Durata ::getDurata_pranzo() const { return durata_pranzo;}


QTime Durata::getDurata() const {

    int ora =  fine.hour()-(inizio.hour()+durata_pranzo.hour());
    int minuti=fine.minute()-(inizio.minute()+durata_pranzo.minute());
    if(minuti<0){
        minuti=minuti+60;
        ora--;
    }

    QTime temp(ora,minuti);

    return temp;



    }

void Durata::setInizio(QTime a){
    inizio=a;
}

void Durata::setFine(QTime a){
    fine=a;
}

void Durata ::setDurata_pranzo(QTime a){
    durata_pranzo=a;
}

QString Durata::PrintDurata() const{
    return getDurata().toString();

}

