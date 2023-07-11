#include <iostream>
#include "ArvBin.h"
using namespace std;

int main()
{
    ArvBin arv;
    arv.montaArvore();
    //arv.insere(15);
    //arv.insere(25);
    //arv.insere(10);
    arv.preOrdem();
    cout << "Numero de nos: " << arv.contaNos() << endl;
    cout << "Numero de nos folhas: " << arv.contaNosFolhas() << endl;
    cout << "Altura: " << arv.altura() << endl;
    cout << "Numero de impares: " << arv.contaImpar() << endl;
    cout << "Numero de impares folhas: " << arv.contaFolhaImpar() << endl;
    //arv.imprimeNivel(1);
    cout << "mediado nivel: " << arv.mediaNivel(1) << endl;
    cout << "valor minimo: " << arv.min() << endl;
    cout << "valor maximo: " << arv.max() << endl;
    //arv.inverte();
    //arv.imprimeNivel(1);
    //cout << "valor no mais a esquerda: " << arv.noMaisEsquerda() << endl;
    //cout << "valor no mais a direita: " << arv.noMaisDireita() << endl;
    cout << "é arv bin de busca? " << arv.ehABB() << endl;
    cout << "é arv bin cheia? " << arv.ehcheia() << endl;
    //arv.imprime();
    //arv.excluifolhas();
    arv.imprime();
    arv.percursoPreOrdem();
    arv.percursoLargura();
    cout << "é arv bin cheia2? " << arv.ehcheia2() << endl;
    cout << "nnnk? " << arv.nnnk(1) << endl;
    cout << "é estritamente binaria? " << arv.ehestr() << endl;
    cout << "é binaria completa? " << arv.ehcom() << endl;
    cout << "numero de impares: " << arv.impares() << endl;
    cout << "soma: " << arv.soma() << endl;
    cout << "media dos pares: " << arv.mediaPares() << endl;
    cout << "maior valor da arv: " << arv.maiorVal() << endl;
    cout << "quantidade valores maiores que val: " << arv.maiores(1) << endl;
    cout << "sucessor de val: " << arv.sucessor(5) << endl;
    arv.contaElegante();
    cout << endl;
    arv.contagens(3);


}
