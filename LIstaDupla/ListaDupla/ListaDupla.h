#ifndef LISTADUPLA_H_INCLUDED
#define LISTADUPLA_H_INCLUDED
#include "NoDuplo.h"

class ListaDupla
{
public:
    ListaDupla();
    ~ListaDupla();
    bool busca(int val);
    int get(int k);
    void set(int k, int val);
    void insereInicio(int val);
    void removeInicio();

    void insereFinal(int val);
    void removeFinal();
    void imprime();
    void imprimeReverso();
    ListaDupla* concatena(ListaDupla *l2);
    ListaDupla* partir(int x);
    void removeOcorrencias(int val);
    void removeMaior();
    void anexar(ListaDupla *l2);
    void trocaSegundoPenultimo();
    int* append(int n);


    private:

    NoDuplo *primeiro;
    NoDuplo *ultimo;
    int n;
};
#endif
