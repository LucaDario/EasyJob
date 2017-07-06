#ifndef LISTA_SPESE_H
#define LISTA_SPESE_H
#include "Gestionale_lite/HeaderLogica/spesa_generale.h"
#include "Gestionale_lite/HeaderLogica/spesa_km.h"
#include "Gestionale_lite/HeaderLogica/spese_dipendente.h"
#include <QVector>



class Lista_Spese{
    friend class iteratore;
private:



    class nodo{
    public:
        //no costruttore di default
        nodo(Spesa* x, nodo* p):info(x), next(p){}


        Spesa* info;
        nodo* next;
        ~nodo();



    };
    nodo* first;   //unico campo dati
    static void distruggi(nodo* a);
public:

    class iteratore{
        friend class Lista_Spese;
    private:
        Lista_Spese::nodo* punt;    //nodo puntato dall iteratore
    public:

        iteratore operator++(int);     //operator ++ post fisso
        bool operator==(iteratore) const;
        bool operator!=(iteratore) const;
        Spesa* operator*() const;
    }; //fine iteratore

    Lista_Spese();
    ~Lista_Spese();

    bool vuota() const;
    void AggiuntaOrdinata(Spesa* a);
    void TogliIntroito(Spesa* a);

    QVector<Spesa*> EstrazioneMese(unsigned short int a, const int b) const;
    //metodi iteratore
    iteratore begin() const;
    iteratore end()const;
    //Spesa& operator[](iteratore it) const;
    double IvaTotale() const;
    double IvaTotale(const int a) const;
    double SpesaTotale() const;
    double SpesaTotale(const int a) const;
    double SpesaTotaleIva() const;
    double SpesaTotaleIva(const int a) const;
    void ElimnaSpesa(Spesa *a);







};

#endif // LISTA_SPESE_H
