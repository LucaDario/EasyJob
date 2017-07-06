#include "Gestionale_lite/HeaderLogica/societa.h"

Societa::Societa(QDateTime data_creazione, QString nome_Societa, QString Piva, QString Descrizione_societa,
                 Lista_Spese *elenco_Spese, Lista_introiti *elenco_Introiti, QString Nazionalita) : Data_creazione(data_creazione),
                  Nome_Societa(nome_Societa), pIva(Piva),descrizione_societa(Descrizione_societa), elenco_spese(elenco_Spese),
                  elenco_introiti(elenco_Introiti),nazionalita(Nazionalita){}


QDateTime Societa::GetDataCreazione() const{return Data_creazione;}
QString Societa::GetNomeSocieta() const{return Nome_Societa;}
QString Societa::GetPiva() const{return pIva;}
QString Societa::GetDescrizioneSocieta() const{return descrizione_societa;}
void Societa::SetDataCreazione(const QDateTime &data){Data_creazione=data;}
void Societa::SetNomeSocieta(const QString &nome){Nome_Societa=nome;}
void Societa::SetPiva(const QString &Piva){pIva=Piva;}
void Societa::SetDescrizioneSocieta(const QString &descrizione){descrizione_societa=descrizione;}

void Societa::AggiuntaSpesaOrdinata(Spesa *spesa){
    elenco_spese->AggiuntaOrdinata(spesa);
}
void Societa::AggiuntaIntroitoOrdinato(Introiti_Lavoratore *introito){
    elenco_introiti->AggiuntaOrdinata(introito);
}


double Societa::GetIvaSpese() const{return elenco_spese->IvaTotale();}
double Societa::GetIvaSpese(const int a) const{return elenco_spese->IvaTotale(a);}
double Societa::GetSoldiSpeseTotali() const{return elenco_spese->SpesaTotale();}
double Societa::GetSoldiSpeseTotali(const int a) const{return elenco_spese->SpesaTotale(a);}
double Societa::GetSoldiSpeseIvaTotali() const{return elenco_spese->SpesaTotaleIva();}
double Societa::GetSoldiSpeseIvaTotali(const int a) const{return elenco_spese->SpesaTotaleIva(a);}

double Societa::GetIvaIntroiti() const{return elenco_introiti->IvaTotale();}
double Societa::GetIvaIntroiti(const int a) const{return elenco_introiti->IvaTotale(a);}
double Societa::GetIntroitiTotali() const{return elenco_introiti->IntroitiTotali();}
double Societa::GetIntroitiTotali(const int a) const{return elenco_introiti->IntroitiTotali(a);}
double Societa::GetIntroitiIvaTotali() const{return elenco_introiti->IntroitiTotaliIva();}
double Societa::GetIntroitiIvaTotali(const int a) const{return elenco_introiti->IntroitiTotaliIva(a);}

QString Societa::GetNazionalita() const{return nazionalita;}
Lista_Spese* Societa::GetListaSpese() const{
    return elenco_spese;
}

QVector<Spesa *> Societa::EstraiSpeseByMese(unsigned short a, const int b){
    return elenco_spese->EstrazioneMese(a,b);
}

void Societa::EliminaSpesa(Spesa *a){
    elenco_spese->ElimnaSpesa(a);
}

void Societa::EliminaIntroito(Introiti_Lavoratore *a){
    elenco_introiti->eliminaIntroito(a);
}
QVector<Introiti_Lavoratore *> Societa::EstraiIntroitoByMese(unsigned short a, const int b){
    return elenco_introiti->EstrazioneMese(a,b);
}

double Societa::GetIvaStato() const{
    return elenco_introiti->IvaTotale()-elenco_spese->IvaTotale();
}

Societa::~Societa(){
    delete elenco_introiti;
    delete elenco_spese;


}
