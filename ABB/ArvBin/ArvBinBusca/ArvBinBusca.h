#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int val);
    void insere(int val);
    void remove(int val);
    void imprime();
    float mediaCaminho(int ch);
    int maior();
    int menor();
    void removeMaior();
    void removeMin();
    void removeMenor();
    int contaParesCaminho(int x);

    void imprimeFilhos(int x);
    void imprimeIntervalo(int x, int y);
    void imprimeCrescente();
    void imprimeDecrescente();
    void insereDoVetor(int n, int *vet);
    int* insereVetorCrescente();
    int* insereNoVetDecrescente();
    NoArv* buscaValor(int val);
    int classificaNo(int val);
    void insere2(int val);
    int nos1Filho();
    int nos2Filho();
    bool estritamenteBin();
    void transfABemABB();
    int contaNos();
    int impressaoParcial(int a, int b);
    void removeMenor2(int val);
    void removeFilhoEsquerdaK(int k, int val);
    void nosImpares02Filhos(int *nImpar, int *n2Filhos);
    void insNaoRec(int val);
    int* vetIntervalo(int a, int b, int k);


private:
    NoArv* raiz; // ponteiro para o No raiz da árvore
    bool auxBusca(NoArv *p, int val);
    NoArv* auxInsere(NoArv *p, int val);
    NoArv* auxRemove(NoArv *p, int val);
    NoArv* menorSubArvDireita(NoArv *p);
    NoArv* removeFolha(NoArv *p);
    NoArv* remove1Filho(NoArv *p);
    void imprimePorNivel(NoArv* p, int nivel);
    NoArv* libera(NoArv *p);
    int auxmaior(NoArv *p);
    int auxmenor(NoArv *p);
    NoArv* auxremoveMaior(NoArv *p);
    NoArv* auxRemoveMin(NoArv *p);
    int auxcontaParesCaminho(NoArv *p, int x, int *cont);
    NoArv* maiorSubArvEsq(NoArv *p);

    void auximprimeFilhos(NoArv *p, int x);
    void auximprimeIntervalo(NoArv *p, int x, int y);
    void auximprimeCrescente(NoArv *p);
    void auximprimeDecrescente(NoArv *p);
    void auxinsereDoVetor(int n, int *vet, int p, int q);
    int* auxinsereVetorCrescente(int *cont, int *vet, NoArv *p);
    int* auxinsereNoVetDecrescente(int *cont, int *vet, NoArv *p);

    void auxnos1Filho(int *cont, NoArv *p);
    void auxnos2Filho(int *cont, NoArv *p);
    bool auxestritamenteBin(NoArv *p);
    void auxtransfABemABB();
    int auxContaNos(NoArv *p);

    int auximpressaoParcial(NoArv *p, int a, int b, int *soma);
    void auxnosImpares02Filhos(NoArv *p, int *nImpar, int *n2Filhos);
    void auxvetIntervalo(NoArv *p, int *vet, int a, int b, int k, int *i, int cont);
};

#endif // ARVBINBUSCA_H_INCLUDED
