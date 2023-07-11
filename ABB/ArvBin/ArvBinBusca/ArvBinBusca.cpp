#include <iostream>
#include "ArvBinBusca.h"
#include <math.h>

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}

NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;
    else if(p->getInfo() == val)
        return true;
    else if(val < p->getInfo())
        return auxBusca(p->getEsq(), val);
    else
        return auxBusca(p->getDir(), val);
}

void ArvBinBusca::remove(int val)
{
    raiz = auxRemove(raiz, val);
}

NoArv* ArvBinBusca::auxRemove(NoArv *p, int val)
{
    if(p == NULL)
        return NULL;
    else if(val < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), val));
    else if(val > p->getInfo())
        p->setDir(auxRemove(p->getDir(), val));
    else
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if((p->getEsq() == NULL) || (p->getDir() == NULL))
            p = remove1Filho(p);
        else
        {
            //p tem dois filhos
            NoArv *aux = menorSubArvDireita(p);

            // troca as informações
            int auxInt = aux->getInfo();
            p->setInfo(auxInt);
            aux->setInfo(val);

            // recursão: para a subarv. direita
            p->setDir(auxRemove(p->getDir(), val));
        }
    }
    return p;
}

NoArv* ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}

NoArv* ArvBinBusca::remove1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir();
    else
        aux = p->getEsq();
    delete p;
    return aux;
}

NoArv* ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir();
    while(aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}

void ArvBinBusca::imprime()
{
    imprimePorNivel(raiz, 0);
}

void ArvBinBusca::imprimePorNivel(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "--";
        cout << p->getInfo() << endl;
        imprimePorNivel(p->getEsq(), nivel+1);
        imprimePorNivel(p->getDir(), nivel+1);
    }
}

ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return p;
}

float ArvBinBusca::mediaCaminho(int ch)
{
    int soma = 0, cont = 0;
    NoArv *p = raiz;
    while(p != NULL)
    {
        cont++;
        soma += p->getInfo();
        if(ch == p->getInfo())
            break;
        else if(ch > p->getInfo())
            p = p->getDir();
        else
            p = p->getEsq();
    }
    return (float)soma/cont;
}

/*1. Fazer uma operac ̧ao para encontrar, e retornar, o  ̃ maior
elemento de uma arvore bin  ́ aria de busca.  ́
int ArvBinBusca::maior();*/

int ArvBinBusca::maior()
{
    return auxmaior(raiz);
}

int ArvBinBusca::auxmaior(NoArv *p)
{
    if(p!=NULL)
    {
        if(p->getDir() == NULL)
        {
            return p->getInfo();
        }

        return auxmaior(p->getDir());
    }
}

/*2. Fazer uma operac ̧ao para encontrar, e retornar, o  ̃ menor
elemento de uma arvore bin  ́ aria de busca.  ́
int ArvBinBusca::menor();*/

int ArvBinBusca::menor()
{
    return auxmenor(raiz);
}

int ArvBinBusca::auxmenor(NoArv *p)
{
    if(p!=NULL)
    {
        if(p->getEsq() == NULL)
        {
            return p->getInfo();
        }

        return auxmenor(p->getEsq());
    }
}

/*3. Fazer uma operac ̧ao para  ̃ remover o maior elemento de
uma arvore bin  ́ aria de busca.  ́
void ArvBinBusca::removeMaior();*/

void ArvBinBusca::removeMaior()
{
    NoArv *p = raiz;
    while(p->getDir()!=NULL)
    {
        p = p->getDir();
    }

    remove(p->getInfo());
}


void ArvBinBusca::removeMenor()
{
    NoArv *p = raiz;
    while(p->getEsq()!=NULL)
    {
        p = p->getEsq();
    }

    remove(p->getInfo());
}

void ArvBinBusca::removeMin()
{
    auxRemoveMin(raiz);
}

