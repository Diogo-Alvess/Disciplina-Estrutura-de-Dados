#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"
#include <math.h>

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Árvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}

NoArv* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}

//1. Desenvolva uma operac ̧ao para contar quantos o total de  ̃
//nos de uma  ́ arvore bin  ́ aria.  ́

int ArvBin::contaNos()
{
    return auxContaNos(raiz);
}

int ArvBin::auxContaNos(NoArv *p)
{
    if(p == NULL)
    {
        return 0;
    }

    return 1 + auxContaNos(p->getEsq()) + auxContaNos(p->getDir());
}

//2. Desenvolva uma operac ̧ao para contar quantos n  ̃ os s  ́ ao ̃
//folhas em uma arvore bin  ́ aria.  ́
int ArvBin::contaNosFolhas()
{
    return auxContaNosFolhas(raiz);
}

int ArvBin::auxContaNosFolhas(NoArv *p)
{
    if(p == NULL )
    {
        return 0;
    }

    if(p->getEsq() == NULL && p->getDir() == NULL )
    {
        return 1;
    }

    return auxContaNosFolhas(p->getEsq()) + auxContaNosFolhas(p->getDir());

}

//3. Desenvolva uma operac ̧ao para determinar a altura de  ̃
//uma arvore bin  ́ aria.

int ArvBin::altura()
{
    return auxAltura(raiz);
}

int ArvBin::auxAltura(NoArv *p)
{
    if(p==NULL)
    {
        return -1;
    }

    int he = auxAltura(p->getEsq());
    int hd = auxAltura(p->getDir());

    if(he > hd)
    {
        return 1 + he;
    }

    else
    {
        return 1 + hd;
    }
}

//4. Desenvolva uma operac ̧ao para calcular e retornar a  ̃
//quantidade de valores  ́ımpares numa arvore bin  ́ aria.  ́

int ArvBin::contaImpar()
{

    return auxContaImpar(raiz);
}

int ArvBin::auxContaImpar(NoArv *p)
{

    if(p==NULL)
    {
        return 0;
    }

    else
    {

        return (p->getInfo()%2 != 0 ? 1 : 0) + auxContaImpar(p->getDir()) + auxContaImpar(p->getEsq());

    }

}

//5. Desenvolva uma operac ̧ao para calcular a quantidade de  ̃
//valores  ́ımpares armazenados nos nos folhas de uma arvore bin  ́ aria.  ́

int ArvBin::contaFolhaImpar()
{
    return auxcontaFolhaImpar(raiz);
}

int ArvBin::auxcontaFolhaImpar(NoArv *p)
{

    if(p==NULL)
    {
        return 0;
    }

    return (p->getEsq() == NULL && p->getDir() == NULL && p->getInfo()%2 != 0 ? 1 : 0) + auxcontaFolhaImpar(p->getEsq()) + auxcontaFolhaImpar(p->getDir());

}

//6. Desenvolva uma operac ̧ao para imprimir todos os valores  ̃
//dos nos de um dado n  ́  ́ıvel k da arvore bin  ́ aria.  ́

void ArvBin::imprimeNivel(int k)
{
    auximprimeNivel(raiz,0, k);
    cout << endl;
}

void ArvBin::auximprimeNivel(NoArv *p, int cont, int k)
{
    if(p!=NULL)
    {
        if(cont == k)
        {
            cout << p->getInfo()<< endl;
        }

        auximprimeNivel(p->getEsq(), cont+1, k);
        auximprimeNivel(p->getDir(), cont+1, k);

    }

}

//7. Desenvolva uma operac ̧ao para calcular a m  ̃ edia dos  ́
//valores dos nos de um dado n  ́  ́ıvel k.

float ArvBin::mediaNivel(int k)
{
    int soma = 0;
    int div = 0;
    auxmediaNivel(raiz, 0, &div, &soma, k);

    return soma/div;
}

void ArvBin::auxmediaNivel(NoArv *p, int cont,int *div, int *soma, int k)
{
    if(p!=NULL)
    {
        if(cont == k)
        {
            *div = *div + 1;
            *soma = *soma + p->getInfo();
        }

        auxmediaNivel(p->getEsq(), cont+1, div, soma, k);
        auxmediaNivel(p->getDir(), cont+1, div, soma, k);

    }

}

