#include <iostream>
#include "Aluno.h"
#include "Prova.h"

using namespace std;

int main()
{
    cout << "LABORATORIO DE PROGRAMACAO II - AULA 04\n" << endl;

    // ------------------------------------------------------------------------
    // EXERCICIO 1
    // ------------------------------------------------------------------------
    /*Aluno a("Carlos", "201566123AB", 20);

    cout << "Nome: " <<  a.getNome() << endl;
    cout << "Matricula: " << a.getMat() << endl;
    cout << "Idade: " << a.getIdade() <<endl;


    // leitura das notas do aluno
    a.leNotas();
    double m = a.calculaMedia();
    a.freq();
    a.relatorio();


    cout << "Media do aluno: " << m << endl;
*/


    //Prova p(3);

    Prova p(3);

    p.leNotas2();

    cout << "Obter nota final: " << p.obtemNotaFinal() << endl;


    return 0;
}