NoArv* ArvBinBusca::auxRemoveMin(NoArv *p)
{
    if(p!=NULL)
    {
        if(p->getEsq() ==NULL)
        {
            NoArv *r = p->getDir();
            delete p;
            return r;
        }
        p->setEsq(auxRemoveMin(p->getEsq()));
        return p;
    }
}

//5. Desenvolver uma operac ̧ao para contar  ̃ quantos n  ́os s ̃ao
//pares no caminho que vai da raiz ate o n  ́ o de valor  ́ x.
//int ArvBinBusca::contaParesCaminho(int x);

int ArvBinBusca::contaParesCaminho(int x)
{
    int cont =0;
    auxcontaParesCaminho(raiz,10, &cont);
    return cont;
}

int ArvBinBusca::auxcontaParesCaminho(NoArv *p, int x, int *cont)
{
    if(p!=NULL)
    {
        if(p->getInfo() == x)
        {
            return *cont;
        }

        if(p->getInfo()%2 ==0)
        {
            *cont = *cont +1;
        }

        if( p->getDir() != NULL && p->getDir()->getInfo() > x)
        {
            auxcontaParesCaminho(p->getEsq(), x, cont);
        }

        if( p->getEsq() != NULL && p->getEsq()->getInfo() < x)
        {
            auxcontaParesCaminho(p->getDir(), x, cont);
        }
    }

    return -1;
}

//6 Alterar a fun ̧c ̃ao de remo ̧c ̃ao de no com dois filhos  ́
//considerando, agora, o maior elemento da sub- ́arvore `a
//esquerda como o elemento a ser trocado com o no a ser  ́
//removido.
//NoArv* ArvBinBusca::maiorSubArvEsq(NoArv *p);

NoArv* ArvBinBusca::maiorSubArvEsq(NoArv *p)
{
    NoArv* aux = p->getEsq();
    NoArv* anterior = NULL;

    while (aux != NULL)
    {
        anterior = aux;
        aux = aux->getDir();
    }

    return anterior;
}






void ArvBinBusca::imprimeFilhos(int x)
{
     auximprimeFilhos(raiz, x);
}

void ArvBinBusca::auximprimeFilhos( NoArv *p, int x)
{
    if(p!=NULL)
    {
        if(p->getInfo() == x)
        {
            cout << p->getEsq()->getInfo() << " " << p->getDir()->getInfo() << endl;
        }

        auximprimeFilhos(p->getEsq(), x);
        auximprimeFilhos(p->getDir(), x);

    }
}

void ArvBinBusca::imprimeIntervalo(int x, int y)
{
    auximprimeIntervalo(raiz, x, y);
}

void ArvBinBusca::auximprimeIntervalo(NoArv *p, int x, int y)
{
    if(p!=NULL)
    {
        if(x< p->getInfo() && p->getInfo() <y)
        {
            cout << p->getInfo() << " ";
        }

        auximprimeIntervalo(p->getEsq(), x, y);
        auximprimeIntervalo(p->getDir(), x, y);
    }
}


void ArvBinBusca::imprimeCrescente()
{
     auximprimeCrescente(raiz);
}
void ArvBinBusca::auximprimeCrescente(NoArv *p)
{
    if(p!=NULL)
    {
        auximprimeCrescente(p->getEsq());

        cout << p->getInfo() << " ";

        auximprimeCrescente(p->getDir());
    }
}


void ArvBinBusca::imprimeDecrescente()
{
    auximprimeDecrescente(raiz);
}
void ArvBinBusca::auximprimeDecrescente(NoArv *p)
{
    if(p!=NULL)
    {
        auximprimeDecrescente(p->getDir());

        cout << p->getInfo() << " ";

        auximprimeDecrescente(p->getEsq());
    }
}


void ArvBinBusca::insereDoVetor(int n, int *vet)
{
    auxinsereDoVetor(n, vet, 0, n-1);
}