//8. Desenvolva uma operac ̧ao para encontrar o menor (e o  ̃
//maior) valor de uma arvore bin  ́ aria.  ́
int ArvBin::min()
{
    int compara = raiz->getInfo();
    auxmin(raiz, &compara);
    return compara;
}

void ArvBin::auxmin(NoArv *p, int *compara)
{
    if(p!=NULL)
    {

        if(p->getInfo() < *compara)
        {
            *compara = p->getInfo();
        }

        auxmin(p->getEsq(), compara);
        auxmin(p->getDir(), compara);

    }

}

int ArvBin::max()
{
    int compara = raiz->getInfo();
    auxmax(raiz, &compara);
    return compara;

}

void ArvBin::auxmax(NoArv *p, int *compara)
{
    if(p!=NULL)
    {
        if(p->getInfo() > *compara)
        {
            *compara = p->getInfo();
        }

        auxmax(p->getEsq(), compara);
        auxmax(p->getDir(), compara);
    }
}

//9. Escreva uma operac ̧ao que  ̃ inverte a arvore bin  ́ aria, isto  ́ e, ́
//todo no que tiver 2 filhos ter  ́ a o seu valor do filho  ́ a`
//esquerda trocado com o do filho a direita. `

void ArvBin::inverte()
{
    auxInverte(raiz);
}

void ArvBin::auxInverte(NoArv *p)
{
    if(p!=NULL)
    {
        NoArv *aux = p->getEsq();
        p->setEsq(p->getDir());
        p->setDir(aux);

        auxInverte(p->getEsq());
        auxInverte(p->getDir());
    }
}

//10. Desenvolva uma operac ̧ao para retornar o valor do n  ̃ o ́
//mais a esquerda da ` arvore bin  ́ aria. Em seguida, fac ̧a outra  ́
//operac ̧ao para retornar o valor do n  ̃ o mais  ́ a direita da `
//arvore.

int ArvBin::noMaisEsquerda()
{
    return auxnoMaisEsquerda(raiz);
}

int ArvBin::auxnoMaisEsquerda(NoArv *p)
{
    if(p->getEsq() == NULL && p->getDir() == NULL)
    {
        return p->getInfo();
    }

    else
    {

        auxnoMaisEsquerda(p->getEsq());
    }

}

int ArvBin::noMaisDireita()
{
    return auxnoMaisDireita(raiz);
}

int ArvBin::auxnoMaisDireita(NoArv *p)
{
    if(p->getEsq() == NULL && p->getDir() == NULL)
    {
        return p->getInfo();
    }

    else
    {

        auxnoMaisDireita(p->getDir());
    }
}

//12. Fac ̧a uma operac ̧ao para verificar se uma  ̃ arvore bin  ́ aria  ́ e ́
//uma arvore bin  ́ aria de busca (ABB). Dica: utilize as  ́
//func ̧oes definidas no Exerc  ̃  ́ıcio 8 de forma auxiliar. Por
//exemplo, se o maior valor da sub-arvore  ́ a esquerda for `
//maior do que o valor da raiz, entao n  ̃ ao ̃ e ABB. Fac ̧a um  ́
//teste similar para a sub-arvore  ́ a direita.

bool ArvBin::ehABB()
{
    return auxEhABB(raiz);
}

bool ArvBin::auxEhABB(NoArv *p )
{
    if (p == NULL)
    {
        return true;
    }

    if (p->getEsq() != NULL && p->getEsq()->getInfo() > p->getInfo())
    {
        return false;
    }

    if (p->getDir() != NULL && p->getDir()->getInfo() < p->getInfo())
    {
        return false;
    }

    return auxEhABB(p->getEsq()) && auxEhABB(p->getDir());
}


//3.Escrever uma operação para verificar se uma árvore
//binária (AB) é cheia (retornar false) ou não (retornar
//true). O número de nós n de uma AB cheia é dado por
//n = 2^h+1 − 1, onde h é altura da AB. Também, pode-
//se considerar que uma AB é cheia quando o número
//de nós do último nível (número de folhas) da árvore
//binária é 2^h;

