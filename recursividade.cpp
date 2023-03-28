#include <iostream>
#include <string>

using namespace std;

/* 
1. (Aquecimento) Implemente uma func ̧ao ̃ recursiva para
calcular o fatorial de um numero inteiro  ́ n.
int fatorial(int n);

int fatorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n* fatorial(n-1);
    }
}

2. Desenvolva uma func ̧ao ̃ recursiva que, dados tres valores ˆ
inteiros como parametros ˆ a, b e inc, imprime o intervalo
fechado de a ate ́ b com incremento inc.
void imprimeIntervalo(int a, int b, int inc);
Exemplo: imprimeIntervalo(1,8,2)
Sa ́ıda: 1 3 5 7

void imprimeIntervalo(int a, int b, int inc)
{
    if(a <= b )
    {
        cout << a << " ";
        return imprimeIntervalo(a+inc, b, inc);
    }
}

int main()
{
    int a;
    int b;
    int inc;

    cin >> a;
    cin >> b;
    cin >> inc;

    imprimeIntervalo(a, b, inc);

    return 0;
}

3. Desenvolver uma func ̧ao ̃ recursiva que recebe um valor
inteiro n e imprime todos os inteiros de n ate 0 de forma  ́
decrescente.
void imprimeDecrescente(int n);

void imprimeDecrescente(int n)
{
    if( n == 0 )
    {
        cout << n;
    }
    else {

        cout << n << " ";
        return imprimeDecrescente(n-1);
    }
}

int main()
{
    int n;

    cin >> n;

    imprimeDecrescente(n);

    return 0;
}

4. Desenvolver uma func ̧ao recursiva que recebe um vetor de  ̃
reais e seu tamanho n, calcular e retornar a soma de todos
os seus valores.
float soma(int n, float vet[]);

float soma(int n, float vet[])
{
    if( n == 0)
    {
        return vet[n];
    }
    else{

        return vet[n] + soma(n-1, vet);
    }

}

int main()
{
    int n;

    cin >> n;

    float *vet = new float[n];

    for(int i = 0; i<n; i++)
    {
        cin >> vet[i];
    }

    cout << soma(n, vet);
    
    delete [] vet;

    return 0;
}

5. Desenvolver uma func ̧ao ̃ recursiva que recebe um vetor de
numeros reais e o seu tamanho  ́ n, calcula e retorna o
menor valor do vetor.
float menor(int n, float vet[]);

float menor(int n, float vet[])
{

    if(n==1)
    {
        return vet[0];
    }

    float x = menor(n-1, vet); // empinha do maior tam para o menor e desempinha do menor para o maior
    
    // o processo de comparação so chega ao fim quando o x desempinhar por completo
    
    if(x < vet[n-1]) // compara 
    {
        return x;
    }
    else
        return vet[n-1]; // passa pra o proximo vet de tam menor 
}

int main()
{
    int n;

    cin >> n;

    float *vet = new float[n];

    for(int i = 0; i<n; i++)
    {
        cin >> vet[i];
    }

    cout << menor(n, vet);

    delete [] vet;

    return 0;
}


*6. Desenvolver uma func ̧ao recursiva para calcular e retornar  ̃
a quantidade de valores pares de um vetor com n numeros  ́
inteiros.
int contaPares(int n, int vet[]);*/

int contaPares(int n, int vet[])
{
    if(n == 0)
    {
        if(vet[0]%2 == 0)
        {
            return 1;
        }
        else
            return 0;
    }

    int x = contaPares(n-1, vet);

    if(vet[n-1]%2 == 0)
    {
        return x+1;
    }
    else
        return x;

}

int main()
{
    int n;

    cin >> n;

    int *vet = new int[n];

    for(int i = 0; i<n; i++)
    {
        cin >> vet[i];
    }

    cout << contaPares(n, vet);

    delete [] vet;

    return 0;
}