void ArvBinBusca::auxinsereDoVetor(int n, int *vet, int p, int q)
{
    if(p>q)
        return;

    int valor = (p + q) /2;

    insere(vet[valor]);


    auxinsereDoVetor(n, vet, p, valor-1);
    auxinsereDoVetor(n, vet, valor+1, q);

}



int ArvBinBusca::contaNos()
{
    return auxContaNos(raiz);
}

int ArvBinBusca::auxContaNos(NoArv *p)
{
    if(p == NULL)
    {
        return 0;
    }

    return 1 + auxContaNos(p->getEsq()) + auxContaNos(p->getDir());
}



int* ArvBinBusca::insereVetorCrescente()
{
    int n = contaNos();
    int cont =0;
    int *vet = new int[n];
    auxinsereVetorCrescente(&cont, vet, raiz);

    for(int i=0; i<n; i++)
    {
        cout << vet[i] << " ";
    }

    return vet;
}
int* ArvBinBusca::auxinsereVetorCrescente(int *cont, int *vet, NoArv *p)
{
    if(p!=NULL)
    {
        auxinsereVetorCrescente(cont, vet, p->getEsq());

        vet[*cont] = p->getInfo();
        *cont = *cont +1;

        auxinsereVetorCrescente(cont, vet, p->getDir());
    }
}


int* ArvBinBusca::insereNoVetDecrescente()
{
    int n = contaNos();
    int cont =0;
    int *vet = new int[n];
    auxinsereVetorCrescente(&cont, vet, raiz);

    for(int i=0; i<n; i++)
    {
        cout << vet[i] << " ";
    }

    return vet;
}

int* ArvBinBusca::auxinsereNoVetDecrescente(int *cont, int *vet, NoArv *p)
{
    if(p!=NULL)
    {
        auxinsereVetorCrescente(cont, vet, p->getDir());

        vet[*cont] = p->getInfo();
        *cont = *cont +1;

        auxinsereVetorCrescente(cont, vet, p->getEsq());
    }
}

NoArv* ArvBinBusca::buscaValor(int val)
{
   NoArv *p = raiz;

   while(p!= NULL)
   {
       if(p->getInfo() == val)
       {
           return p;
       }
       else if(val < p->getInfo())
       {
           p = p->getEsq();
       }
       if(val > p->getInfo())
       {
           p = p->getDir();
       }
   }
   return NULL;

}

int ArvBinBusca::classificaNo(int val)
{
    NoArv *p = raiz;

   while(p->getInfo() != val )
   {
       if(val < p->getInfo())
       {
           p = p->getEsq();
       }
       if(val > p->getInfo())
       {
           p = p->getDir();
       }
   }

   if(p->getDir() != NULL && p->getEsq() != NULL)
   {
       return 2;
   }
   else if((p->getDir() == NULL && p->getEsq() != NULL ) || (p->getDir() != NULL && p->getEsq() == NULL ))
   {
       return 1;
   }
   if(p->getDir() == NULL && p->getEsq() == NULL )
   {
       return 0;
   }

}


void ArvBinBusca::insere2(int val)
{
    NoArv *pn = new NoArv();
    pn->setInfo(val);
    pn->setEsq(NULL);
    pn->setDir(NULL);

    if (raiz == NULL) {
        raiz = pn;
        return;
    }

    NoArv *p = raiz;
    NoArv *pai = NULL;

    while(p!= NULL)
    {
        pai = p;

        if(val < p->getInfo())
       {
           p = p->getEsq();
       }
       if(val > p->getInfo())
       {
           p = p->getDir();
       }
    }

    if (val < pai->getInfo()) {
        pai->setEsq(pn);
    }
    else {
        pai->setDir(pn);
    }

}

int ArvBinBusca::nos1Filho()
{
    int cont = 0;
    auxnos1Filho(&cont, raiz);
    return cont;
}

