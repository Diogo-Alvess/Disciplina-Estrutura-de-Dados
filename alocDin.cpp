#include <iostream>
#include <string>

using namespace std;

/*
// ALOCAÇÃO DINAMICA

A aloca ̧c ̃ao dinamica de memoria permite reservar
espacos de memoria de tamanho arbitrario e acessa-los 
atraves de ponteiros. Desta forma, podemos escrever programas mais flexıveis,
pois nem todos os tamanhos devem ser definidos ao screver o programa.

NEW - é usado para alocar memoria em tempo de execuçao.
DELETE - libera o uso de um bloco de memoria, permitindo que este espaco seja reaproveitado.

E recomendado que o uso do new seja sempre balanceado
com o uso do delete, caso contrario voce estara perdendo  
memoria que poderia ser usada. 

I Alocou memoria com  new tipo;
I Desaloca com delete;
I Alocou memoria com  new tipo[tam];
I Desaloca com delete []; 

// modo certo funçao com vet
float* somaVetores(float u[], float v[])
{
    float *r = new float[3]; // alocacao dinamica
    r[0] = u[0] + v[0];
    r[1] = u[1] + v[1];
    r[2] = u[2] + v[2];

    return r;
}

int i, dim=3;
float vecU[3] = {1.0,1.0,1.0};
float vecV[3] = {2.0,1.0,-1.0};
float *vecRes = somaVetores(vecU, vecV);
for(i=0; i<dim; i++){
cout << "resultado " << i << " = ";
cout << vecRes[i] << endl;
}
delete [] vecRes;

Dinamica: tamanhos podem ser determinados em tempo de execuçao 

int n;
cin >> n; // assumindo n >= 4
int *ptr;
ptr = new int[n];
ptr[3] = 99;
// ...
delete [] ptr;

5. Faça um programa que leia um numero inteiro n e aloque
um vetor com n inteiros de forma dinamica (use o
operador new). Em seguida, o programa deve ler os
valores do vetor e calcular a media dos elementos desse
vetor. Por fim, deve desalocar (use o operador delete) a
memoria usada para armazenar os seus elementos. 


int main()
{
    int n;
    cin >> n;
    int *vet = new int[n];

    float soma, media = 0;

    for(int i = 0; i< n; i++)
    {
        cin >> vet[i];
        soma = soma + vet[i];
    }

    media = soma/ n;

    cout<< "media: " << media << endl;

    delete [] vet;

    return 0;

}

6. Implemente uma funcao que calcule o produto escalar  
entre dois vetores do tipo de dados float. No programa
principal voce deve ler o tamanho n dos vetores, os quais
devem ser alocados dinamicamente usando new. Depois,
voce deve ler os dados dos vetores e chamar a funcao para  
calcular o produto escalar. Por fim, use o operador
delete para desalocar toda memoria alocada de forma 
dinamica. Prototipo:  
float prodEscalar(int n, float x[], float y[]);
Ex. O produto escalar entre x = [1, 2, 3] e y = [4, 5, 6] e dado  
por:
x · y = 1 × 4 + 2 × 5 + 3 × 6 = 32.

float prodEscalar(int n, float x[], float y[])
{
    float prodEsc = 0;

    for(int i = 0; i < n; i++)
    {
        prodEsc =  prodEsc + (x[i] * y[i]);
    }

    return prodEsc;

}

int main()
{

    int n;
    cout << "tamalho dos vetores: ";
    cin >> n;

    float *vet1= new float[n];
    float *vet2= new float[n];

    for(int i = 0; i < n; i++)
    {
        cout<< "valor [" << i << "] do vet1: ";
        cin >> vet1[i];
        cout<< "valor [" << i << "] do vet2: ";
        cin >> vet2[i];
    }

    cout << "produto escalar = " << prodEscalar(n, vet1, vet2);

    delete [] vet1;
    delete [] vet2;

    return 0;

}

4. Fac ̧a um programa que leia um numero inteiro  ́ N e que
aloque dinamicamente um vetor com N elementos reais e
fac ̧a a leitura dos seus valores. Em seguida, calcule a
media dos valores do vetor e imprima na tela. Por fim,  ́
libere a memoria alocada de forma din  ́ amica. ˆ
5. Modifique o exerc ́ıcio anterior e crie uma func ̧ao para  ̃
realizar a tarefa de calcular a media dos elementos do  ́
vetor. Prototipo:  ́
float calcMedia(int n, float vet[]);
6. Modifique o exerc ́ıcio anterior e crie agora uma func ̧ao ̃
para alocar vetores de numeros reais de tamanho  ́ N de
forma dinamica. Prot ˆ otipo:  ́
float* alocaVetor(int n);

*/

float calcMedia(int n, float vet[])
{
    float soma, media = 0;
    for(int i = 0; i < n; i++)
    {
        soma = soma + vet[i];
    }

    media = soma/n;

    return media;
}

float* alocaVetor(int n)
{
    float *vet = new float[n];
    return vet;
}

int main()
{

    int n;
    cin >> n;
    
    float *vetResp = alocaVetor(n);
    for(int i = 0; i<n; i++)
    {
        cin >> vetResp[i];
    }

    cout << calcMedia(n, vetResp);

    delete [] vetResp;
    return 0;

} 











