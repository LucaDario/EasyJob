#include "Gestionale_lite/HeaderLogica/introiti_lavoratoreore.h"


Introiti_LavoratoreOre::Introiti_LavoratoreOre(QDateTime data, Durata durata, QString nome, QString luogo, bool pagato,double retribuzione):
                                 Introiti_Lavoratore(data,pagato),Durata_lavoro(durata), Nome_Cliente(nome),
                                 Luogo(luogo), Retribuzione_oraria(retribuzione) {}



Durata Introiti_LavoratoreOre::GetDurataLavoro() const{return Durata_lavoro;}

QString Introiti_LavoratoreOre::GetCliente() const{return Nome_Cliente;}

QString Introiti_LavoratoreOre::GetLuogo() const{return Luogo;}


void Introiti_LavoratoreOre::SetRetOraria(double a){Retribuzione_oraria=a;}



void Introiti_LavoratoreOre::SetDurata(Durata a){Durata_lavoro=a;}

void Introiti_LavoratoreOre::SetCliente(QString a){Nome_Cliente=a; }


double Introiti_LavoratoreOre::GetIva() const{
    return ((Retribuzione_oraria*Durata_lavoro.getDurata().hour())+(Retribuzione_oraria*
                                                                    (Durata_lavoro.getDurata().minute()/60)))*0.22;}
double Introiti_LavoratoreOre::GetTotaleIvaEsclusa() const{
    return ((Retribuzione_oraria*Durata_lavoro.getDurata().hour())+(Retribuzione_oraria*
                                                                    (Durata_lavoro.getDurata().minute()/60)));
}

double Introiti_LavoratoreOre::GetTotaleIvaInclusa() const{
    return GetTotaleIvaEsclusa()+GetIva();
}



