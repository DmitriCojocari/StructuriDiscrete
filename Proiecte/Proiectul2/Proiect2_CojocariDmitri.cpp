#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

unsigned long long Factorial(unsigned);
unsigned long long Permutari(unsigned);
unsigned long long Aranjamente(unsigned, unsigned);
unsigned long long Combinari(unsigned, unsigned);
unsigned long long Power(unsigned, unsigned);
unsigned long long PowerRec(unsigned, unsigned);
unsigned long long PermutariCuRepetitii(unsigned);
unsigned long long AranjamenteCuRepetitii(unsigned, unsigned);
unsigned long long CombinariCuRepetitii(unsigned, unsigned);
unsigned long long PermutariCuRepetitii2(unsigned, unsigned[]);

int main()
{
    cout << "Proiect nr.2" << endl;
    cout << "Tema: Elemente de combinatorica" << endl;
    cout << "Elaborat de Cojocari Dmitri" << endl;
    unsigned a[10] = {1, 3, 2, 0, 0};
    char sir[100] = "Pr(", Sir[100];
    unsigned n = 6, k = 2, m;
    cout << "Numarul total de elemente al multimii: ";
    cin >> n;
    do
    {
        cout << "Numarul de elemente al grupului (cate elemente luam in grup): ";
        cin >> k;
    } while (k > n || k < 0);
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    cout << "Introduceti " << n << " elemente: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        a[m - 1]++;
    }
    cout << n << "^" << k << " = " << PowerRec(n, k) << endl;
    cout << n << "! = " << Factorial(n) << endl;
    cout << "P(" << n << ")"
         << " = " << Permutari(n) << endl;
    cout << "A(" << n << "," << k << ")"
         << " = " << Aranjamente(n, k) << endl;
    cout << "C(" << n << "," << k << ")"
         << " = " << Combinari(n, k) << endl;
    cout << "Pr(" << n << ")"
         << " = " << PermutariCuRepetitii(n) << endl;
    cout << "Ar(" << n << ")"
         << " = " << AranjamenteCuRepetitii(n, k) << endl;
    cout << "Cr(" << n << ")"
         << " = " << CombinariCuRepetitii(n, k) << endl;
    int d = 0;
    while (a[d] == 0)
    {
        d++;
    }
    sprintf(Sir, "%s%u", sir, a[d]);
    strcpy(sir, Sir);
    for (int i = d + 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            sprintf(Sir, "%s%c%u", sir, ',', a[i]);
        }
        strcpy(sir, Sir);
    }
    m = strlen(sir);
    strcpy(&sir[1], &sir[m]);
    //sir[strlen(sir) - 1] = '\0';
    cout << Sir << ") = " << PermutariCuRepetitii2(n, a);
    return 0;
}

unsigned long long Factorial(unsigned m)
{
    unsigned long long f = 1;
    for (int i = 2; i <= m; i++)
    {
        f *= i;
    }
    return f;
}

unsigned long long Permutari(unsigned n)
{
    return Factorial(n);
}

unsigned long long Aranjamente(unsigned n, unsigned k)
{
    return (Factorial(n) / Factorial(n - k));
}

unsigned long long Combinari(unsigned n, unsigned k)
{
    return (Factorial(n) / (Factorial(k) * Factorial(n - k)));
}

unsigned long long Power(unsigned n, unsigned k)
{
    unsigned long long p = 1;
    for (int i = 1; i <= k; i++)
    {
        p = p * n;
    }
    return p;
}

unsigned long long PowerRec(unsigned n, unsigned k)
{
    unsigned long long p = 1;
    if (k <= 0)
        return 1;
    return (PowerRec(n, k - 1) * n);
}

unsigned long long PermutariCuRepetitii(unsigned n)
{
    return Power(n, n);
}

unsigned long long AranjamenteCuRepetitii(unsigned n, unsigned k)
{
    return Power(n, k);
}

unsigned long long CombinariCuRepetitii(unsigned n, unsigned k)
{
    return (Factorial(n + k - 1) / (Factorial(k) * Factorial(n - 1)));
}

unsigned long long PermutariCuRepetitii2(unsigned size, unsigned a[])
{
    // Exemplu: avem 3 cifre de 2, 2 cifre de 3, 1 cifra de 1. Ce numere putem alcatui?
    // 222331
    // 122233, 122323, 122332, 123223 ...
    // P2(2,3,1) = (2+3+1)! / (2!*3!*1!)
    unsigned long long p = 1;
    unsigned s = 0;
    for (int i = 0; i < size; i++)
    {
        s += a[i];
        p *= Factorial(a[i]);
    }
    return Factorial(s) / p;
}
