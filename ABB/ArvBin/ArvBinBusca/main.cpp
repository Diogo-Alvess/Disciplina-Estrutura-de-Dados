#include <iostream>
#include "ArvBinBusca.h"
#include <math.h>

using namespace std;


/*
7. Desenvolver uma func ̧ao recursiva para ser usado no  ̃
programa principal para preencher uma  ́arvore bin ́aria de
busca, isto e, de tal forma que ela fique completa. Os  ́
valores dos nos devem ser inteiros no intervalo de  ́ p a q. Os
parametros do procedimento ser ˆ ao uma  ̃ arvore vazia e os  ́
valores inteiros p e q.
void preencheABB(ArvBinBusca *a, int p, int q);*/

void preencheABB(ArvBinBusca *a, int p, int q)
{
    if(p>q)
        return;

    int valor = (p + q) / 2; // Valor médio do intervalo

    a->insere(valor); // Inserir valor na árvore

    preencheABB(a, p, valor - 1); // Preenche a subárvore esquerda
    preencheABB(a, valor + 1, q); // Preenche a subárvore direita
}

int main()
{
    ArvBinBusca arv;

    /*cout << "Criando Arvore Binaria de Busca (ABB)" << endl;
    arv.insere(15);
    arv.insere(9);
    arv.insere(20);
    arv.insere(7);
    arv.insere(16);
    arv.insere(18);
    arv.insere(24);
    arv.insere(6);
    arv.insere(8);
    arv.insere(10);
    arv.insere(12);
    arv.insere(17);
    arv.insere(19);
    arv.imprime();
    cout << endl;

    cout << "Media do caminho ate o no com valor 18: " << arv.mediaCaminho(18) << endl;

    cout << "Busca o valor 20: " << arv.busca(20) << endl;
    cout << "Busca o valor  5: " << arv.busca(5) << endl;
    cout << endl;

    cout << "Removendo os valores 24, 6, 7, 12, 18, 5." << endl;
    arv.remove(24);
    arv.remove(6);
    arv.remove(7);
    arv.remove(12);
    arv.remove(18);
    arv.remove(5);
    cout << endl;

    cout << "Arvore Binaria de Busca final:" << endl;
    arv.imprime();

    cout << "maior valor abb: " << arv.maior() << endl;
    cout << "menor valor abb: " << arv.menor() << endl;
    arv.removeMaior();
    arv.removeMin();
    arv.imprime();
    cout << arv.contaParesCaminho(10);*/

    ArvBinBusca arv2;

    preencheABB(&arv2, 1, 15 );
    arv2.imprime();
    arv2.imprimeFilhos(8);
    arv2.imprimeIntervalo(2, 5);
    cout<<endl;
    arv2.imprimeCrescente();
    cout<<endl;
    arv2.imprimeDecrescente();

    ArvBinBusca arv3;

    int vet[5] = {1,2,3,4,5};

    arv3.insereDoVetor(5, vet);

    arv3.imprime();

    arv2.insereVetorCrescente();
    cout<<endl;
    arv2.insereVetorCrescente();
    NoArv *p = arv2.buscaValor(8);
    cout<<endl;
    cout<< p->getInfo() <<endl;
    cout<< arv2.classificaNo(8) <<endl;
    arv2.insere2(16);
    arv2.imprime();

    //cout << arv2.nos1Filho() << endl;
    //cout << arv2.nos2Filho() << endl;

    //cout << "eh estritamente binaria?" << arv2.estritamenteBin()<< endl;
    //cout<<endl;
    //cout<< arv2.impressaoParcial(2, 6) <<endl;
    //arv2.removeMenor2(16);
    //arv2.imprime();
    //arv2.removeFilhoEsquerdaK(2, 2);
    arv2.imprime();

    int i= 0;
    int f2 = 0;
    arv2.nosImpares02Filhos(&i, &f2);
    cout<< i << " " << f2;
    arv2.insNaoRec(9);
    arv2.imprime();
    int *vet2 = arv2.vetIntervalo( 2, 14, 2);
    for(int i = 0; i< pow(2,2) +1; i++)
    {
        cout << vet2[i] << " ";
    }

    return 0;
}

