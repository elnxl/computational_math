#include <bits/stdc++.h>

using namespace std;

bool DIA(double **a, int n)
{
    int k = 1;
    double sum;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
            sum += abs(a[i][j]);
        sum -= abs(a[i][i]);
        if (sum > abs(a[i][i]))
        {
            k = 0;
            cout << abs(a[i][i]) << "<" << sum << endl;
        }
        else
        {
            cout << abs(a[i][i]) << ">" << sum << endl;
        }
    }
    return (k == 1);
}

bool CNV(double *xk, double *xkp, int n, double e)
{
    double norm = 0;
    for (int i = 0; i < n; i++)
        norm += (xk[i] - xkp[i]) * (xk[i] - xkp[i]);
    return (sqrt(norm) < e);
}

double UKR(double x, double e)
{
    int i = 0;
    while (e != 1)
    {
        i++;
        e *= 10;
    }
    int UKR = pow(double(10), i);
    x = int(x * UKR + 0.5) / double(UKR);
    return x;
}

void GT(int n, double **a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "A[" << i << "][" << j << "] =";
            cin >> a[i][j];
        }
    }
}

void ST(int n, double **a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
            cout << endl;
        }
    }
}

void potato(int n, double *b)
{
    for (int i = 0; i < n; i++)
    {
        cout << "B[" << i + 1 << "] = ";
        cin >> b[i];
    }
    cout << endl;
}

void proverit(double **a, int n, double e, double *x)
{
    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j] * x[j];
            cout << a[i][j] << " * " << UKR(x[j], e);
            if (j < (n - 1))
                cout << " + ";
        }
        cout << " = " << sum << " +- " << e << endl;
    }
}

void PRB(int n, double **a, double *b, double *x, double *p, double e)
{
    int m = 0;
    for (int i = 0; i < n; i++)
        x[i] = 1;
    cout << "Diagonal prevalence " << endl;
    if (DIA(a, n))
    {
        do
        {
            for (int i = 0; i < n; i++)
                p[i] = x[i];
            for (int i = 0; i < n; i++)
            {
                double var = 0;
                for (int j = 0; j < i; j++)
                    var += (a[i][j] * x[j]);
                for (int j = i + 1; j < n; j++)
                    var += (a[i][j] * p[j]);
                x[i] = (b[i] - var) / a[i][i];
            }
            m++;
        } while (!CNV(x, p, n, e));
        cout << "System Solution: " << endl
             << endl;
        for (int i = 0; i < n; i++)
            cout << "Iterations " << m << endl;
        proverit(a, n, e, x);
    }
    else
    {
        cout << "Diagonals do not prevail " << endl;
    }
}

int main()
{
    double e;
    int n;
    cout << "Enter the size of your matrix ";
    cin >> n;
    cout << "Enter precision ";
    cin >> e;
    double **a;
    a = new double *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new double[n];
    }
    double *b = new double[n];
    double *x = new double[n];
    double *p = new double[n];
    cout << "Enter your matrix: " << endl
         << endl;
    GT(n, a);
    cout << "Your matrix: " << endl
         << endl;
    ST(n, a);
    cout << "Enter the column of free members: " << endl
         << endl;
    potato(n, b);
    PRB(n, a, b, x, p, e);
    return 0;
}