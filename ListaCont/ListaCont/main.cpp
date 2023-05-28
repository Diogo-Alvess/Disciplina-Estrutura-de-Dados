#include <iostream>
#include "Ponto.h"
#include "ListaCont.h"

using namespace std;
/*Fac ̧a um programa que crie 3 listas cont ́ıguas L1, L2 e L3.
Inicialize L1 com 50 valores quaisquer ate que a lista esteja  ́
cheia. Em seguida, retire a primeira metade de L1 e guarde
em L2. Fac ̧a o mesmo com a segunda metade, mas guarde
em L3. Imprima L2 e L3.
Observa ̧c ̃ao: Utilize apenas as operac ̧oes de inserc ̧  ̃ ao e  ̃
remoc ̧ao do TAD  ̃ ListaCont.*/
void particiona(ListaCont *l1, ListaCont *l2, ListaCont *l3)
{
    for(int i = 0; i < 3; i++)
    {
        l2->insereFinal(l1->get(i));
    }

    for(int i = 3; i < 6; i++)
    {
        l3->insereFinal(l1->get(i));
    }

    l1->limpar();
}


int main()
{
    ListaCont l(10);

    l.insereFinal(2);
    l.insereFinal(3);
    l.insereFinal(24);
    l.insereFinal(-1);
    l.insereFinal(99);
    cout << "Numero de nos: " << l.numNos() << endl;
    cout<< "Valor maior que " << 5 << " no indice: " << l.buscaMaior(5) << endl;
    l.imprime();
    //l.limpar();
    //l.imprime();
    int vet2[5] = {1,2,3,4,5};

    l.insereValores(5, vet2);
    l.imprime();
    cout << "Numero de nos: " << l.numNos() << endl;

    cout << "os valores foram trocados trocou? " << l.troca(2, 5) << endl;
    l.imprime();

    ListaCont l1(10);

    l1.insereFinal(2);
    l1.insereFinal(3);
    l1.insereFinal(24);
    l1.insereFinal(-1);
    l1.insereFinal(99);
    l1.insereFinal(9);

    l1.imprime();

    ListaCont l2(5);

    ListaCont l3(5);

    particiona(&l1, &l2, &l3);

    l2.imprime();
    l3.imprime();



    //cout << l.troca(2,4) << endl;
    //cout << l.aumentaCapacidade(15) << endl;



    return 0;
}
