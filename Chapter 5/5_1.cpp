#include <stdio.h>
#include <iostream>

class Matrice
{
public:
    int n, m;
    int M[100][100];

public:
    Matrice() {}
    Matrice(int n, int m) : n(n), m(m)
    {
    }
    void citire()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                std::cin >> this->M[i][j];
    }
    void afisare()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                std::cout << this->M[i][j] << " ";
            std::cout << "\n";
        }
    }
    Matrice operator+(const Matrice &m)
    {
        Matrice C = Matrice(m.n, m.m);
        for (int i = 0; i < m.n; i++)
            for (int j = 0; j < m.m; j++)
                C.M[i][j] = this->M[i][j] + m.M[i][j];
        return C;
    }
    Matrice operator-(const Matrice &m)
    {
        Matrice C = Matrice(m.n, m.m);
        for (int i = 0; i < m.n; i++)
            for (int j = 0; j < m.m; j++)
                C.M[i][j] = this->M[i][j] - m.M[i][j];
        return C;
    }

    Matrice operator*(const Matrice &m)
    {
        Matrice C = Matrice(this->n, m.m);

        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < m.m; j++)
            {
                C.M[i][j] = 0;
                for (int k = 0; k < m.n; k++)
                {
                    C.M[i][j] += this->M[i][k] * m.M[k][j];
                }
            }
        }
        return C;
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    Matrice A = Matrice(n, m);
    A.citire();
    std::cin >> n >> m;
    Matrice B = Matrice(n, m);
    B.citire();
    std::cin >> n;
    if (n == 1)
        (A + B).afisare();
    if (n == 2)
        (A - B).afisare();
    if (n == 3)
        (A * B).afisare();
    return 0;
}