#include "Aluno.h"

Aluno::Aluno(string n, string m, int idd)
{
    cout << "Criando aluno" << endl;
    nome = n;
    matricula = m;
    idade = idd;
}

Aluno::~Aluno()
{
    cout << "Destruindo objeto aluno" << endl;
}

void Aluno::leNotas()
{

    for(int i=0; i<7; i++)
    {
        cout << "Nota " << i+1 << ": ";
        cin >> notas[i];
    }
}

double Aluno::calculaMedia()
{
    double media = 0;
    for(int i = 0;i<7;i++)
    {
        media= media + notas[1];
    }
    return media/7;
}

// ----------------------------------------------------------------------------

void Aluno::setNome(string novo)
{
    nome = novo;
}

string Aluno::getNome()
{
    return nome;
}

// ----------------------------------------------------------------------------
// Exercicio 2
// ----------------------------------------------------------------------------

void Aluno::setIdade(int novaidd)
{
    idade = novaidd;
}

double Aluno::getIdade()
{
    return idade;
}

void Aluno::setMat (string novaMat)
{
    matricula = novaMat;
}

string Aluno::getMat()
{
    return matricula;
}

void Aluno::freq()
{

    for(int i = 0; i<7; i++)
    {
        cout << "Frequencia dia " << i+1 << ": ";
        cin >> frequencia[i];
    }

}

void Aluno::relatorio()
{
    cout << "------ Relatório ------" << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "Idade: " << getIdade() << endl;
    cout << "Matricula: " << getMat() << endl;


    int freq = 0;

    for(int i = 0; i<7; i++)
    {
        cout << "Disciplina " << 1+i << endl;
        cout << "Foi Frequente? ";
        if(frequencia[i] == 1)
        {
            cout << "Sim" << endl;

        }else{

            cout << "Não" << endl;
        }

        cout << "Foi Aprovado? ";
        if(notas[i] >= 60)
        {
            cout << "Sim" << endl;

        }else{

            cout << "Não" << endl;
        }

    }

}

