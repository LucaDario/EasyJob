#ifndef SPESA_KM_H
#define SPESA_KM_H
#include "Gestionale_lite/HeaderLogica/spesa.h"
#include <QString>

class Spesa_Km : public Spesa{
private:
    int km_percorsi;

    double PrezzoGasolio;
    double Km_litro;
    QString Luogo;

public:
    Spesa_Km(QDateTime f, int Km_percorsi, double prezzoGasolio, double km_litro, QString luogo, bool e);            //costruttore

    int GetKm_percorsi() const;

    void SetKmPercorsi(int a);

    double Soldispesa() const;
    double CalcolaIva() const;
    QString GetInformazione() const;



};



#endif // SPESA_KM_H
