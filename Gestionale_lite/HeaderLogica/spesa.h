#ifndef SPESA_H
#define SPESA_H
#include <QDateTime>


class Spesa{
private:
    QDateTime Data_immissione;
    bool pagato;


public:

    Spesa(QDateTime a,bool e);
    QDateTime GetData_immissione() const;
    void SetData_immissione();

    //metodi virtuali puri

    virtual double Soldispesa() const=0;
    virtual double CalcolaIva() const=0;
    double SoldispesaIva() const;

    virtual ~Spesa(){}
    virtual QString GetInformazione() const=0;
    bool GetPagato() const;
    void changePagato();
    static double const IVA ;



};


#endif // SPESA_H