bool ArvBin::ehcheia()
{
    int n = numnos(raiz);
    int h = altura();

    return (pow(2, h+1) -1 == n ? 1:0);

}

int ArvBin::numnos(NoArv *p)
{
    if(p==NULL)
    {
        return 0;
    }

    return 1 + numnos(p->getEsq()) + numnos(p->getDir());
}

//4.Escrever uma operação para excluir todas as folhas de
//uma árvore binária, deixando a raiz e os nós
//intermediários nos respectivos lugares. Dica: usar o
//percurso em pré-ordem.

void ArvBin::excluifolhas()
{
    return auxEfolhas(raiz);
}

void ArvBin::auxEfolhas(NoArv *p)
{
    if(p==NULL)
    {
        return;
    }

    if(p->getEsq() != NULL && p->getEsq()->getEsq() == NULL && p->getEsq()->getDir() == NULL)
    {
        delete p->getEsq();
        p->setEsq(NULL);
    }

    if(p->getDir() != NULL && p->getDir()->getEsq() == NULL && p->getDir()->getDir() == NULL)
    {
        delete p->getDir();
        p->setDir(NULL);
    }

    auxEfolhas(p->getEsq());
    auxEfolhas(p->getDir());
}

//8. Desenvolver uma operação para imprimir o nível
//seguido do valor do nó de uma AB.

void ArvBin::imprime()
{
    auxImprime(raiz, 0);
    cout << endl;
}
void ArvBin::auxImprime(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ") -- ";

        cout << p->getInfo() << endl;
        auxImprime(p->getEsq(), nivel+1);
        auxImprime(p->getDir(), nivel+1);
    }
}

//5.Reescrever a operação de percurso em pré-ordem
//usando uma pilha em vez da recursão.

#include <stack>

void ArvBin::percursoPreOrdem()
{
    if (raiz == NULL)
    {
        return;
    }

    std::stack<NoArv*> pilha; //representa a pilha.
    pilha.push(raiz);  //insere um elemento no topo da pilha.

    while (!pilha.empty())    //verificar se ainda há nós na pilha a serem processados.
    {

        NoArv* atual = pilha.top(); //obter nó do topo da pilha.
        pilha.pop();   //remover o nó do topo da pilha, respectivamente.

        std::cout << atual->getInfo() << std::endl;

        if (atual->getDir() != NULL)
        {
            pilha.push(atual->getDir());
        }

        if (atual->getEsq() != NULL)
        {
            pilha.push(atual->getEsq());
        }

    }
}

//pilha.push() é usado para adicionar os nós à pilha,
//enquanto pilha.top() e pilha.pop() são usados para obter e remover o nó do topo da pilha, respectivamente.

//6.Reescrever o procedimento que realiza o percurso em
//largura usando uma pilha em vez de uma fila.
//(observar que o resultado dos exercícios 5 e 6 deve ser
//o mesmo. Por quê?).

/*void ArvBin::percursoLargura()
{
    NoArv *p = raiz, *q; //ponteiros para nó da árvore
    FilaEncad fila;
    if (p != NULL)//verifica se árvore está vazia
    {
        fila.Enfileira(p);//coloca nó raiz na fila
        while (!fila.Vazia()) //há nós na fila?
        {
            q = fila.desenfileira(); // tira nó da fila
            cout << q->getInfo()<< endl;
            if(q->getEsq() != NULL)
                fila.enfileira(q->getEsq());
            if(q->getDir() != NULL)
                fila.enfileira(q->getDir());

        }
    }
}*/

void ArvBin::percursoLargura()
{
    if (raiz != NULL)
    {

    std::stack<NoArv*> pilha; //representa a pilha.
    pilha.push(raiz);  //insere um elemento no topo da pilha.

    while (!pilha.empty())    //verificar se ainda há nós na pilha a serem processados.
    {
        NoArv* atual = pilha.top(); //obter nó do topo da pilha.
        pilha.pop();   //remover o nó do topo da pilha, respectivamente.

        std::cout << atual->getInfo() << std::endl;

        if (atual->getDir() != NULL)
        {
            pilha.push(atual->getDir());
        }

        if (atual->getEsq() != NULL)
        {
            pilha.push(atual->getEsq());
        }

     }
    }

}

