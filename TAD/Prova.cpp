#include "Prova.h"

Prova::Prova(int nq)
{
    cout << "Criando uma prova" << endl;
    n = nq;
    notasQuestoes = new double [n];

}

Prova::~Prova()
{
    delete [] notasQuestoes;
    cout << "Destruindo objeto aluno" << endl;
}


void Prova::leNotas2()

{
    for(int i = 0; i<n; i++)
    {
        cout << "Nota questao " << i+1 << ": ";
        cin >> notasQuestoes[i];
    }
}

void Prova::calculaNotaFinal()
{
    double soma = 0;
    for(int i = 0; i<n; i++)
    {
       soma = soma + notasQuestoes[i];
    }

    double menor = 0;
    for(int i = 0; i<n; i++)
    {
       if(menor < notasQuestoes[i])
       {
           menor = notasQuestoes[i];
       }
    }

     notaFinal = soma - menor;

}

double Prova::obtemNotaFinal()
{
    return notaFinal;
}

