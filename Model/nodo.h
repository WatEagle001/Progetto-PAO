#ifndef NODO_H
#define NODO_H

template <class T> class nodo;

template <class T>
class nodo {
 private:
    T info;
    nodo* prev;
    nodo* next;
public:
    nodo(const T& i, nodo* p = 0, nodo* n = 0): info(i), prev(p), next(n){};
    //nodo(const automobile& i, nodo* p = 0, nodo* n = 0): info(i), prev(p), next(n){};
   // distruttore in versione standard

    nodo* first; // puntatori alla testa e alla coda della lista
    nodo* last;

    void inserisci(nodo* v, const T t);
    static bool cerca(nodo* v, T c);
    static void copia(nodo* fst, nodo*& n, nodo* l);

    static int dim(nodo* v, int c = 0);

    static void distruggi(nodo* n);
    static void remove(nodo* v, T c);
    nodo *getFirst() const;
    void setFirst(nodo *newFirst);
    T getInfo() const;
    void setInfo(const T &newInfo);
    nodo *getNext() const;
    nodo *getPrev() const;
};
#endif //NODO_H
