#include <stdio.h>
#include <conio.h>
#include <mem.h>
int a[20][20], d[20], i, j, k, n, x, y, min, imin;
char c[20], varf[20];
char local[20][20] = {"Dmitri", "Balti", "Orhei", "Sangerei", "Rascani", "Ungheni", "Chisinau", "Soroca", "Falesti", "Glodeni", "Drochia"};
int main()
{
    printf("Lucrare nr.4");
    printf("\nTema: Algoritmul lui Dijkstra");
    printf("\nElaborat de Cojocari Dmitri");
    //citirea din fisier
    FILE *f;
    f = fopen("dijkstra.in", "r");
    if (f == NULL)
    {
        printf("Eroare la deschidere");
        return -1;
    }
    //citim numarul de noduri
    fscanf(f, "%d", &n);
    //citim matricea de costuri
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            fscanf(f, "%d", &a[i][j]);
    //citim nodul sursa
    fscanf(f, "%d", &x);
    memset(d, 0, sizeof(d));
    memset(varf, 0, sizeof(varf));
    for (i = 1; i <= n; i++)
    {
        c[i] = 1;
        if (a[x][i])
            varf[i] = x;
    }
    //nodul curent se seteaza cu 0
    c[x] = 0;
    for (i = 1; i <= n; i++)
        if (c[i])
            d[i] = a[x][i];
    for (y = 1; y <= n; y++)
        if (x != y)
        {
            for (k = 1; k <= n - 2; k++)
            {
                min = 10000;
                for (i = 1; i <= n; i++)
                    if (c[i] && d[i] > 0 && d[i] < min)
                    {
                        min = d[i];
                        imin = i;
                    }
                if (imin == y)
                    break;
                c[imin] = 0;
                for (i = 1; i <= n; i++)
                    if (c[i] && d[imin] != 0 && a[imin][i] != 0)
                        if (d[i] == 0 || d[i] > d[imin] + a[imin][i])
                        {
                            d[i] = d[imin] + a[imin][i];
                            varf[i] = imin;
                        }
            }
            printf("\nDistanta minima intre %s si %s este: %d \n", local[x], local[y], d[y]);
            c[i = 0] = y;
            while (varf[i] != x && varf[c[i]])
                c[++i] = varf[c[i - 1]];
            if (c[i] != x)
                c[++i] = x;
            for (; i >= 0;)
                printf("%s ", local[c[i--]]);
        }
    getch();
    return 0;
}