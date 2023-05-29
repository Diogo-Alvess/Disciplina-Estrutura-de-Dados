#ifndef LISTACONT_H_INCLUDED
#define LISTACONT_H_INCLUDED
#include "Ponto.h"

class ListaCont
{
private:
    int max;
    int n;
    int *vet;

public:
    ListaCont(int tam);
    ~ListaCont();

    int get(int k);
    void set(int k, int val);
    void insereFinal(int val);
    void insereK(int k, int val);
    void insereInicio(int val);
    void removeFinal();
    void removeK(int k);
    void removeInicio();
    void imprime();
    int numNos();
    int buscaMaior(int val);
    void limpar();
    void insereValores(int tam, int vet2[]);
    bool troca(int posicao1, int posicao2);
    bool aumentaCapacidade(int novoMax);
    void intercala(ListaCont *la, ListaCont *lb);
    void inserirVet(int tam, int v[]);
    ListaCont* copiar(int valor);
    bool insereValores(int k, int tam, int v[]);
    ListaCont* moveParesInvertidos();
};

#endif // LISTACONT_H_INCLUDED
