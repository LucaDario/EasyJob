#include "Gestionale_lite/HeaderLogica/spesa_generale.h"

Spesa_generale::Spesa_generale(QDateTime c, double a,QString b,bool e):Spesa(c,e),
                        Soldi_spesa(a), Descrizione(b){}
double Spesa_generale::GetSpesa()const{return Soldi_spesa;}
QString Spesa_generale::GetInformazione() const{return Descrizione;}
void Spesa_generale::SetDescrizione(QString a){Descrizione=a;}
void Spesa_generale::SetSpesa(double a){Soldi_spesa=a;}
double Spesa_generale::Soldispesa() const{
    return Soldi_spesa;
}
double Spesa_generale::CalcolaIva() const{
    return Soldispesa()*Spesa::IVA;

}



