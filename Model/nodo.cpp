#include "nodo.h"
template <class T>
T nodo<T>::getInfo() const
{
    return info;
}

template <class T>
nodo<T>* nodo<T>::getNext() const
{
    return next;
}
template <class T>
nodo<T>* nodo<T>::getPrev() const
{
    return prev;
}

template<class T>
void nodo<T>::inserisci(nodo* v,const T t){
    first = new nodo(t, nullptr,first);
    if(last == nullptr){
        last = first;
    }
    if(first->next != nullptr){
        (first->next)->prev = first;
    }
}

template<class T>
bool nodo<T>::cerca(nodo *v, T c){
    if(!v){
        return false;
    }
    if(v->info.getTarga() == c.getTarga()){
        return true;
    }
    else{
        return cerca(v->next,c);
    }
}

template<class T>
void nodo<T>::copia(nodo *fst, nodo *&n, nodo *l){
    if(!fst){
        n = nullptr;
        l = nullptr;
        return;
    }
    nodo* tmp = fst;
    fst = new nodo(tmp->info, nullptr,nullptr);
    l= new nodo(tmp->info, nullptr,nullptr);
    while(tmp->next != nullptr){
        tmp = tmp->next;
        l->next= new nodo(tmp->info, l,nullptr);
        l = l->next;
    }
}

template<class T>
int nodo<T>::dim(nodo *v, int c){
    while(v != nullptr){
        c++;
    }
    return c;
}

template<class T>
void nodo<T>::distruggi(nodo *n){
    if(n != nullptr){
        distruggi(n->next);
        delete n;
    }
}

template<class T>
void nodo<T>::remove(nodo *v, T c){ // da rifare completamente
    /*if(!v){
        cout<<"no lista";
    }
    else{
        if(v->info.getTarga() == c.getTarga() && v->next == nullptr && v->prev == nullptr){ // fine lista
            cout<<"inizio lista, cancella tutto";
        }
        if(v->info.getTarga() == c.getTarga()){ // caso veicolo nel mezzo della lista
            cout<<"centro lista";
            nodo* aux = v;
            v->info = aux->next->info;

            v->prev = aux->prev;
            v->next = aux->next->next;
            //delete aux;
        }
        else{
        remove(v->next,c);
        }
    }
    */
    /*if (v == nullptr)
          return;
      if (v->info.getTarga() == c.getTarga())
          v = v->next;
      if (v->next != NULL)
          v->next->prev = v->prev;
      if (v->prev != NULL)
          v->prev->next = v->next;
    */
}

template <class T>
nodo<T>* nodo<T>::getFirst() const
{
    return first;
}

