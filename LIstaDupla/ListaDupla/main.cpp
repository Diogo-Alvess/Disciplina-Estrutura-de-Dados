#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaDupla.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1); /// retorna um numero inteiro aleat—rio entre a e b
}

int main()
{
    ListaDupla l; /// cria lista vazia
    int NumNos = 10;

    srand(time(NULL));

    /// ATENCAO: os valores inseridos na lista sao gerados
    /// aleatoriamente e mudam em cada execucao do programa!!!
    cout << "Inserindo valores: ";
    for(int i = 1; i <= NumNos; i++)
    {
        int val =  numAleatorio(0, 50); /// cria um valor aleat—rio entre 0 e 50
        cout << val << ", ";
        l.insereInicio(val);
    }
    cout << endl;


    l.insereFinal(5);
    l.imprime();
    //l.removeFinal();
    //l.imprime();
    l.imprimeReverso();

    bool existe = l.busca(20);
    cout << "O valor 20 esta na lista? ";
    if(existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    ListaDupla l2;

    l2.insereFinal(1);
    l2.insereFinal(2);
    l2.insereFinal(3);
    l2.insereFinal(4);
    l2.insereFinal(5);



    //l.concatena(&l2);

    //l.partir(5);

    //l2.removeOcorrencias(3);
    //l2.imprime();

    //l.removeMaior();
    //l.imprime();

    //l.anexar(&l2);
    //l.imprime();

    l2.trocaSegundoPenultimo();
    l2.imprime();

    l2.append(int n);



    return 0;
};

