#ifndef LISTA_INTROITI_H
#define LISTA_INTROITI_H
#include "Gestionale_lite/HeaderLogica/introiti_lavoratoreore.h"
#include <QVector>



class Lista_introiti{

        friend class iteratore;
    private:



        class nodo{
        public:
            //no costruttore di default
            nodo(Introiti_Lavoratore* x, nodo* p):info(x), next(p){}
            Introiti_Lavoratore* info;
            nodo* next;
            ~nodo();



        };
        nodo* first;   //unico campo dati
        static void distruggi(nodo* a);
public:
        class iteratore{
            friend class Lista_introiti;
        private:
            Lista_introiti::nodo* punt;    //nodo puntato dall iteratore
        public:

            iteratore operator++(int);     //operator ++ post fisso
            bool operator==(iteratore) const;
            bool operator!=(iteratore) const;
            Introiti_Lavoratore* operator*() const;
        }; //fine iteratore

        Lista_introiti();
        ~Lista_introiti();
        void distruggi();
        bool vuota() const;
        void AggiuntaOrdinata(Introiti_Lavoratore* a);
        void TogliIntroito(Introiti_Lavoratore* a);
        Introiti_Lavoratore& TrovaByMese(int a);    //restituisce indirizzo della prima spesa con quel mese

        //metodi iteratore
        iteratore begin() const;
        iteratore end()const;

        double IvaTotale() const;
        double IvaTotale(const int a) const;
        double IntroitiTotali() const;
        double IntroitiTotali(const int a) const;
        double IntroitiTotaliIva()const;
        double IntroitiTotaliIva(const int a)const;
        void eliminaIntroito(Introiti_Lavoratore* a);
        QVector<Introiti_Lavoratore*> EstrazioneMese(unsigned short int a, const int b) const;







    };




#endif // LISTA_INTROITI_H
