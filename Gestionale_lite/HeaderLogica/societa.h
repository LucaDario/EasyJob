#ifndef SOCIETA_H
#define SOCIETA_H
#include "Gestionale_lite/HeaderLogica/lista_spese.h"
#include "Gestionale_lite/HeaderLogica/lista_introiti.h"


class Societa{
private:
    QString nazionalita;
    QDateTime Data_creazione;
    QString Nome_Societa;
    QString pIva;
    QString descrizione_societa;
    Lista_Spese* elenco_spese;
    Lista_introiti* elenco_introiti;






public:
    Societa(QDateTime data_creazione,QString nome_Societa,QString Piva, QString Descrizione_societa,
                                      Lista_Spese* elenco_Spese,Lista_introiti* elenco_Introiti,QString Nazionalita); //costruttore


    QDateTime GetDataCreazione() const;
    QString GetNomeSocieta() const;
    QString GetPiva() const;
    QString GetDescrizioneSocieta() const;
    QString GetNazionalita() const;
    void SetDataCreazione(const QDateTime& data);
    void SetNomeSocieta(const QString& nome);
    void SetPiva(const QString& Piva);
    void SetDescrizioneSocieta(const QString& descrizione);

    void AggiuntaSpesaOrdinata(Spesa* spesa);
    void AggiuntaIntroitoOrdinato(Introiti_Lavoratore* introito);

    double GetIvaSpese() const;
    double GetIvaSpese(const int a) const;
    double GetSoldiSpeseTotali() const;
    double GetSoldiSpeseTotali(const int a) const;
    double GetSoldiSpeseIvaTotali() const;
    double GetSoldiSpeseIvaTotali(const int a) const;

    double GetIvaIntroiti() const;
    double GetIvaIntroiti(const int a) const;
    double GetIntroitiTotali() const;
    double GetIntroitiTotali(const int a) const;
    double GetIntroitiIvaTotali() const;
    double GetIntroitiIvaTotali(const int a) const;
    Lista_Spese* GetListaSpese() const;

    QVector<Spesa*> EstraiSpeseByMese(unsigned short int a, const int b);
    void EliminaSpesa(Spesa* a);
    void EliminaIntroito(Introiti_Lavoratore* a);
    QVector<Introiti_Lavoratore*> EstraiIntroitoByMese(unsigned short int a, const int b);
    double GetIvaStato() const;
    ~Societa();


};

#endif // SOCIETA_H
