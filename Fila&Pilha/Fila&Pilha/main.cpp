#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"

using namespace std;

int* inverte(int *vet, int n)
{
    PilhaEncad *pilha = new PilhaEncad();

    for(int i= 0; i<n; i++)
    {
        pilha->empilha(vet[i]);
    }

    int *vetNovo = new int[n];

    for(int i = 0; i< n; i++)
    {
        vetNovo[i] = pilha ->desempilha();
    }

    cout << "vetNovo: ";


    for(int i = 0; i< n; i++)
    {
        cout << vetNovo[i]<< " ";
    }

    cout << endl;

    return vetNovo;

}

void inverteFila(FilaEncad *f)
{
    PilhaEncad *p = new PilhaEncad;


    while (!f->vazia()) {
        int elemento = f->desenfileira();
        p->empilha(elemento);

    }


    while (!p->vazia()) {
        int elemento = p->desempilha();
        f->enfileira(elemento);
    }

    delete p;
   f->imprime();
}

int main()
{
    /// TESTE COM PILHA
    PilhaEncad p;

    for(int i = 0; i < 5; i++) p.empilha(i);
    cout << "Pilha apos inserir 5 valores" << endl;
    p.imprime();

    for(int i = 20; i < 25; i++) p.empilha(i);
    cout << "Pilha apos inserir mais 5 valores" << endl;
    p.imprime();

    cout << "numeros de nos: " << p.tamanho() << endl;


    /// TESTE COM FILA

    FilaEncad f;
    for(int i=0; i<5; i++) f.enfileira(i);
    cout << "Fila apos inserir 5 valores" << endl;
    f.imprime();

    for(int i = 20; i < 25; i++) f.enfileira(i);
    cout << "Fila apos inserir mais 5 valores" << endl;
    f.imprime();

    int vet[5] = {1, 2, 3, 4, 5};

    inverte(vet, 5);

    inverteFila(&f);


    return 0;
}
