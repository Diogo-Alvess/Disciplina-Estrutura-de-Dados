#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad()
{
    cout << "Criando objeto ListaEncad" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaEncad::~ListaEncad()
{
    cout << "Destruindo objeto ListaEncad" << endl;
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaEncad::busca(int val)
{
    No *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaEncad::get(int k)
{
    No *p = primeiro;
    int i = 0;
    while(i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if(p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}

void ListaEncad::set(int k, int val)
{
    No *p = primeiro;
    int i = 0;
    while(i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}


void ListaEncad::insereInicio(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(primeiro);

    primeiro = p;

    n++;
    if(n == 1) ultimo = p;
}

void ListaEncad::insereFinal(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);

    if(ultimo != NULL) ultimo->setProx(p);
    ultimo = p;

    n++;
    if(n == 1) primeiro = p;
}

void ListaEncad::removeInicio()
{
    No* p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;

        n--;
        if(n == 0) ultimo = NULL;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

void ListaEncad::removeFinal()
{
    No* p;
    if(ultimo != NULL)
    {
        if(primeiro == ultimo)
        {
            primeiro = NULL;
            p = NULL;
        }
        else
        {
            p = primeiro;
            while(p->getProx() != ultimo)
                p = p->getProx();
            p->setProx(NULL);
        }
        delete ultimo;
        ultimo = p;
        n--;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}


void ListaEncad::imprime()
{
    No *p = primeiro;

    cout<< "lista: ";
    while(p!=NULL){

        cout << p->getInfo() << " ";

        p= p->getProx();
    }
    cout << endl;
}

int ListaEncad::numNos()
{
   return n;
}

int ListaEncad::buscaMaior(int val)
{
    No* p= primeiro;
    int cont = 0;

    while(p!=NULL)
    {
       if(p->getInfo() > val)
       {
           return cont;
       }

       cont++;
       p=p->getProx();
    }

    return -1;
}

void ListaEncad::limpar()
{
    while( primeiro != NULL)
    {
        removeInicio();
    }
}

float ListaEncad::calculaMedia()
{
    No* p = primeiro;
    float valor = 0;

    while(p != NULL)
    {
        valor = valor + p->getInfo();

        p=p->getProx();
    }

    valor = valor /n;
    return valor;
}

void ListaEncad::concatena(ListaEncad *l2)
{
    No *p = l2->primeiro;

    while(p!=NULL)
    {

        insereFinal(p->getInfo());

        p = p->getProx();
    }
}

ListaEncad* ListaEncad::partir(int x)
{
    ListaEncad *l1 = new ListaEncad();
    ListaEncad *l2 = new ListaEncad();

    No *p= primeiro;
    int k = 0;

    while( p!= NULL)
    {
        if(k < x)
        {
            l1->insereFinal(p->getInfo());
        }
        if(k >= x)
        {
            l2->insereFinal(p->getInfo());
        }

        k++;
        p=p->getProx();
    }
    l2->imprime();

    return l2;
}


/*2. Criar um TAD Lista Encadeada de forma que todos os nos ́
da lista fiquem sempre em ordem crescente. Dica:
desenvolver uma unica operac ̧  ́ ao de inserc ̧  ̃ ao na lista de tal  ̃
forma que o valor do novo no mantenha a lista em ordem  ́
crescente.*/

void ListaEncad::insereOrdenado(int val)
{
    No *p = primeiro;

    while(p!=NULL && p->getInfo() < val)
    {
        p= p->getProx();
    }
    // p = 4;
    No *nv= new No();
    nv->setInfo(val);
    nv->setProx(p); //  3 é nv e o proximo dele é p que é 4

    if (p == primeiro) { // se os dois forem igual a null...
    primeiro = nv;  // Atualiza o primeiro nó se o novo nó for inserido no início da lista
    } else {

    No* anterior = primeiro;
    while (anterior->getProx() != p) {
        anterior = anterior->getProx();
    }
    // anterior = 2
    anterior->setProx(nv);  // Atualiza o ponteiro do nó anterior para o novo nó
    n++;
    }
    imprime();
}

/* Desenvolver uma nova operac ̧ao para inserir um novo n  ̃ o ́
em uma determinada posic ̧ao da lista, a qual ser  ̃ a ́
especificada por um parametro k */
void ListaEncad::novoNo(int k, int valor)
{
    if(k > n)
    {
        cout << "indice invalido: k > n" << endl;
    }
    else{
    No* p = primeiro;

    int cont = 0;
    while(p !=  NULL && cont < k)
    {
        cont++;
        p=p->getProx();
    }

    No *nv = new No();
    nv->setInfo(valor);
    nv->setProx(p);

    No* ant = primeiro;

    while(ant->getProx() != p)
    {
        ant = ant->getProx();
    }

    ant->setProx(nv);
    n++;

    imprime();
    }
}

/*
4. Desenvolver uma nova operac ̧ao para remover o  ̃ ultimo n  ́ o ́
da lista.
*/

void ListaEncad::removeFinal1()
{
    No* p;

    if(ultimo != NULL)
    {
        if(primeiro == ultimo)
        {
            primeiro = NULL;  // primeiro passa a apontar pra nada
            p = NULL;
        }
        else
        {
            p = primeiro;
            while(p->getProx() != ultimo)
            {
                p = p->getProx();
            }

            p->setProx(NULL);
        }
        delete ultimo;
        ultimo = p;
        n--;

    }
     else
        cout << "ERRO: lista vazia!" << endl;
    imprime();
}

/*
4. Considerando o TAD ListaEncad que representa uma lista simplesmente encadeada de valores
inteiros, implementar uma fun ̧c ̃ao para retornar o n ́umeros de n ́os da lista que possuem o campo
info maior que o valor inteiro val.
int ListaEncad :: contaMaiores (int val ) ;
*/

int ListaEncad :: contaMaiores (int val )
{
    No *p = primeiro;
    int cont = 0;

    while( p != NULL)
    {
        if(p->getInfo() > val)
        {
            cont++;
        }

        p = p->getProx();
    }

    return cont;

}

/*
8. Implemente uma opera ̧c ̃ao do TAD ListaEncad que verifica se duas listas encadeadas s ̃ao iguais
e que retorna true, caso sejam, e false, caso contr ́ario. Duas listas s ̃ao consideradas iguais se
tˆem a mesma sequˆencia de elementos.
bool ListaEncad :: igual ( ListaEncad * l2 ) ;
*/

bool ListaEncad :: igual( ListaEncad * l3 )
{
    No *p = primeiro;
    No *g = l3->primeiro;

    while(p != NULL && g != NULL)
    {
        if(p->getInfo() != g->getInfo())
        {
            return false;
        }

        p = p->getProx();
        g = g->getProx();
    }


    return true;
}

void ListaEncad :: removeValor (int val )
{
     No* rem = primeiro;
    No* anterior = nullptr;

    while (rem != nullptr)
    {
        if (rem->getInfo() == val)
        {
            if (anterior == nullptr)
            {
                primeiro = rem->getProx();
            }
            else
            {
                anterior->setProx(rem->getProx());
            }

            No* proximo = rem->getProx();
            delete rem;
            rem = proximo;
            n--;
        }
        else
        {
            anterior = rem;
            rem = rem->getProx();
        }
    }

    imprime();
}
/*Considere o TAD ListaEncad que representa uma lista simplesmente encadeada de inteiros (detalhes deste TAD no projeto). Implementar a opera¸c˜ao void ListaEncad::removeBloco(int
a, int b) que remove todos os elementos localizados entre o elemento com valor a e o elemento com
valor b, inclusive a e b. A opera¸c˜ao deve percorrer a lista uma ´unica vez. Assuma que: (i) o elemento
de valor a, se houver, aparecer´a antes do elemento com b; (ii) n˜ao havendo a na lista ent˜ao nenhum
elemento deve ser removido; e (iii) havendo um elemento com o valor a mas n˜ao havendo um com b
ent˜ao todos os elementos a partir de a devem ser removidos.*/
void ListaEncad::removeBloco(int a, int b)
{
   No *p = primeiro;
   No *ant = NULL;

   // encontrar o elemento com valor "a" , p
   while(p != NULL && p->getInfo() != a)
   {
       ant = p;
       p = p->getProx();
   }

   if(p==NULL)
   {
       // nao ha o elemento "a", nao é necessario remover nada
       return;
   }

   //Remover elemento entre a e b;
   while(p != NULL && p->getInfo() != b)
   {
       No *n = p->getProx();
       delete p;
       p = n;
   }

   if(p != NULL)
   {
       //remover o elemento b tambem
       No *n = p->getProx();
       delete p;
       p = n;
   }

    //atualizar o ponteiro do nó anterior e proximo
    if(ant != NULL)
    {
        ant->setProx(p);
    }
    else{
        primeiro = p;
    }

   imprime();

}