void ArvBinBusca::auxnos1Filho(int *cont, NoArv *p)
{
    if(p!=NULL)
    {
        if((p->getDir() == NULL && p->getEsq() != NULL) || (p->getDir() != NULL && p->getEsq() == NULL) )
        {
            *cont = *cont +1;
        }

        auxnos1Filho(cont, p->getEsq());
        auxnos1Filho(cont, p->getDir());
    }
}


int ArvBinBusca::nos2Filho()
{
    int cont = 0;
    auxnos2Filho(&cont, raiz);
    return cont;
}

void ArvBinBusca::auxnos2Filho(int *cont, NoArv *p)
{
     if(p!=NULL)
    {
        if(p->getDir() != NULL && p->getEsq() != NULL )
        {
            *cont = *cont +1;
        }

        auxnos1Filho(cont, p->getEsq());
        auxnos1Filho(cont, p->getDir());
    }
}


bool ArvBinBusca::estritamenteBin()
{
    return auxestritamenteBin(raiz);
}


bool ArvBinBusca::auxestritamenteBin(NoArv *p)
{
    if(p == NULL)
    {
        return true;
    }

    if((p->getEsq() != NULL && p->getDir() == NULL) || (p->getEsq() == NULL && p->getDir() != NULL)  )
    {
        return false;
    }

    return auxestritamenteBin(p->getEsq()) && auxestritamenteBin(p->getDir());
}

/*
void ArvBinBusca::transfABemABB()
void ArvBinBusca::auxtransfABemABB();
- Ordena a a arv em um vetor em ordem crescente
- controi a nova a partir do vetor
*/


//Implementar a operação int ArvBinBusca::impressaoParcial(int a, int b);
//que percorre a árvore binária de busca e imprime os valores do intervalo
//aberto (a,b) que estão presentes em nós da árvore em que a soma dos
//valores dos nós filhos (caso existam) é par. Os filhos considerados na soma
//podem ou não pertencer ao intervalo. Ao final da operação, retornar a soma dos
//valores impressos. Obs.: A operação deve utilizar a propriedade das
//árvores binárias de busca e visitar o menor número possível de nós.


 /*int ArvBinBusca::impressaoParcial(int a, int b)
 {
     NoArv *p= raiz;
     int soma=0;

     auximpressaoParcial(raiz, a, b, &soma);

     return soma;
 }

 int ArvBinBusca::auximpressaoParcial(NoArv *p, int a, int b, int *soma)
 {


     if(p!=NULL)
     {

         if(p->getInfo() >= a &&  p->getInfo() <= b)
         {
            if((p->getEsq() != NULL && p->getDir() != NULL) && (p->getEsq()->getInfo() + p->getDir()->getInfo()) %2 ==0 )
            {
                cout << p->getInfo() << " ";

                *soma = *soma + p->getInfo();
            }
         }

         auximpressaoParcial(p->getEsq(), a, b, soma);
         auximpressaoParcial(p->getDir(), a, b, soma);

     }
 }

*/

int ArvBinBusca::impressaoParcial(int a, int b)
 {

    NoArv *p = raiz;

    int soma = 0;
     while(p!=NULL)
     {

         if(p->getInfo() >= a &&  p->getInfo() <= b)
         {
            if((p->getEsq() != NULL && p->getDir() != NULL) && (p->getEsq()->getInfo() + p->getDir()->getInfo()) %2 ==0 )
            {
                cout << p->getInfo() << " ";

                soma = soma + p->getInfo();
            }
         }

         if(p->getEsq() != NULL)
         {
             p= p->getEsq();
         }
         else
         {
             p = p->getDir();
         }
     }

     return soma;
 }

//Desenvolver a operação NÃO RECURSIVA void ArvBinBusca::removeMenor(int val);
//para buscar o valor val em uma árvore binária de busca e remover
//o menor valor da subárvore à esquerda do nó com valor val.
//Cada nó pode ser visitado uma única vez. Imprima uma mensagem para
//cada caso em que não ocorra a remoção.

