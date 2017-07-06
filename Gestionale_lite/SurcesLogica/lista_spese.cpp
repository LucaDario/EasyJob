
#include "Gestionale_lite/HeaderLogica/lista_spese.h"

//costruttori


Lista_Spese::Lista_Spese(){first=0;}




    Lista_Spese::iteratore Lista_Spese::iteratore::operator ++(int){


        if(punt) punt=punt->next;
        return *this; /// modificato
    }



    Lista_Spese::iteratore Lista_Spese::begin() const{
        iteratore aux;
        aux.punt=first;
        return aux;
    }


    Lista_Spese::iteratore Lista_Spese::end() const{
        iteratore aux;
        aux.punt=0;
        return aux;
    }


    double Lista_Spese::IvaTotale()const{                    //ritorna l' iva totale
        double temp=0;
        for(Lista_Spese::iteratore it=begin(); it!=end();it++)
            temp=(temp+(*it)->CalcolaIva());

        return temp;

    }
    double Lista_Spese::IvaTotale(const int a) const{
        double temp=0;
        for(Lista_Spese::iteratore it=begin(); it!=end();it++)
            if((*it)->GetData_immissione().date().year()==a)temp=(temp+(*it)->CalcolaIva());

        return temp;

    }

    double Lista_Spese::SpesaTotale()const{                                //ritorna la spesa senza Iva
        double temp=0;
        for(Lista_Spese::iteratore it=begin(); it!=end();it++)
            temp=(temp+(*it)->Soldispesa());

        return temp;

    }
    double Lista_Spese::SpesaTotale(const int a)const{                                //ritorna la spesa senza Iva
        double temp=0;
        for(Lista_Spese::iteratore it=begin(); it!=end();it++)
            if((*it)->GetData_immissione().date().year()==a)temp=(temp+(*it)->Soldispesa());

        return temp;

    }

    double Lista_Spese::SpesaTotaleIva() const{
        return SpesaTotale()+IvaTotale();
    }
    double Lista_Spese::SpesaTotaleIva(const int a) const{
        return SpesaTotale(a)+IvaTotale(a);
    }

    Lista_Spese::~Lista_Spese(){
        distruggi(first);
    }

    void Lista_Spese::distruggi(nodo* a){
        if(!a){
            return;
        }

        else  Lista_Spese::distruggi(a->next);
            delete a;                //chiamata ricorsiva al ritorno del distruttore di nodo;
    }

    Spesa* Lista_Spese::iteratore::operator *() const{
        return punt->info;
    }

    bool Lista_Spese::iteratore::operator ==(iteratore i) const{
        return punt==i.punt;
    }


    bool Lista_Spese::iteratore::operator !=(iteratore i ) const{
        return punt!=i.punt;
    }


    void Lista_Spese::AggiuntaOrdinata(Spesa *a){
        Lista_Spese::iteratore it=begin();
        if(begin().punt==0 || (*it)->GetData_immissione() > a->GetData_immissione()){
            nodo*temp=first;
            nodo* b=new nodo(a,temp);
            first=b;
        }

        else{
                bool esci=0;
            for(;it!=end() && esci==0;it++){
                if(it.punt->next==end().punt|| it.punt->next->info->GetData_immissione()
                        > a->GetData_immissione()){
                    //se quello dopo e zero O quello dopo ha una data maggiore
                    nodo* temp=it.punt->next;
                    nodo* b=new nodo(a,temp);
                    it.punt->next=b;
                    esci=1;

                }


            }
        }
    }


Lista_Spese::nodo::~nodo(){

    delete info;
}

QVector<Spesa*> Lista_Spese::EstrazioneMese(unsigned short a, const int b) const{

    QVector<Spesa*> temp;

    unsigned short int d;
    int e;
    for(Lista_Spese::iteratore it=begin();it!=end();it++){
        d=(*it)->GetData_immissione().date().month();
         e= (*it)->GetData_immissione().date().year();

        if(a==d && e==b )  temp.push_back(*it);

    }
    return temp;
}


void Lista_Spese::ElimnaSpesa(Spesa* a){
    if(first->info==a){
        nodo* temp=first->next;
        delete first;
        first=temp;
    }

    else{
        bool esci=0;
        for(Lista_Spese::iteratore it=begin();it!=end() && esci==0;it++){
            if(it.punt->next->info){
                if(it.punt->next->info==a){
                    nodo* temp=it.punt->next->next;
                    delete it.punt->next;
                    it.punt->next=temp;
                    esci=1;
                }

            }

        }
    }






}











