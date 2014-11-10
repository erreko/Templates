#ifndef MATRIX_H
#define MATRIX_H

#include<fstream>

using namespace std;

template<class T>
class Matrix
{
private:
       int r;
       int c;
       T **m;

public:
Matrix()
{
    m = NULL;
    r =0;
    c =0;
}

Matrix(int r ,int c)
{
    this->r = r;
    this->c = c;

    m = new T*[this->r];
    for (int i =0; i< this->r ; i++)
    {
        m[i] = new T[this->c];

    }

    for (int i =0; i< this->r ; i++)
       {
        for (int j=0; j < this->c ; j++)
            {
                 m[i][j] = 0;

            }
       }
}

void showMatrix()
    {
      for(int i=0;i<r;i++)
      {
          for(int j=0;j<c;j++)
          {
               cout << m[i][j] << " " ;
          }
       cout << endl;
      }

    }

int getR() const
{
    return r;
}

void setR(const int &value)
{
    r = value;
}

int getC() const
{
    return c;
}

void setC(const int &value)
{
    c = value;
}

void suma(Matrix a, Matrix b)
{

    for(int i =0;i<r; i++)
    {
        for(int j=0;j<c;j++)
        {
            m[i][j] = a.m[i][j] + b.m[i][j];
        }
    }
}

void resta(Matrix a, Matrix b)
{
    for(int i =0;i<r; i++)
    {
        for(int j=0;j<c;j++)
        {
            m[i][j] = a.m[i][j] - b.m[i][j];
        }
    }
}

void escalar(int a)
{
    for(int i =0;i<r; i++)
    {
        for(int j=0;j<c;j++)
        {
            m[i][j] *= a;
        }
    }
}

void transpuesta(Matrix a)
{
    for(int i =0;i<c; i++)
    {
        for(int j=0;j<r;j++)
        {
            m[j][i]= a.m[i][j];
        }
    }

}

void mul(Matrix a, Matrix b)
{
    int **d;
    d = new T*[r];
    for(int i=0;i<r;i++)
    {
        d[i]= new int[c];
    }

    for(int i =0;i<r; i++)
    {
        for(int j=0;j<c;j++)
        {
            for(int k=0;k<c;k++)
            {
               m[i][j]= m[i][j] + a.m[i][k]*b.m[k][j];
            }
        }
    }
}

void rellenar()
{
    float z =1.5;
    for(int i =0;i<r; i++)
    {
        for(int j=0;j<c;j++)
        {
           // cin >> m[i][j];
            m[i][j] = z ;
            z++;
        }
    }

}

Matrix &operator +(const Matrix &valor)
 {
    Matrix *c = new Matrix(valor.r, valor.c);

        for(int i = 0; i<c->r; i++)
        {
            for(int j = 0; j<c->c; j++)
            {
                c->m[i][j] = this->m[i][j] + valor.m[i][j];
            }
        }

        return *c;
 }

Matrix &operator -(const Matrix &valor)
 {
    Matrix *c = new Matrix(valor.r, valor.c);

        for(int i = 0; i<c->r; i++)
        {
            for(int j = 0; j<c->c; j++)
            {
                c->m[i][j] = this->m[i][j] - valor.m[i][j];
            }
        }

        return *c;
 }

Matrix &operator *(const Matrix &valor)
{
    Matrix *c = new Matrix(valor.r, valor.c);

        for (int i = 0; i < this->r; i++)
        {
            for (int j = 0; j < this->c; j++)
            {
                c->m[i][j]=0;
                for (int k = 0; k < this->c; k++)
                {
                    c->m[i][j]=c->m[i][j] + (this->m[i][k]*valor.m[k][j]);
                }
            }
        }
        return *c;
}

/*
ostream& operator <<(ostream &os, const Matrix &valor)
{
    for(int i = 0; i<valor.r; i++)
    {
        for(int j = 0; j<valor.c; j++)
        {
            os<<valor.m[i][j]<<" ";
        }
        os<<"\n";
    }
    return os;
}
*/

void rellenar2(string ca)
{
    int i = 0;
    int j = 0;
    ifstream file;
    file.open(ca.c_str());
    if(file.is_open())
    {
        file >> this->r;
        file >> this->c;

              this->m = new T* [r];

              for(i=0;i<this->r;i++)
              {
                  this->m[i]= new T [c];
              }

              for(i = 0;i<this->r;i++)
              {
                  for(j = 0;j<this->c;j++)
                  {
                      file >> this->m[i][j];

                  }
              }

     file.close();

    }

}

void imprimir(string c)
{
    int i = 0;
    int j = 0;
    ofstream file;
    file.open(c.c_str());
    if(file.is_open())
    {
        file << this->r << " "<< this->c<<endl;


              for(i = 0;i<this->r;i++)
              {
                  for(j = 0;j<this->c;j++)
                  {
                      file << this->m[i][j] << " ";

                  }

                  file << endl;
              }

      file.close();
    }

}


};


#endif // MATRIX_H
