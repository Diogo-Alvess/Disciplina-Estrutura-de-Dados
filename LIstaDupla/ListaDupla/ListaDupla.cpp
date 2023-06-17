#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    cout << "Criando uma ListaDupla" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    cout << "Destruindo ListaDupla" << endl;
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaDupla::busca(int val)
{
    NoDuplo *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaDupla::get(int k)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
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

void ListaDupla::set(int k, int val)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}

void ListaDupla::insereInicio(int val)
{
	NoDuplo *p = new NoDuplo();
	p->setInfo(val);
	p->setProx(primeiro);
	p->setAnt(NULL);

	if(n == 0) ultimo = p;
	else primeiro->setAnt(p);

	primeiro = p;
	n = n + 1;
}

void ListaDupla::removeInicio()
{
	NoDuplo *p;
	if(primeiro != NULL)
	{
		p = primeiro;
		primeiro = p->getProx();
		delete p;
		n = n - 1;

		if(n == 0) 	ultimo = NULL;
		else primeiro->setAnt(NULL);
	}
	else
        cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::insereFinal(int val)
{
    NoDuplo *nv = new NoDuplo();
    nv ->setAnt(ultimo);
    nv ->setInfo(val);
    nv ->setProx(NULL);

    if(n == 0)
    {
       primeiro = nv;
       ultimo = nv;

    }
    else
    {
        ultimo ->setProx(nv);
        ultimo = nv;
    }

    n++;
}

void ListaDupla::removeFinal()
{
    NoDuplo *remover = ultimo;
    ultimo = ultimo->getAnt();

    if(ultimo != NULL)
        ultimo -> setProx(NULL);
    else
        primeiro = NULL; // a lista esta vazia apos a remoçao

    delete remover;
    n--;
}

 void ListaDupla::imprime()
 {
    cout << "lista: ";
    NoDuplo *p= primeiro;

    while(p!=NULL)
    {
        cout<< p->getInfo() << " ";
        p=p->getProx();
    }

    cout << endl;
 }

void ListaDupla::imprimeReverso()
{
    cout << "lista Reversa: ";
    NoDuplo *p = ultimo;

    while(p != NULL)
    {
        cout<< p->getInfo() << " ";
        p= p->getAnt();
    }

    cout << endl;

}

ListaDupla* ListaDupla::concatena(ListaDupla *l2)
{
    ListaDupla *res = new ListaDupla();

    NoDuplo *p = primeiro;

    while(p!=NULL)
    {
        res->insereFinal(p->getInfo());
        p=p->getProx();
    }

    NoDuplo *f = l2->primeiro;

    while(f!=NULL)
    {
        res->insereFinal(f->getInfo());
        f=f->getProx();
    }

    res->imprime();

    return res;
}


ListaDupla* ListaDupla::partir(int x)
{
    ListaDupla *l1 = new ListaDupla();
    ListaDupla *l2 = new ListaDupla();

    NoDuplo * p = primeiro;

    while(p!=NULL && p->getInfo() != x)
    {
        l1->insereFinal(p->getInfo());
        p= p->getProx();
    }
    while(p!=NULL)
    {
        l2->insereFinal(p->getInfo());
        p= p->getProx();
    }


    l1->imprime();
    l2->imprime();

    return (l1,l2);
}

void ListaDupla::removeOcorrencias(int val)
{
    NoDuplo *p= primeiro;
    NoDuplo *ant = NULL;
    NoDuplo *prox = NULL;

    while(p!=NULL)
    {
        if(p->getInfo() == val)
        {
            ant = p->getAnt();
            prox= p->getProx();
            delete p;
            p = ant;
            p-> setProx(prox);

            n--;
        }
        else
        {p=p->getProx();}
    }

}

/* Considere o TAD ListaDupla para representar uma lista duplamente encadeada de
inteiros (detalhes deste TAD no projeto). Implementar a opera¸c˜ao removeMaior() que remove o n´o
com maior valor de uma lista duplamente encadeada. A opera¸c˜ao deve percorrer a lista uma ´unica vez.
Imprima uma mensagem de erro caso n˜ao seja poss´ıvel remover o n´o.*/

void ListaDupla::removeMaior()
{
    NoDuplo *p= primeiro;
    NoDuplo *ant = NULL;
    NoDuplo *prox = NULL;
    NoDuplo *m = NULL;
    int cont =0;

    if(primeiro == NULL)
    {
        cout<< "Erro, lista vazia"<< endl;
    }
    while(p!=NULL)
    {
        if(p->getInfo() > cont)
        {
            cont = p->getInfo();
            m=p;
        }
        p=p->getProx();
    }

    ant = m->getAnt();
    prox= m->getProx();
    delete m;
    m = ant;
    m-> setProx(prox);

    n--;
}

/*
 Implementar a operação void ListaDupla::anexar(ListaDupla *lde) para, dado um ponteiro
para uma LDE lde, anexar a lde com a lista intrínseca, nesta ordem. Alterar apenas os ponteiros necessários
para a anexação. Não pode haver movimentações de valores dos nós das listas e nem pode criar uma nova
LDE e adicionar os nós das listas nessa nova lista. A lista lde deve se tornar vazia no fim da operação. [25]
Exemplo: Considere a lista intrínseca inicial L=[1,2,3,4,5] e lde=[3,8,15]. Após a execução de
L.anexar(lde), obtém-se: L→[3,8,15,1,2,3,4,5] e lde→[ ].
*/

void ListaDupla::anexar(ListaDupla *l2)
{
    if(l2->n >0) ///lde vazia. Lista implícita fica intacta
    {
        if(n ==0)
        {
            primeiro = l2->primeiro;
            ultimo = l2->ultimo;
        }
        else
        {
            l2->ultimo->setProx(primeiro);
            primeiro->setAnt(l2->ultimo);

            primeiro = l2->primeiro;

        }
        n = n + l2->n;

        ///torna a lista l2 vazia
        l2->primeiro =NULL;
        l2->ultimo =NULL;
        l2->n = 0;
        }
}

/* Considere o TAD ListaDupla para representar uma lista duplamente encadeada de inteiros. Implementar
a operação void ListaDupla::trocaSegundoPenultimo() que realiza a troca do segundo pelo
penúltimo nó de uma lista duplamente encadeada. A operação deve realizar a troca dos nós e não somente
de suas informações. Somente realizar a troca se a lista possuir mais do que quatro nós. Imprima uma
mensagem de erro caso a troca não seja efetuada. Não utilizar outras operações do TAD.*/

void ListaDupla::trocaSegundoPenultimo()
{
    if(n > 4)
    {
        NoDuplo *segundo = primeiro->getProx();
        NoDuplo *penultimo = ultimo->getAnt();
        NoDuplo *terceiro = segundo->getProx();
        NoDuplo *antepenultimo = penultimo->getAnt();

        penultimo->setAnt(primeiro);
        penultimo->setProx(terceiro);

        segundo->setAnt(antepenultimo);
        segundo->setProx(ultimo);

        primeiro->setProx(penultimo);
        ultimo->setAnt(segundo);

        terceiro->setAnt(penultimo);
        antepenultimo->setProx(segundo);

    }
    else{
        cout << "a lista possui menos que 4 ou 4 nos" << endl;
    }
}

int* ListaDupla::append(int n)
{
    if(n>0)
    {
        int cont =0;

        No* p= primeiro;

        while()
        {

        }
    }
}































