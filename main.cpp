#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{

    Matrix <float> a;
    Matrix <float> b;
    Matrix <float> c;

    a = Matrix<float>(3,3);
    b = Matrix<float>(3,3);
    c = Matrix<float>(3,3);

    a.rellenar2("123.txt");
    b.rellenar2("123.txt");

  //  c.mul(a,b);

  //  c.transpuesta(a);

    c = a*b;

    c.showMatrix();

    c.imprimir("respuesta.txt");

    return 0;
}