void ArvBinBusca::removeMenor2(int val)
{
    NoArv *p = raiz;

    while(p!=NULL)
    {
        if(p->getInfo() == val)
        {
            break;
        }

        if(p->getInfo() > val)
         {
             p= p->getEsq();
         }
         else
         {
             p = p->getDir();
         }
    }

    if(p == NULL)
    {
        cout << "valor nao encontrado" << endl;
    }

    NoArv *pai;

    while(p!=NULL)
    {
        pai = p;
        p = p->getEsq();
    }

    remove(pai->getInfo());


}

/*
void ArvBinBusca::removeMenor(int val)
{
    NoArv* p = raiz;
    NoArv* pai = nullptr;

    // Busca pelo nó com valor val
    while (p != nullptr && p->getInfo() != val)
    {
        pai = p;

        if (val < p->getInfo())
            p = p->getEsq();
        else
            p = p->getDir();
    }

    // Se o nó não foi encontrado, imprime uma mensagem e retorna
    if (p == nullptr)
    {
        cout << "Valor não encontrado." << endl;
        return;
    }

    // Encontrou o nó com valor val, encontra o menor valor na subárvore à esquerda
    NoArv* menor = p->getEsq();
    NoArv* menorPai = p;

    while (menor != nullptr && menor->getEsq() != nullptr)
    {
        menorPai = menor;
        menor = menor->getEsq();
    }

    // Se não encontrou um menor valor, imprime uma mensagem e retorna
    if (menor == nullptr)
    {
        cout << "Não há um menor valor na subárvore à esquerda do nó com valor " << val << "." << endl;
        return;
    }

    // Remove o menor valor
    if (menor->getDir() != nullptr)
    {
        // Se o menor valor possui subárvore à direita, atualiza os ponteiros
        menorPai->setEsq(menor->getDir());
    }
    else
    {
        // Caso contrário, remove o menor valor ajustando o ponteiro do pai
        menorPai->setEsq(nullptr);
    }

    delete menor;
}
*/


// Desenvolver a operação NÃO RECURSIVA void ArvBinBusca::removeFilhoEsquerdaK(int k, int val);
//para buscar o nó de nível k que faz parte do caminho de busca
//(com sucesso ou não) do valor val em uma árvore binária de busca.
//Após encontrar o nó de nível k, remover o nó à esquerda deste nó,
//caso exista. Imprima mensagens que indiquem os casos de não remoção.

void ArvBinBusca::removeFilhoEsquerdaK(int k, int val)
{
    NoArv *p = raiz;
    NoArv *pai = NULL;

    int cont =0;

    while(p!=NULL && (cont != k && p->getInfo() != val))
    {

        if(p->getInfo() < val)
        {
            cont = cont +1;
            p=p->getDir();
        }
        else{

            cont =cont +1;
            p=p->getEsq();
        }
    }

    if(p==NULL || p->getInfo() != val )
    {
        cout << " o valor nao foi encontrado" << endl;
        return;
    }

    if(p->getEsq() != NULL)
    {
        remove(p->getEsq()->getInfo());
    }

}

//1) Desenvolver uma operação para uma árvore binária (AB) que calcula estas duas quantidades de forma
//independente (variáveis separadas):
//• o número de nós com valores absolutos impares; e
//• o número de nós com 0 (zero) ou 2 (dois) filhos.
//Esta operação deve percorrer a árvore binária APENAS UMA ÚNICA VEZ fazendo um percurso em pré-ordem.
//Cuidado com a inicialização e atualização dos parâmetros passados por referência. Protótipo: [30]
//void ArvBinBusca::nosImpares02Filhos(int *nImpar, int *n2Filhos);

void ArvBinBusca::nosImpares02Filhos(int *nImpar, int *n2Filhos)
{
    auxnosImpares02Filhos(raiz, nImpar, n2Filhos);
    //cout<< *nImpar << " " << *n2Filhos;
}

