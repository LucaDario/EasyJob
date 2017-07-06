#ifndef SPESE_DIPENDENTE_H
#define SPESE_DIPENDENTE_H
#include "Gestionale_lite/HeaderLogica/durata.h"
#include "Gestionale_lite/HeaderLogica/spesa.h"
#include <QString>

class Spese_Dipendente: public Spesa{
private:
    QString Nome_dipendente;
    QString Luogo;
    Durata Durata_giornata;
    double Retribuzione_oraria;

public:
    Spese_Dipendente(QDateTime f, QString a, QString b, Durata c, double d, bool e);
    QString GetNome() const;
    Durata GetDurata() const;
    double GetRetOraria() const;
    void SetNome(QString a);
    void SetDurata(Durata a);
    void SetRetOraria(double a);
    double Soldispesa() const;

     double CalcolaIva() const;
     QString GetInformazione() const;
     QString PrintDurata() const;

};

#endif // SPESE_DIPENDENTE_H
