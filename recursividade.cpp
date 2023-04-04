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


6. Desenvolver uma func ̧ao recursiva para calcular e retornar  ̃
a quantidade de valores pares de um vetor com n numeros  ́
inteiros.
int contaPares(int n, int vet[])

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

5 Desenvolver uma função recursiva para calcular e retornar
uma string de caracteres contendo ‘0’ e ‘1’ correspondente
à versão binária de um número inteiro positivo dado.


void binaria(int n)
{
    if( n == 1 )
    {
        cout << n;
    }
    else
    {
        binaria(n/2);
        cout << n%2;
    }

}

int main()
{
    int n;

    cin >> n;

    binaria(n);

    return 0;
}

26. Escreva uma fun ̧c ̃ao recursiva que calcule a soma dos n ́umeros de a at ́e b, onde a e b s ̃ao dados
como parˆametro para a fun ̧c ̃ao e s ̃ao tais que a < b.
int soma(int a, int b);



int soma(int a, int b)
{
    if( a >= b )
    {
        return a;
    }
    else
    {
        return a + soma(a+1, b);
    }

}

int main()
{
    int n;
    int m;


    cin >> n;
    cin >> m;

    cout << soma(n, m);

    return 0;
}

27. O n ́umero de d ́ıgitos de um n ́umero inteiro positivo pode ser determinado atrav ́es de sucessivas
divis ̃oes por 10 (sem guardar o resto) at ́e que o n ́umero seja menor do que 10, consistindo
de apenas 1 d ́ıgito. Implemente uma fun ̧c ̃ao recursiva que calcule o n ́umero de d ́ıgitos de um
inteiro positivo n.
int numDigitos(int n);


int numDigitos(int n)
{
    if( n < 10 )
    {
        return 1;
    }
    else
    {
        return 1 + numDigitos(n/10);
    }

}

int main()
{
    int n;

    cin >> n;

    cout << numDigitos(n);

    return 0;
}

29. Escreva uma fun ̧c ̃ao recursiva que fa ̧ca a busca por uma chave (um valor espec ́ıfico) em um
array ordenada usando o algoritmo da busca bin ́aria. A fun ̧c ̃ao recebe como parˆametros o array
de inteiros, seu tamanho e a chave a ser procurada e deve retornar se encontrou ou n ̃ao o valor
da chave.
bool buscaBinaria(int vet[], int n, int chave);

bool buscaBinaria(int vet[], int n, int chave)
{
    float c = 0;
     if( vet[n] == 1)
     {
         if(vet[n] == chave)
         {
             return true;
         }
         else{
            return false;
         }
     }

     c = buscaBinaria(vet, n-1, chave);

     if(vet[n-1] == chave )
     {
         return c + true;
     }
     else

        return c + false;


}

int main()
{
    int n;
    int chave;
    int *vet = new int[n];

    cout << "digite o valor da chave: ";
    cin >> chave;
    cout << "digite n: ";
    cin >> n;
    cout << "preencha o vetor: ";

    for(int i = 0; i< n ; i++)
    {
        cin >> vet[i];
    }

    cout << buscaBinaria(vet, n, chave);

    delete [] vet;
    return 0;

}

28. Escreva uma fun ̧c ̃ao recursiva que determina se um vetor de caracteres  ́e um pal ́ındromo. A
fun ̧c ̃ao recebe como parˆametros o tamanho e o vetor e deve retornar true ou false.
bool ehPalindromo(char a[], int n);

bool ehPalindromo(char a[], int n){
    // Caso base: se a string for vazia ou tiver apenas um caractere, é um palíndromo
    if (n <= 1) {
        return true;
    }
    // Caso recursivo: se o primeiro e o último caracteres forem iguais,
    // chama a função recursivamente para o subvetor interno, excluindo os extremos
    else if (a[0] == a[n-1]) {
        return ehPalindromo(a+1, n-2);
    }
    // Se não forem iguais, não é um palíndromo
    else {
        return false;
    }
}


int main()
{
    int n;
    cout << "digite o valor de n: ";
    cin >> n;

    char *a = new char[n];

    for(int i = 0; i< n; i++)
    {
        cin >> a[i];
    }

    cout << ehPalindromo(a, n);

    delete [] a;
    return 0;

}

*/