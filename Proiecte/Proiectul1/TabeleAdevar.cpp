#include <iostream>
#include <stdio.h>

using namespace std;

void LinieTabel(int nr_col, char left, char lin, char mid, char right);
void Negatie();
void Disjunctie();
void Conjunctie();
void Diferenta();
void DiferentaSimetrica();
void NOR();
void NAND();

int main()
{
    cout << "Proiect nr.1, elaborat de Cojocari Dmitri" << endl;
    cout << "Tema: Tabelul justetei" << endl;

    Negatie();
    Disjunctie();
    Conjunctie();
    Diferenta();
    DiferentaSimetrica();
    NOR();

    return 0;
}

void LinieTabel(int nr_col, char left, char lin, char mid, char right)
{
    int i, j;
    printf("\n%c", left);
    for (j = 1; j < nr_col; j++)
    {
        for (i = 1; i <= 3; i++)
            printf("%c", lin);
        printf("%c", mid);
    }
    for (i = 1; i <= 9; i++)
        printf("%c", lin);
    printf("%c", right);
}
void Negatie()
{
    cout << "\n\tNegatia (complementara):" << endl;
    LinieTabel(2, 201, 205, 209, 187);
    printf("\n%c a %c%c not a %2c", 186, 179, 32, 186);
    LinieTabel(2, 199, 196, 197, 182);
    for (int a = 0; a <= 1; a++)
    {
        printf("\n%c %d %c %4d %4c", 186, a, 179, !a, 186);
    }
    LinieTabel(2, 200, 205, 207, 188);
}

void Disjunctie()
{
    cout << "\n\tDisjunctia (adunarea):\n";
    LinieTabel(3, 201, 205, 209, 187);
    printf("\n%c a %c b %c a or b %2c", 186, 179, 179, 186);
    LinieTabel(3, 199, 196, 197, 182);
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
        {
            printf("\n%c %d %c %d %c %4d %4c", 186, a, 179, b, 179, a || b, 186);
        }
    LinieTabel(3, 200, 205, 207, 188);
}

void Conjunctie()
{
    cout << "\n\tConjunctia (inmultirea):\n";
    LinieTabel(3, 201, 205, 209, 187);
    printf("\n%c a %c b %c a and b%c%c", 186, 179, 179, 32, 186);
    LinieTabel(3, 199, 196, 197, 182);
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
        {
            printf("\n%c %d %c %d %c %4d %4c", 186, a, 179, b, 179, a && b, 186);
        }
    LinieTabel(3, 200, 205, 207, 188);
}

void Diferenta()
{
    cout << "\n\tDiferenta :\n";
    LinieTabel(3, 201, 205, 209, 187);
    printf("\n%c a %c b %c  a - b%c%2c", 186, 179, 179, 32, 186);
    LinieTabel(3, 199, 196, 197, 182);
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
        {
            printf("\n%c %d %c %d %c %4d %4c", 186, a, 179, b, 179, a && !b, 186);
        }
    LinieTabel(3, 200, 205, 207, 188);
}

void DiferentaSimetrica()
{
    cout << "\n\tXor (diferenta simetrica):\n";
    LinieTabel(3, 201, 205, 209, 187);
    printf("\n%c a %c b %c a xor b%c%c", 186, 179, 179, 32, 186);
    LinieTabel(3, 199, 196, 197, 182);
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
        {
            printf("\n%c %d %c %d %c %4d %4c", 186, a, 179, b, 179, a ^ b, 186);
        }
    LinieTabel(3, 200, 205, 207, 188);
}

void NOR()
{

    cout << "\n\tNOR (negatia disjunctiei):\n";
    LinieTabel(3, 201, 205, 209, 187);
    printf("\n%c a %c b %c a nor b%c%c", 186, 179, 179, 32, 186);
    LinieTabel(3, 199, 196, 197, 182);
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
        {
            printf("\n%c %d %c %d %c %4d %4c", 186, a, 179, b, 179, !(a || b), 186);
        }
    LinieTabel(3, 200, 205, 207, 188);
}