#include "Gestionale_lite/HeaderLogica/lista_introiti.h"

Lista_introiti::Lista_introiti(){first=0;}   //overload di costruttore standard




Lista_introiti::iteratore Lista_introiti::iteratore::operator ++(int){   //overload di operatore ++postfisso


    if(punt) punt=punt->next;
    return *this;
}

Introiti_Lavoratore* Lista_introiti::iteratore::operator *() const {return punt->info;}
Lista_introiti::iteratore Lista_introiti::begin() const{       //ritorna un itertore con campo punt==al primo elemento
    iteratore aux;                                                         //della lista
    aux.punt=first;
    return aux;
}



Lista_introiti::iteratore Lista_introiti::end() const{        //ritorna un itertore con campo punt==al ultimo elemento
    iteratore aux;                                                                  //della lista
    aux.punt=0;
    return aux;
}





double Lista_introiti::IntroitiTotali()const{                                //ritorna la spesa senza Iva
    double temp=0;
    for(Lista_introiti::iteratore it=begin(); it!=end();it++)
        temp=(temp+(*it)->GetTotaleIvaEsclusa());

    return temp;

}
double Lista_introiti::IntroitiTotali(const int a)const{                                //ritorna la spesa senza Iva
    double temp=0;
    for(Lista_introiti::iteratore it=begin(); it!=end();it++)
        if((*it)->GetData_Lavoro().date().year()==a) temp=(temp+(*it)->GetTotaleIvaEsclusa());

    return temp;

}

double Lista_introiti::IvaTotale() const{               //ritorna l' iva Totale
    double temp=0;
    for(Lista_introiti::iteratore it=begin(); it!=end();it++)
        temp=(temp+(*it)->GetIva());

    return temp;

}
double Lista_introiti::IvaTotale(const int a ) const{               //ritorna l' iva Totale
    double temp=0;
    for(Lista_introiti::iteratore it=begin(); it!=end();it++)
        if((*it)->GetData_Lavoro().date().year()==a) temp=temp+((*it)->GetIva());

    return temp;

}

double Lista_introiti::IntroitiTotaliIva() const{             ////ritorna la spesa con Iva
    return IvaTotale()+IntroitiTotali();

}
double Lista_introiti::IntroitiTotaliIva(const int a) const{             ////ritorna la spesa con Iva
    return IvaTotale(a)+IntroitiTotali(a);

}
Lista_introiti::~Lista_introiti(){        //overload della delete standard
    distruggi(first);

}

void Lista_introiti::distruggi(nodo* a){//ditruggi che viene chiamato dalla delete di Lista Introiti

    if(!a){
        return;
    }

    else  Lista_introiti::distruggi(a->next);
        delete a;                //chiamata ricorsiva al ritorno del distruttore di nodo che chiama il ditruttore della parte info;
}




bool Lista_introiti::iteratore::operator ==(iteratore i) const{
    return punt==i.punt;
}


bool Lista_introiti::iteratore::operator !=(iteratore i ) const{
    return punt!=i.punt;
}

void Lista_introiti::AggiuntaOrdinata(Introiti_Lavoratore *a){
    if(!begin().punt || begin().punt->info->GetData_Lavoro() > a->GetData_Lavoro()){
        nodo*temp=first;
        nodo* b=new nodo(a,temp);
        first=b;
    }

    else{
            bool esci=0;
        for( Lista_introiti::iteratore it=begin();it!=end() && esci==0;it++){
            if(it.punt->next==end().punt||it.punt->next->
                info->GetData_Lavoro() > a->GetData_Lavoro()){
                //se quello dopo e zero O quello dopo ha una data maggiore
                nodo* temp=it.punt->next;
                nodo* b=new nodo(a,temp);
                it.punt->next=b;
                esci=1;

            }


        }
    }
}
Lista_introiti::nodo::~nodo(){


    delete info;




}

void Lista_introiti::eliminaIntroito(Introiti_Lavoratore *a){
    if(first->info==a){
        nodo* temp=first->next;
        delete first;
        first=temp;
    }

    else{
        bool esci=0;
        for(Lista_introiti::iteratore it=begin();it!=end() && esci==0;it++){
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

QVector<Introiti_Lavoratore*> Lista_introiti::EstrazioneMese(unsigned short a, const int b) const{

    QVector<Introiti_Lavoratore*> temp;

    unsigned short int d;
    int e;
    for(Lista_introiti::iteratore it=begin();it!=end();it++){
        d=(*it)->GetData_Lavoro().date().month();
         e= (*it)->GetData_Lavoro().date().year();

        if(a==d && e==b )  temp.push_back(*it);

    }
    return temp;
}

