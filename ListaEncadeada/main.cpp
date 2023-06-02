#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaEncad.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1) ; /// retorna um numero inteiro aleatório entre a e b
}

int main()
{
    /*ListaEncad l; /// cria lista vazia
    int NumNos = 12;

    srand(time(NULL));
    /// ATENCAO: os valores inseridos na lista sao gerados
    /// aleatoriamente e mudam em cada execucao do programa!!!
    cout << "Inserindo valores: ";
    for(int i = 1; i <= NumNos; i++)
    {
        int val =  numAleatorio(0, 50); /// cria um valor aleatório entre 0 e 50
        cout << val << ", ";
        l.insereInicio(val);
    }
    cout << endl;

    bool existe = l.busca(20);
    cout << "O valor 20 esta na lista? ";
    if(existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    l.imprime();

    cout << l.numNos() << " nos" << endl;

    cout<<"Media dos valores: " <<l.calculaMedia() << endl;


    cout << "Primeiro elemento maior no indice: " << l.buscaMaior(40)<< endl;

    //l.limpar();

    cout << "lista: ";
    //l.imprime();

    cout<<"Media dos valores: " <<l.calculaMedia() << endl;
    */
    ListaEncad l2;

    l2.insereFinal(1);
    l2.insereFinal(2);
    l2.insereFinal(4);
    l2.insereFinal(3);
    l2.insereFinal(5);

    //cout << "Concatenada: ";
    //l.concatena(&l2);
    l2.imprime();

    //cout << "Partida: ";
    //l.partir(6);

    l2.insereOrdenado(3);
    l2.novoNo(3,77);

    l2.removeFinal1();
    cout <<"numeros maiores: "<< l2.contaMaiores(0) << endl;

    ListaEncad l3;

    l3.insereFinal(1);
    l3.insereFinal(2);
    l3.insereFinal(3);
    l3.insereFinal(77);
    l3.insereFinal(4);

    cout << "as listas sao iguais? " <<l2.igual (&l3)<< endl;

    l2.removeValor(3);

    l2.removeBloco(2, 77);

    l2.imprime();

    return 0;
};

