#ifndef INTROITI_LAVORATOREORE_H
#define INTROITI__H
#include <QString>
#include <Gestionale_lite/HeaderLogica/durata.h>
#include <Gestionale_lite/HeaderLogica/introiti_lavoratore.h>





class Introiti_LavoratoreOre:public Introiti_Lavoratore{
private:

    Durata Durata_lavoro;
    QString Nome_Cliente;
    QString Luogo;

    double Retribuzione_oraria;

public:
    Introiti_LavoratoreOre(QDateTime data, Durata durata, QString nome , QString luogo, bool pagato, double retribuzione);

    Durata GetDurataLavoro() const;
    QString GetCliente() const;
    QString GetLuogo() const;
    double GetIva() const;
    double GetTotaleIvaEsclusa () const;
    double GetTotaleIvaInclusa() const;
    double GetRetOraria() const;
    void SetRetOraria(double a);
    void SetDurata(Durata a);
    void SetCliente(QString a);






};

#endif // INTROITI_INTESTATARIO_H
