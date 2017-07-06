#include "Gestionale_lite/HeaderLogica/spese_dipendente.h"

Spese_Dipendente::Spese_Dipendente(QDateTime f, QString a, QString b, Durata c, double d, bool e): Spesa(f,e),
                                                                                  Nome_dipendente(a),
                                        Durata_giornata(c),Retribuzione_oraria(d),Luogo(b){}

QString Spese_Dipendente::GetNome()const{return Nome_dipendente;}
Durata Spese_Dipendente::GetDurata()const{return Durata_giornata;}
double Spese_Dipendente::GetRetOraria()const{return Retribuzione_oraria;}
void Spese_Dipendente::SetNome(QString a){Nome_dipendente=a;}
void Spese_Dipendente::SetDurata(Durata a){Durata_giornata=a;}
void Spese_Dipendente::SetRetOraria(double a){Retribuzione_oraria=a;}


double Spese_Dipendente::Soldispesa() const{
    QTime temp=Durata_giornata.getDurata();


    return Retribuzione_oraria*temp.hour()+(Retribuzione_oraria*(temp.minute()/60));
}

double Spese_Dipendente::CalcolaIva() const{
    return Soldispesa()*Spesa::IVA; // ricordarsi di sostituire 0.22 con IVA staticae
}

QString Spese_Dipendente::GetInformazione() const{return Luogo;}

QString Spese_Dipendente::PrintDurata() const{
    return Durata_giornata.PrintDurata();
}
