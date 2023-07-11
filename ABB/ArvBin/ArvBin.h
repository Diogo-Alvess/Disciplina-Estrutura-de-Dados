#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a �rvore est� vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);
    int contaNos();
    int contaNosFolhas();
    int altura();
    int contaImpar();
    int contaFolhaImpar();
    void imprimeNivel(int k);
    float mediaNivel(int k);
    int min();
    int max();
    void inverte();
    int noMaisEsquerda();
    int noMaisDireita();
    bool ehABB();
    bool ehcheia();
    void excluifolhas();
    void imprime();
    void percursoPreOrdem();
    void percursoLargura();
    bool ehcheia2();
    int nnnk(int k);
    bool ehestr();
    bool ehcom();

    int impares();
    int soma();
    float mediaPares();
    int maiorVal();
    int maiores(int val);
    void imprimirNivel(int nivel);
    int sucessor(int val);
    //void cria(int valRaiz, ArvBinAlt* sae, ArvBinAlt *sad);
    void alturaNos();

    void contaElegante();
    void contagens(int val);



  private:
    NoArv *raiz; // ponteiro para o No raiz da �rvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    void auxImpNivel(NoArv *p, int atual, int k);
    NoArv* auxInsere(NoArv *p, int x);
    int auxContaNos(NoArv * p);
    int auxContaNosFolhas(NoArv *p);
    int auxAltura(NoArv *p);
    int auxContaImpar(NoArv *p);
    int auxcontaFolhaImpar(NoArv *p);
    void auximprimeNivel(NoArv *p, int cont, int k);
    void auxmediaNivel(NoArv *p, int cont,int *div, int *soma, int k);
    void auxmin(NoArv *p, int *compara);
    void auxmax(NoArv *p, int *compara);
    void auxInverte(NoArv *p);
    int auxnoMaisEsquerda(NoArv *p);
    int auxnoMaisDireita(NoArv *p);
    bool auxEhABB(NoArv *p);
    int numnos(NoArv *p);
    void auxEfolhas(NoArv *p);
    void auxImprime(NoArv *p, int nivel);
    int auxehcheia(int *n, NoArv *p);
    int auxnnnk(NoArv *p, int cont, int *n, int k);
    bool auxehestr(NoArv *p);

    int auximpares(NoArv *p);
    int auxsoma(NoArv *p);
    float auxmediaPares(NoArv *p ,int *cont, int *soma);
    void auxmaiorVal(NoArv *p, int *comp);
    void auxmaiores(NoArv *p, int *cont, int val);
   //void auxcria(int valRaiz, ArvBinAlt* sae, ArvBinAlt *sad);
    void auxalturaNos();
    void auxcontaElegante(NoArv *p, int *c2, int *c5);
    void auxcontagens(NoArv *p, int *c1, int *cmv, int val);

};



#endif // ARVBIN_H_INCLUDED
