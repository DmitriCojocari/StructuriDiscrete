#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

double factorial(int n)
{
    double fact = 1.0;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int main()
{
    cout << "Proiect nr.3" << endl;
    cout << "Tema: Serii Taylor" << endl;
    cout << "Elaborat de Cojocari Dmitri" << endl;
    double x = 65, eps = 1e-9;
    int n = 10;
    //cout << "Value for degree : ";
    //cin >> x;
    x = (x * M_PI) / 180;
    //cout << "Input precission : ";
    //cin >> eps;
    //cout << "Number of terms : ";
    //cin >> n;

    int exponent, key, i;
    double res, numarator, numitor, t;
    do
    {
        cout << "\n1. Metoda directa";
        cout << "\n2. Metoda recurenta - precizia de calcul";
        cout << "\n3. Metoda recurenta - suma partiala";
        cout << "\n0. Exit";
        cout << "\n\n\tAlege (de la 0 la 3) : ";
        cin >> key;
        switch (key)
        {
        case 1:
            res = numarator = numitor = 0.0;
            for (int i = 0; i < n; i++)
            {
                exponent = 2 * i;
                numarator = pow(x, exponent);
                numitor = factorial(exponent);
                t = (numarator * pow(-1, i)) / numitor;
                res = res + t;
                cout << "Numarator: " << numarator << " Numitor: " << numitor << " T" << i << " = " << t << " S" << i << " = " << setprecision(16) << res << endl;
            }
            cout << "Cosinus computed with Taylor series (direct) = " << res << endl;
            break;
        case 2:
            double s, q;
            i = 0;
            s = t = 1.0;
            while (abs(t) > eps)
            {
                i++;
                q = -(x * x) / ((2 * i - 1) * (2 * i));
                t = t * q;
                s += t;
                cout << "T" << i << " = " << t << ". S" << i << " = " << setprecision(16) << s << endl;
            }
            cout << "Cosinus computed with recurrence formula after " << i << " steps = " << setw(16) << setprecision(16) << s << endl;
            cout << "Cosinus (standart function) = " << cos(x) << endl;
            cout << "Error = " << setprecision(3) << abs(s - cos(x)) << endl;
            break;
        case 3:
            s = t = 1.0;
            for (i = 1; i <= n; i++)
            {
                q = -(x * x) / ((2 * i - 1) * (2 * i));
                t = t * q;
                s += t;
                cout << "T" << i << " = " << t << ". S" << i << " = " << setprecision(16) << s << endl;
            }
            cout << "Cosinus computed with recurrence formula = " << setw(16) << setprecision(16) << s << endl;
            cout << "Cosinus (standart function) = " << cos(x) << endl;
            cout << "Error = " << setprecision(3) << abs(s - cos(x)) << endl;
            break;
        }
    } while (key);

    return 0;
}