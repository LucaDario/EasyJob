#ifndef SPESA_GENERALE_H
#define SPESA_GENERALE_H
#include "Gestionale_lite/HeaderLogica/spesa.h"
#include <QString>



class Spesa_generale: public Spesa{
private:
    QString Descrizione;
    double Soldi_spesa;
public:
    Spesa_generale(QDateTime c, double a, QString b, bool e);
    double GetSpesa() const;
    QString GetInformazione() const;
    void SetDescrizione(QString);
    void SetSpesa(double);
    void Print() const;   // da impementre
    double Soldispesa () const;
    double CalcolaIva() const;



};

#endif // SPESA_GENERALE_H
