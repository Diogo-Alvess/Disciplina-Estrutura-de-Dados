#include <iostream>
#include <string>

using namespace std;
/*PONTEIROS 

int updates = 6; // variavel
int *p_updates;  // ponteiro, * operador conteudo de.
p_updates = &updates; // ponteiro aponta para o endereço da var, & operador endereço.
// é assim que declara ponteiro..

// imprime valores
cout << "Valor: updates = " << updates;
cout << ", *p_updates = " << *p_updates;
cout << endl;
// imprime enderecos
cout << "Endereco: &updates = " << &updates;
cout << ", p_updates = " << p_updates << endl;
// usa ponteiro para alterar o conteudo
*p_updates = *p_updates + 1;
cout << "Valor atualizado: updates = ";
cout << updates << endl;

ARITMÉTICA DE PONTEIROS
- Somar 1 a uma variavel do tipo ponteiro incrementa seu valor dependendo do tipo do ponteiro.
EX:
int x;
int *ap;
cout << "Digite x: ";
cin >> x;
ap = &x;
cout << "Endereco de x: " << &x << endl;
cout << "Valor de ap : " << ap << endl;
cout << "Valor de ap+1: " << *ap+1 << endl;  //
cout << "Valor de ap+2: " << ap+2 << endl;

Ponteiros e Arrays
-o nome de um vetor e um ponteiro. Ou seja, pode-se acessar os elementos de um vetor de duas formas.
-Usando o operador []: vet[2];
-Usando aritmetica de ponteiros: *(vet+i);

Ponteiros e o valor NULL
-O valor NULL e um valor especial que significa que o ponteiro esta apontando para nada.
int * ptr = NULL;
// ou
int * ptr = 0;

Ponteiros e Funçoes
-Passagem por valor
I Mesmo que a funcao altere o valor, esta alteraçao nao
permanecera no parametro original apos o retorno da funcao.
-Passagem por referencia.
I Se a funçao alterar o valor do objeto passado, essa alteracao sera realizada no objeto original.
ex:
void troca(int *a, int *b)
{
int aux = *b;
*b = *a;
*a = aux;
}

int main()
{
int x=2, y=30;
troca(&x, &y);
cout << "x = " << x << " , ";
cout << "y = " << y << endl;
return 0;
}

Sendo assim, pode-se alterar os valores dos elementos do
array dentro da funcao.

void incr_vet(int tam, int vet[]) {
 int i;
  for(i=0; i<tam; i++)
   vet[i] = vet[i] + 1;
}

int main() {
 int v[]={10, 20, 5};
 incr_vet(3, v);
 cout << v[0] <<" "<<v[1]<<" "<<v[2]<< "\n";
 return 0;
}

Exercıcios
1. Ponteiro e aritmetica de ponteiro. Faca esse exercıcio com
auxılio do computador e verifique o entendimento das
operacoes. Sejam ̃i e j sao variaveis inteiras e p e q
ponteiros para inteiros. Quais das seguintes expressoes de atribuicao sao ̃incorretas?
a) p = &i; correto
b) *q=&j; correto
c) p=&*&i; correto
d) i=(*&)j; errado
e) i=*&*&j; correto
f) q=&p; correto
g) i=(*p)++ + *q; correto
h) if(p==i)i++; errado

2. O que fazem as seguintes funcoes: 
void func( ) {
int mat[ ] = {1, 10, 100};
for(int j=0; j<3; j++)
cout << *(mat+j) << endl;
} //aritimetica dos ponteiros, percorre os valores do vetor
void func( ){
int mat[ ] = {1, 10, 100};
for(int j=0; j<3; j++)
cout << (mat+j) << endl;
} //aritimetica dos ponteiros, percorre os endereços do vetor
void func( ) {
int mat[ ] = {1, 10, 100}; int *p=mat;
for(int j=0; j<3; j++)
cout << (*p)++ << endl;
} //add 1 ao primeiro elemento do vet n vezes


3. Implementar uma unica funçao que recebe um vetor de  
numeros inteiros (vet) e o seu tamanho (tam) e  
I conte o total de elementos pares
I conte o total de elementos impares
I conte o total de elementos negativos
I e por fim, retorne verdadeiro se existirem numeros  
negativos no vetor, ou retorne falso, caso contrario. 
Considere o seguinte prototipo:
bool func(int tam, int vet[], int *par, int *imp, int *neg);


bool func(int tam, int vet[], int *par, int *imp, int *neg)
{

    for(int i = 0; i<=tam; i++)
    {
        if(vet[i]%2 == 0)
        {
            *par = *par +1;
        }
        if(vet[i]%2 != 0)
        {
            *imp = *imp +1;
        }
        if(vet[i] < 0)
        {
            *neg = *neg +1;
        }
    }

    if( neg != 0)
    {
        return true;
    }

    return false;
}


int main()
{

    int par=0;
    int imp=0;
    int neg = 0;
    int tam = 5;
    int vet[tam] = {1,2,-2,3,5,0};

    func(tam, vet, &par, &imp, &neg);

    cout << "num pares: " << par << ", num impares: " << imp << ", num de negativos: " << neg << endl;
    return 0;
}

1. Fac ̧a um programa que realize as seguintes operac ̧oes:  ̃
I Declare um ponteiro para inteiro pt.
I Imprima o enderec ̧o de pt.
I Crie uma variavel inteira  ́ x.
I Leia um valor para x.
I Fac ̧a com que pt aponte para x.
I Imprima o conteudo da vari  ́ avel  ́ pt.
I Imprima o enderec ̧o de x.
I Usando apenas o ponteiro pt multiplique x por 10 e altere
o seu valor.
I Imprima o conteudo apontado por  ́ pt.
I Some 10 a vari ` avel  ́ pt.
I Imprima o seu conteudo novamente. Qual o significado  ́
desta sa ́ıda?

int main()
{
   int *pt;
   cout << "endereço de pt: " << &pt << endl;
   int x; 
   cin >> x; 
   pt = &x;
   cout << "conteudo da varaivel pt: " << *pt << endl;
   cout << "endereço de x: " << &x << endl;
   *pt = *pt * 10;
   cout << "conteudo apontado por pt: " << x << endl;
   *pt = *pt + 10;
   cout << "conteudo novamente: " << *pt;

}

2. Implemente a func ̧ao ̃ troca que troca o conteudo de duas  ́
variaveis inteiras  ́ a e b. Fac ̧a um programa que teste a
func ̧ao implementada. Prot  ̃ otipo:  ́
void troca(int *a, int *b);

void troca(int *a, int *b){

   int aux = *a;
   *a = *b;
   *b = aux;

}

int main()
{
   int a =10;
   int b =20;

   troca(&a, &b);

   cout << "valor de a: " << a << " e de b: " << b << endl;

   return 0;

}

3. Dados dois numeros inteiros  ́ num e div, fac ̧a uma func ̧ao ̃
para calcular e retornar o quociente e o resto da divisao ̃
inteira de num por div. Considerar o seguinte prototipo:  ́
void divisao(int num, int div, int *q, int *r);
onde:
I num e dividendo;  
I div e o divisor;  
I q e o quociente;  
I r e o resto.  

void divisao(int num, int div, int *q, int *r)
{
   *q = num/div;
   *r = num%div;

}

int main()
{
   int num = 40;
   int div =4;
   int q, r =0;

   divisao(num, div, &q, &r);

   cout << "valor de q: " << q << " e de r: " << r << endl;

   return 0;

}

*/




