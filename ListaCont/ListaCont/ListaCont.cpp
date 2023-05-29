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
    {
        //lista vazia. Sera o unico no da lista
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

/*
A) Implementar a operação void ListaCont::intercala(ListaCont *la, ListaCont *lb); que recebe como parâmetro ponteiros válidos
para duas listas la e lb de tamanho qualquer. A operação deve limpar a lista interna e depois intercalar os elementos das listas
recebidas como parâmetro dentro da lista interna (iniciando pela lista la). Se for necessário, a operação deve aumentar a capacidade
máxima da lista interna. Ao final, as listas la e lb devem ficar vazias. Não se esqueça de levar em consideração que as listas la e lb
podem ter tamanhos distintos e, neste caso, os elementos da maior lista também devem ser copiados para o final da lista interna.

Exemplo: Considere uma lista inicial interna com os valores [3, 4], a lista la com valores [6, 7, 8, 9, 10] e a lista lb com valores
[0, 1, 2]. Após a execução da operação intercala(), a lista interna deve ficar com [6, 0, 7, 1, 8, 2, 9, 10] e as listas la e lb
devem estar vazias.
*/

void ListaCont::intercala(ListaCont *la, ListaCont *lb)
{
    for(int i = 0; i <= n; i++)
    {
        n--;
    }

    int novoMax = ((la->n) + (lb->n));

    if( novoMax > max)
    {
        max = novoMax;
    }

    for(int i = 0; i< novoMax; i++)
    {
        if(la->n !=0)
        {
            insereFinal(la->get(0));
            la->removeInicio();

            //Ou ...
            /*vet[n] = la->vet[0];
            n++;

            for(int i = 0; i < la->n -1; i++)
                la->vet[i] = la->vet[i+1];
            la->n = la->n -1;*/
        }
        if(lb->n !=0)
        {
            insereFinal(lb->get(0));
            lb->removeInicio();

        }
    }

    imprime();
}

/*Implementar a operação void ListaCont::inserirVet(int tam, int v[]); para inserir os
tam elementos do vetor v[] no início de uma lista contígua. A ordem dos valores do vetor
deve ser preservada na lista. A folga no fim do vetor que armazena a lista deve permanecer
do mesmo tamanho. Por isso, será necessário realocar o vetor suporte da lista para um novo valor de max.
Exemplo: Considere a lista inicial com os valores L = [9, 3, 5, ?, ?] e vet = {-5, 6, 7}.0
Abaixo encontra-se a lista esperada após a execução da operação L.inserirVet(3 ,{-5, 6, 7}):
L → [-5, 6, 7, 9, 3, 5, ?, ?] */

void ListaCont::inserirVet(int tam, int v[])
{
    int novoMax = max +tam;
    max = novoMax;

    for(int i = tam; i >=0 ; i--)
    {
        insereInicio(v[i]);
    }

    //OU...
    /*for(int i = 0; i< tam; i++)
    {
        //insereInicio(v[i]);

        for(int j = n; j >=  0; j--)
        {
            vet[j] = vet[j-1];
        }

    vet[0] = v[i];
    n=n+1;
    }*/

    imprime();

}

/*
Implementar a operação ListaCont* ListaCont::copiar(int valor); para copiar  todos os elementos da
lista intrínseca (elementos da lista para a qual foi chamada a operação)  a partir da primeira ocorrência de valor (inclusive)
para uma nova lista. Retornar a nova  lista. Caso o valor não seja encontrado, retornar uma lista contígua vazia. Os valores
adicionados à nova lista devem ser removidos da lista intrínseca, e a ordem, em ambas as  listas, deve ser preservada.
Exemplo: Considere a lista intrínseca inicial com os valores L = [3, 2, 5, 5, 9] e  valor = 5.
Abaixo estão as listas esperadas após a execução da operação  L.copiar(5):
L → [3, 2]
novaLista → [5, 5, 9]
*/
ListaCont* ListaCont::copiar(int valor)
{
    ListaCont *novaLista = new ListaCont(max);

    for(int i=0; i< n; i++)
    {
        if(vet[i] == valor)
        {
            for(int j = i; j < n; j++)
            {
                cout<< j << endl;
                novaLista->insereFinal(vet[j]);

            }
            int t = n;
            for(int k = i; k< t; k++)
            {
                removeK(i);

            }
            // teste:
            //imprime();
            //novaLista->imprime();
            return novaLista;
        }
    }

    return novaLista;
}

/*
 Implementar a operação bool ListaCont::insereValores(int k, int tam, int v[]);
que recebe como parâmetro um vetor v de números inteiros e seu tamanho tam, e insere os elementos de
v na lista contígua a partir de seu índice k, deslocando os elementos subsequentes da lista para a direita
quando for o caso. Se a inserção for realizada com sucesso, a operação deve retornar true. Se o índice k for
inválido ou se não houver espaço para inserir todos os elementos na lista, então a lista não deve ser
modificada e a operação deve retornar false. A operação deve percorrer apenas uma vez a lista, e não devem
ser utilizadas outras operações do TAD. [35]
Exemplo: Considere uma lista inicial com os valores [3, 2, 5, 7, 9] e capacidade máxima de 8
elementos. Abaixo estão as listas e o retorno esperados para diferentes execuções da operação sempre
sobre a lista inicial:
insereValores(0, 2, [1, 1]) → [1, 1, 3, 2, 5, 7, 9] (true)
insereValores(5, 2, [1, 1]) → [3, 2, 5, 7, 9, 1, 1] (true)
insereValores(3, 2, [1, 1]) → [3, 2, 5, 1, 1, 7, 9] (true)
insereValores(7, 2, [1, 1]) → [3, 2, 5, 7, 9] (false)
insereValores(2, 4, [1, 1, 1, 1]) → [3, 2, 5, 7, 9] (false)
*/

bool ListaCont::insereValores(int k, int tam, int v[])
{
    if( k < 0 || (tam + n) > max || k > n )
    {
        return false;
    }

    for(int j = 0; j<tam; j++)
    {
        for(int i = n-1; i >= k; i--)
            vet[i+1] = vet[i];

        vet[k] = v[j];
        n = n + 1;
    }

    imprime();
    return true;

}

/*Implementar a operação ListaCont* ListaCont::moveParesInvertidos(); que cria
dinamicamente uma nova lista e move para esta nova lista todos os elementos pares da lista interna de modo
que fiquem em ordem invertida na nova lista. Ao final, a lista interna deve ficar apenas com os elementos
ímpares em sua ordem original e a operação deve retornar a lista criada dinamicamente.
Exemplo: Considere uma lista inicial com os valores [2, 3, 4, 5, 6, 7, 8]. Após a execução da
operação moveParesInvertidos(), a lista interna deve ficar com [3, 5, 7] e a operação deve
retornar uma nova lista com [8, 6, 4, 2].*/

ListaCont* ListaCont::moveParesInvertidos()
{
    ListaCont *novaLista = new ListaCont(max);

    for(int i = 0 ; i< n; i++)
    {
        if(vet[i]%2 == 0)
        {
            novaLista->insereInicio(vet[i]);
        }

    }


    for(int i = 0 ; i< n; i++)
    {
        if(vet[i]%2 == 0)
        {
            removeK(i);
        }

    }

    //novaLista->imprime();
    //imprime();


    return novaLista;

}
