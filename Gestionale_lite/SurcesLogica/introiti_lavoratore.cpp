#include "Gestionale_lite/HeaderLogica/introiti_lavoratore.h"



Introiti_Lavoratore::Introiti_Lavoratore(QDateTime a, bool e):DataLavoro(a),Pagato(e){}


QDateTime Introiti_Lavoratore::GetData_Lavoro() const{
    return DataLavoro;
}

void Introiti_Lavoratore::SetData_Lavoro(QDateTime a){
    DataLavoro=a;
}

double Introiti_Lavoratore::GetPagato() const{return Pagato;}

void Introiti_Lavoratore::changePagato(){Pagato=(Pagato+1)%2;}
