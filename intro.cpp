#include <iostream>
#include <string>

using namespace std;

/*1. Fac ̧a um programa que leia do teclado um numero inteiro  ́
n e em seguida leia n numeros reais e calcule a sua m  ́ edia.  ́

int main()
{
    int n;
    cin >> n;
    float soma =0;
    for(int i =0; i< n; i++)
    { int num;
        cin >> num;
        soma = soma + num;
    }

    float media = soma/n;
    cout << media;
}
́*/
/*
2. Implemente agora o exerc ́ıcio (1) utilizando uma func ̧ao ̃
que possua o seguinte prototipo:  ́
float leCalculaMedia(int n);

float leCalculaMedia(int n){

    float soma =0;
    for(int i =0; i< n; i++)
    { int num;
        cin >> num;
        soma = soma + num;
    }

    float media = soma/n;
    cout << media;

}

int main()
{
    int n;
    cin >>n;
    leCalculaMedia(n);

}
*/


/*
3. Fac ̧a uma func ̧ao que receba como par  ̃ ametros um vetor de ˆ
numeros reais e o seu tamanho  ́ n e que leia do teclado n
numeros reais, guarde-os no vetor e calcule a sua m  ́ edia. A  ́
func ̧ao deve retornar a m  ̃ edia ao final.  ́
float leVetorCalculaMedia(int n, float vet[]);

float leVetorCalculaMedia(int n, float vet[])
{
    float soma= 0;

    for(int i = 0; i< n; i++)
    {
        cin >> vet[i];
        soma = soma + vet[i];
    }

    cout << soma/n;
}

int main()
{
    int n;

    cin >> n;

    float vet[n];

    leVetorCalculaMedia(n, vet);
}
*/

/*4. Fac ̧a uma func ̧ao que, dados uma string  ̃ str e um
caractere ch, procure e retorne a posic ̧ao da primeira  ̃
ocorrencia de ˆ ch na string str. Se ch nao for encontrada  ̃
em str, retornar o valor −1.
int procuraCharNaString(string str, char ch);
Dica: para saber o tamanho da string use str.size().

int procuraCharNaString(string str, char ch){

    int tam = str.size();

    for(int i = 0; i< tam; i++)
    {
        if(str[i] == ch){
            return i;
        }
    }
    return -1;

}

int main()
{
    string str = "bolinha";

    char ch = 'a';

    cout << procuraCharNaString(str, ch);


}
*/

/*
Fac ̧a uma func ̧ao que receba um n  ̃ umero inteiro  ́ n > 0 e
determine se este e um n  ́ umero primo. A func ̧  ́ ao deve  ̃
retornar um valor booleano: true ou false. Prototipo:  ́
bool ehPrimo(int n);

bool ehPrimo(int n){

    for(int i = 2; i < n; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main()
{
    int x;
    cout << "digite um numero inteiro maior que 0: ";
    cin >> x;

    cout << ehPrimo(x);

    return 0;
}*/

/*7. Fac ̧a uma func ̧ao para calcular o fatorial de um n  ̃ umero  ́
inteiro n > 0. Fac ̧a um programa que leia um numero  ́
inteiro do teclado, em seguida utilize a func ̧ao para  ̃
calcular o seu fatorial e, por fim, exiba o resultado na tela.
int fatorial(int n);*/

int fatorial(int n){

    int fat = 1;
    for (int i = 1; i <= n; i++)
    {
        fat = fat * i;
    }
    return fat;
}

int main()
{
    cout << "digite um numero inteiro maior que 0: ";
    int x;
    cin >> x;

    cout << fatorial(x);

}