//7.No exercício 3 (verificar se uma AB é cheia), a AB é
//percorrida 2 vezes: uma para calcular o número de
//folhas (ou nós) e outra para calcular a sua altura.
//Desenvolver a mesma operação porém percorrendo a
//árvore apenas uma única vez.


bool ArvBin::ehcheia2()
{
    int n = 0;
    int h = auxehcheia(&n, raiz);

    return (pow(2, h+1) -1 == n ? 1:0);

}

int ArvBin::auxehcheia(int *n, NoArv *p)
{
    if(p==NULL)
    {
        return -1;
    }

    if(p!= NULL)
        {
            *n = *n + 1;
        }

    int he = auxehcheia(n,p->getEsq());
    int hd = auxehcheia(n,p->getDir());

    if(he > hd)
    {
        return 1 + he;
    }

    else
    {
        return 1 + hd;
    }

}

//9. Desenvolver uma operação para, dado um inteiro
//k ≥ 0, calcular o número de nós no nível k de uma AB.

int ArvBin::nnnk(int k)
{

    int n= 0;
    auxnnnk(raiz,0,&n ,k);
    return n;
}

int ArvBin ::auxnnnk(NoArv *p, int cont, int *n, int k)
{
    if(p!=NULL)
    {
        if(cont == k)
        {
            *n = *n + 1;
        }

        auxnnnk(p->getEsq(), cont+1, n, k);
        auxnnnk(p->getDir(), cont+1, n, k);
    }
}

//Escrever uma operação para verificar se uma árvore
//binária (AB) é estritamente binária. Retornar true (se
//sim) ou false (se não).

bool ArvBin::ehestr()
{
    return auxehestr(raiz);
}

bool ArvBin::auxehestr(NoArv *p)
{
    if (p == NULL)
    {
        return true;
    }

    if ((p->getEsq() != NULL && p->getDir() == NULL) || (p->getEsq() == NULL && p->getDir() != NULL))
    {
        return false;
    }

    return auxehestr(p->getEsq()) && auxehestr(p->getDir());
}



//10. Escrever uma operação para verificar se uma árvore
//binária (AB) é completa. Retornar true (se sim) ou
//false (se não). Dica: usar a operação do exercício
//anterior.

bool ArvBin:: ehcom()
{
    int nult = altura();
    int npnult = altura() -1;

    int nnnu = nnnk(nult);
    int nnnpn = nnnk(npnult);

    if(nnnu < pow(2,nult) && nnnpn == pow(2, npnult))
    {
        return true;
    }
    else{
        return false;
    }
}

// Calcular e retornar o n ́umero de n ́os que armazena valores
//́ımpares fazendo um percurso p ́os-ordem.

int ArvBin::impares()
{
    return auximpares(raiz);
}

int ArvBin::auximpares(NoArv *p)
{
    if(p!=NULL)
    {
        return (p->getInfo()%2 != 0 ? 1:0) + auximpares(p->getEsq()) + auximpares(p->getDir());
    }
}

//Calcular e retornar a soma dos valores armazenados nos n ́os da arvore.
int ArvBin::soma()
{
    return auxsoma(raiz);
}

int ArvBin::auxsoma(NoArv *p)
{
    if(p!=NULL)
    {
        return p->getInfo() + auxsoma(p->getEsq()) + auxsoma(p->getDir());
    }
}

//Calcular e retornar a m ́edia dos valores armazenados nos n ́os
//da  ́arvore.

float ArvBin::mediaPares()
{
    int soma = 0;
    int cont = 0;
    auxmediaPares(raiz, &cont, &soma);

    return (float)soma/cont;
}

// Calcular e retornar a m ́edia dos valores pares armazena-
//dos nos n ́os da  ́arvore.
float ArvBin::auxmediaPares(NoArv *p ,int *cont, int *soma)
{
    if(p!=NULL)
    {
        if(p->getInfo()%2 == 0)
        {
            *cont = *cont +1;
            *soma = *soma + p->getInfo();
        }

        auxmediaPares(p->getEsq(), cont, soma);
        auxmediaPares(p->getDir(), cont, soma);
    }
}