void ArvBinBusca::auxnosImpares02Filhos(NoArv *p ,int *nImpar, int *n2Filhos)
{
    if(p!= NULL)
    {
        if(p->getInfo()%2 != 0)
        {
            *nImpar = *nImpar +1 ;
        }

        if( (p->getDir() == NULL && p->getEsq() == NULL) || (p->getDir() != NULL && p->getEsq() != NULL))
        {
            *n2Filhos = *n2Filhos +1;
        }

        auxnosImpares02Filhos(p->getEsq() , nImpar, n2Filhos);
        auxnosImpares02Filhos(p->getDir() , nImpar, n2Filhos);
    }
}

//2) Desenvolver uma operação NÃO RECURSIVA para inserir um novo nó com valor 𝑣𝑎𝑙 em uma árvore binária
//de busca. Caso já exista algum nó com o valor 𝑣𝑎𝑙, não inserir um novo nó e emitir uma mensagem. Protótipo:
//void ArvBinBusca::insNaoRec(int val);

void ArvBinBusca::insNaoRec(int val)
{
    if (raiz == NULL)
    {
        raiz = new NoArv();
        raiz->setInfo(val);
        raiz->setEsq(NULL);
        raiz->setDir(NULL);
        return;
    }

    NoArv *p = raiz;
    NoArv *pai = NULL;

    while (p != NULL)
    {
        pai = p;
        if (val < p->getInfo())
            p = p->getEsq();
        else if (val > p->getInfo())
            p = p->getDir();
        else
        {
            cout << "O valor " << val << " já existe na árvore." << endl;
            return;
        }
    }

    NoArv *novoNo = new NoArv();
    novoNo->setInfo(val);
    novoNo->setEsq(NULL);
    novoNo->setDir(NULL);

    if (val < pai->getInfo())
        pai->setEsq(novoNo);
    else
        pai->setDir(novoNo);
}


//Dados um intervalo fechado 𝐼 = [𝑎, 𝑏] e uma árvore binária de busca (ABB), desenvolver uma operação para
//alocar, retornar e preencher um vetor com os valores de todos os nós do nível 𝑘 da ABB e que estão no
//intervalo 𝐼. Além disso, a operação deve preencher o vetor com os valores dentro do intervalo 𝐼 em ordem
//crescente. O tamanho do vetor (capacidade máxima) deve ser igual a 1 mais o número máximo de nós da
//ABB no nível 𝑘. Caso haja folga no vetor (região do final do vetor não usada para armazenar qualquer valor
//da ABB), ela deve ser preenchida com o valor −1. Considerar que 𝑎 ≤ 𝑏 e, obrigatoriamente, usar a
//propriedade fundamental da ABB para visitar o número mínimo de nós. Não usar nenhum método de
//ordenação de vetores. Protótipo:
//int* ArvBinBusca:: vetIntervalo(int a, int b, int k);

int* ArvBinBusca:: vetIntervalo(int a, int b, int k)
{
    int n = pow(2,k) +1;
    int *vet = new int[n];
    int i = 0;
    int cont =0;
    auxvetIntervalo(raiz, vet, a, b, k , &i, cont );

    for(int j = i; j<n; j++)
    {
        vet[j] = -1;
    }

    return vet;

}

void ArvBinBusca:: auxvetIntervalo(NoArv *p, int *vet, int a, int b, int k, int *i, int cont)
{
    if(p!=NULL)
    {
        auxvetIntervalo(p->getEsq(), vet, a, b, k, i, cont+1);

        if(cont == k && a < p->getInfo()  && p->getInfo() <b )
        {
            vet[*i] = p->getInfo();
            *i = *i+1;

        }

        auxvetIntervalo(p->getDir(), vet, a, b, k, i, cont+1);

    }
}





