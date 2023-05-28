#include <iostream>
#include <cstdlib>
#include "Ponto.h"
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    cout << "Criando objeto ListaCont" << endl;
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont()
{
    cout << "Destruindo objeto ListaCont" << endl;
    delete [] vet;
}

int ListaCont::get(int k)
{
    if(k >= 0 && k < n)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::set(int k, int val)
{
    if(k >= 0 && k < n)
        vet[k] = val;
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::insereFinal(int val)
{
    if(n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    vet[n] = val;
    n = n + 1;
}

void ListaCont::removeFinal()
{
    if(n == 0)
    {
        cout << "ERRO: Lista Vazia!" << endl;
        exit(1);
    }
    n = n - 1;
}

void ListaCont::insereK(int k, int val)
{
    if(n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    if(k >= 0 && k < n)
    {
        for(int i = n-1; i >= k; i--)
            vet[i+1] = vet[i];
        vet[k] = val;
        n = n + 1;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::removeK(int k)
{
    if(k >= 0 && k < n)
    {
        for(int i = k; i < n-1; i++)
            vet[i] = vet[i+1];
        n = n - 1;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::insereInicio(int val)
{
    if(n == 0)
    {   //lista vazia. Sera o unico no da lista
        vet[n] = val;
        n = n + 1;
    }
    else
        insereK(0, val);
}

void ListaCont::removeInicio()
{
    removeK(0);
}


// ------------------------------------------
void ListaCont::imprime()
{
    cout << "imprime lista: ";

    for(int i = 0; i<n; i++)
    {
        cout << vet[i] << " ";
    }
    if(n==0)
        {
             cout << "Lista vazia";
        }
    cout << endl;
}

int ListaCont::numNos()
{
    return n;
}

/*Verificar se existe um elemento na lista com valor maior do
que um valor fornecido. Retornar o  ́ındice do primeiro
elemento que seja maior que o dado de entrada ou -1 caso
contrario.*/
int ListaCont::buscaMaior(int val)
{
    int ind = 0;

    for(int i = 0; i<n; i++)
    {
        if( val < vet[i])
        {
            return ind;

        }
        ind += 1;
    }

    return -1;
}

void ListaCont::limpar()
{
    int cont = n;
    for(int i = 0; i< cont; i++)
    {
        n = n-1;
    }

    //n=0;
}

void ListaCont::insereValores(int tam, int vet2[])
{

    if( (tam + n) > max)
    {
        cout << "vetor cheio" << endl;
        exit(1);
    }

    for(int i=0; i < tam; i++)
    {
        vet[n] = vet2[i];
        n = n+1;
    }
}


/*Considerando o TAD ListaCont que representa uma lista cont ́ıgua, fa ̧ca uma fun ̧c ̃ao para
trocar de posi ̧c ̃ao dois elementos na lista. A fun ̧c ̃ao deve retornar se a opera ̧c ̃ao foi poss ́ıvel ou
n ̃ao.
bool ListaCont :: troca (int posicao1 , int posicao2 ) ;*/


bool ListaCont::troca(int posicao1, int posicao2)
{
    int val1= vet[posicao1];
    int val2= vet[posicao2];

    int aux = vet[posicao1];
    vet[posicao1] = vet[posicao2];
    vet[posicao2] = aux;

    if(val1 == vet[posicao2] && val2 == vet[posicao1])
    {
        return true;
    }
    return false;
}


/*Considerando o TAD ListaCont que representa uma lista cont ́ıgua, fa ̧ca uma fun ̧c ̃ao para
aumentar a capacidade m ́axima (definida por max) do vetor que representa a lista sem que
nenhum dado atualmente representado na lista seja perdido. Se a nova capacidade definida
pelo parˆametro novoMax for menor que a capacidade atual, a opera ̧c ̃ao n ̃ao deve fazer nada.
Ao final retornar se a opera ̧c ̃ao foi ou n ̃ao realizada.
bool ListaCont :: aumentaCapacidade (int novoMax ) ;*/


bool ListaCont::aumentaCapacidade(int novoMax)
{
    if(novoMax > max)
    {
        max = novoMax;
    }

    if(max == novoMax)
    {
        return true;
    }
    else
    {
        return false;
    }
}













