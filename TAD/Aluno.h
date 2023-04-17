#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <string>


/*
TIPOS ABSTRADOS DE DADOS

CLASSES

Sera usado o conceito de classe para criar o TAD.
Uma classe em C++ e uma forma especial de definiçao de
domınios, adicionando-se a possibilidade de definir
componentes que sao funçoes (metodos.
As classes determinam quais sao os metodos e os domınios de um objeto.
Arquivo.h:
Sintaxe:
class nomeDaClasse
{
// ... corpo da classe ...
};


O corpo da classe e constituido por Variaveis e Funçoes;
Os membros (variaveis ou funçoes) de uma classe podem ser:
private: so podem ser acessados pelos membros da propria classe.
public: podem ser acessados em qualquer lugar (na propria classe ou, por exemplo, no programa principal)  ́ ́
A definiçao da classe Poligono deve ser feita no arquivo Poligono.h
Arquivo.cpp:
A classe passa a possuir apenas o prototipo do metodo.
Sintaxe:
NomeDaClasse::nomeDaFuncao(...)
{
// implementacao
C:\Users\Samsung\Downloads\labprog2_projeto_aula04\Aula04\Prova.h}

Construtor e Destrutor

Criaçao e acesso a objetos

Estatica

Circulo c(0,0,5);
float a1 = c.calcArea();
c.setRaio(6);
float a2 = c.calcArea();

Dinamica

Circulo * c = new Circulo(0,0,5);
float a1 = c->calcArea();
c->setRaio(6);
float a2 = c->calcArea();

Objeto da classe

Estudante obj();
obj.funcao();

Estudante * obj = new Estudante();
obj->funcao();

Passagem de argumentos por referˆencia.

void funcaoTeste(Aluno * e)
{
e->imprime();
}


*/



using namespace std;

class Aluno
{
    public:
        Aluno(string n, string m, int idd);
        ~Aluno();

        // operacoes
        void setNome(string n);
        string getNome();

        // exercicio 1
        void leNotas();
        double calculaMedia();

        // exercicio 2
        // implemente aqui
        void setIdade(int n);
        double getIdade();

        void setMat(string n);
        string getMat();

        // exercicio 5
        void freq();
        void relatorio();

    private:
        int idade;
        string nome, matricula;
        double notas[7];
        bool frequencia[7];



        // exercicio 4
        // implemente aqui
};

#endif // ALUNO_H
