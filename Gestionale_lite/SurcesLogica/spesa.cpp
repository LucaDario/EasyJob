#include "Gestionale_lite/HeaderLogica/spesa.h"


const double  Spesa::IVA=0.22;  //iva statica pubblica
QDateTime Spesa::GetData_immissione() const{
    return Data_immissione;
}

Spesa::Spesa(QDateTime a, bool e):Data_immissione(a),pagato(e){}


double Spesa::SoldispesaIva() const{
    return Soldispesa()+CalcolaIva();

}
bool Spesa::GetPagato() const{return pagato;}


void Spesa::changePagato(){pagato=(pagato+1)%2;}