//Determinar e retornar o maior valor armazenado nos n ́os da arvore.
int ArvBin::maiorVal()
{
    int compara = raiz->getInfo();
    auxmaiorVal(raiz, &compara);
    return compara;
}

void ArvBin::auxmaiorVal(NoArv *p, int *comp)
{
    if(p!=NULL)
    {
        if(*comp < p->getInfo())
        {
            *comp = p->getInfo();
        }

        auxmaiorVal(p->getEsq(), comp);
        auxmaiorVal(p->getDir(), comp);
    }
}

//Calcular e retornar a quantidade de n ́os que armazena
//chaves com valores maiores que val fazendo um percurso p ́os-ordem.

int ArvBin::maiores(int val)
{
    int cont =0;
    auxmaiores(raiz, &cont, val);
    return cont;
}

void ArvBin::auxmaiores(NoArv *p, int *cont, int val)
{
    if(p!= NULL)
    {
        if(p->getInfo() > val)
        {
            *cont = *cont +1;
        }

        auxmaiores(p->getEsq(), cont, val);
        auxmaiores(p->getDir(), cont, val);
    }
}

//Determinar e retornar o valor do n ́o da AB que re-
//presenta o sucessor de val. O sucessor de val  ́e o menor valor encontrado na AB maior
//que val. Se n ̃ao existir sucessor, retornar val.

int ArvBin::sucessor(int val)
{
    // se nao for tem que achar o valor maior  de todos com uma funçao

    // se for binaria

    /*NoArv* atual = raiz;
    int sucessor = val;

    while (atual != NULL) {
        if (atual->getInfo() > val) {
            sucessor = atual->getInfo();
            atual = atual->getEsq();
        } else {
            atual = atual->getDir();
        }
    }
    */

    //return sucessor;
}

//Implementar a operação void ArvBin::contaElegante();
//que percorre recursivamente a árvore binária, contando
//a quantidade de nós que possuem dois filhos e também
// a quantidade de nós folha que possuem valores
//múltiplos de 5. Ao final, a função deve imprimir os
//resultados. Você deve percorrer a árvore binária uma
// única vez em pré-ordem!

void ArvBin::contaElegante()
{
    int c2 = 0;
    int c5 = 0;
    auxcontaElegante(raiz, &c2, &c5);

    cout << "num. de nos com 2 filhos: " << c2 << " num. de nos valores múltiplos de 5: " << c5;
}

void ArvBin::auxcontaElegante(NoArv *p, int *c2, int *c5)
{
    if(p!=NULL)
    {
        if(p->getEsq() != NULL && p->getDir() != NULL)
        {
            *c2= *c2 +1;
        }
        if( 5 * (p->getInfo()/5) == p->getInfo())
        {
            *c5 = *c5 +1;
        }

        auxcontaElegante(p->getEsq(), c2, c5);
        auxcontaElegante(p->getDir(), c2, c5);
    }
}

//Implementar a operação void ArvBin::contagens(int val);
// que recebe um valor val como parâmetro e percorre
//recursivamente a árvore binária, calculando as
//seguintes informações:
//1) quantos nós são folhas ou possuem somente um filho;
//2) quantos nós possuem valores múltiplos de val.
//Ao final, a operação deve imprimir os resultados.
//Você deve percorrer a árvore binária uma única vez em-ordem!

void ArvBin::contagens(int val)
{
    int c1 = 0;
    int cmv = 0;
    auxcontagens(raiz, &c1, &cmv, val);

    cout << "num. de nos com 1 filhos: " << c1 << " num. de nos valores múltiplos de val " << cmv;
}

void ArvBin::auxcontagens(NoArv *p, int *c1, int *cmv, int val)
{
    if(p!=NULL)
    {

        if((p->getEsq() == NULL && p->getDir() != NULL) || (p->getEsq() != NULL && p->getDir() == NULL))
        {
            *c1= *c1 +1;
        }

        if( val * (p->getInfo()/val) == p->getInfo())
        {
            *cmv = *cmv +1;
        }

        auxcontagens(p->getEsq(), c1, cmv, val);
        auxcontagens(p->getDir(), c1, cmv, val);
    }
}



