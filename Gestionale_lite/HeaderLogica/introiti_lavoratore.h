#ifndef INTROITI_LAVORATORE_H
#define INTROITI_LAVORATORE_H
#include<QDateTime>


class Introiti_Lavoratore{
private:
    QDateTime DataLavoro;
    bool Pagato;



public:

    Introiti_Lavoratore(QDateTime a,bool e);  //costruttore

    QDateTime GetData_Lavoro() const;
    void SetData_Lavoro(QDateTime);

    virtual double GetIva() const=0;
    virtual double GetTotaleIvaEsclusa () const=0;
    virtual double GetTotaleIvaInclusa() const=0;
    virtual ~Introiti_Lavoratore(){}
    double GetPagato() const;
    void changePagato();

};

#endif // INTROITI_LAVORATORE_H
