#include <iostream>
#include "MatrizLin.h"

using namespace std;

// . = ->
bool simetrica(MatrizLin mat)
{
    if(mat.getNl() == mat.getNc())
    {
        for(int i = 0; i < mat.getNl() ; i++)
        {
            for(int j = 0; j < mat.getNc(); j++)
            {
                if(mat.get(i,j) != mat.get(j,i))
                {
                    return false;
                }

            }
        }
        return true;
    }

    return false;
}

float* prodMatVetor(MatrizLin mat, float *v)
{
    float *vet= new float[mat.getNl()+mat.getNc()];

    for(int i = 0; i < mat.getNl(); i++)
    {
        for(int j = 0; j < mat.getNc(); j++)
        {

            float soma = mat.get(i,j) * mat.getNl();
            vet[mat.getNl()*mat.getNc()+1] = soma;
        }
    }

    return vet;
}
int main()
{
    int m = 3, n = 3;
    MatrizLin mat(m, n);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            float val = j + n*i; /// sequencia numerica no intervalo 0..(m*n-1)
            mat.set(i, j, val);
        }


    mat.imprime();
    cout << "A funçao é simetrica? " << simetrica(mat);
    cout << "O maior valor é? " << mat.maiorvalor();

    MatrizLin*  transposta = mat.transposta();
    transposta-> imprime();

    float v[3] = {1,2,3};


    cout << v[3];



    return 0;
}
