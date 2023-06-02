#ifndef LISTAENCAD_H_INCLUDED
#define LISTAENCAD_H_INCLUDED
#include "No.h"

class ListaEncad
{
public:
    ListaEncad();
    ~ListaEncad();
    bool busca(int val);        /// retorna true caso val esteja na lista e false caso contrario
    int get(int k);             /// retorna o valor do k-ésimo elemento
    void set(int k, int val);   /// altera o valor do k-ésimo elemento
    void insereInicio(int val); /// insere um novo No contendo val no início da lista
    void insereFinal(int val);  /// insere um novo No contendo val no final da lista
    void removeInicio();        /// remove o primeiro No da lista
    void removeFinal();         /// remove o último No da lista

    /*
    1. Implemente as seguintes operacoes:
    I Imprimir a lista;
    I Retornar o numero de n  ́ os de uma lista; ́
    I Verificar se existe um elemento na lista com valor maior do
    que um valor fornecido. Retornar a posicao do primeiro
    elemento que seja maior que o dado de entrada ou -1 caso
    contrario;
    I “Limpar” a lista, isto e, remover todos os elementos;
    I Calcular e retornar a media dos valores armazenados;
    I Concatenar (por copia) a lista l2 ao final da lista interna;  ́
    I Partir a lista interna em duas partes, de maneira que o no
    de  ́ındice x se torne o primeiro no da nova lista, que deve
    ser retornada pela funcao.
    */
    void imprime();
    int numNos();
    int buscaMaior(int val);
    void limpar();
    float calculaMedia();
    void concatena(ListaEncad *l2);
    ListaEncad* partir(int x);

    void insereOrdenado(int val);
    void novoNo(int k, int valor);
    void removeFinal1();
    int contaMaiores (int val );
    bool igual( ListaEncad * l3 );
    void removeValor (int val );

    void removeBloco(int a, int b);

private:
    No *primeiro;  /// ponteiro para o primeiro No da lista
    No *ultimo;    /// ponteiro para o ultimo No da lista
    int n;         /// numero de nos na lista
};
#endif
