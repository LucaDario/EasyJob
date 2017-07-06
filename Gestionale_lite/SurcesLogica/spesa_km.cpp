#include "Gestionale_lite/HeaderLogica/spesa_km.h"

Spesa_Km::Spesa_Km(QDateTime f, int Km_percorsi, double prezzoGasolio, double km_litro, QString luogo,bool e):Spesa(f,e),km_percorsi(Km_percorsi),PrezzoGasolio(prezzoGasolio),
                                                Km_litro(km_litro),Luogo(luogo){ }

int Spesa_Km::GetKm_percorsi()const {return km_percorsi;}

void Spesa_Km::SetKmPercorsi(int a){ km_percorsi=a;}

double Spesa_Km::Soldispesa()const{

    return ((km_percorsi/Km_litro)*PrezzoGasolio)/(1+Spesa::IVA);

}





double Spesa_Km::CalcolaIva() const{
    return Soldispesa()*Spesa::IVA;
}

QString Spesa_Km::GetInformazione() const{return Luogo;}
