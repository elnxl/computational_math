#include <bits/stdc++.h>

using namespace std;

int factorial(int i)
{
    if (i == 0)
        return 1;
    else
        return i * factorial(i - 1);
}

int proizv(int *a, int *b, int n)
{
    int *c = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
        c[i] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; ++j)
        {
            c[i + j] += a[i] * b[j];
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        a[i] = c[i];
    }
    return *a;
}

float q_zn1(float q, int *mas, int n)
{
    float temp = q;
    int *mnoj = new int[2];
    mnoj[1] = 1;
    mnoj[0] = (1 - n);
    proizv(mas, mnoj, n); //произведение

    int *pr = new int[n]; //производная
    for (int i = 0; i < n; i++)
    {
        pr[i] = mas[i + 1] * (i + 1);
    }
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pr[i] * pow(temp, i);
    }
    return sum;
}
float q_zn2(float q, int *mas, int n)
{
    float temp = q;
    int *mnoj = new int[2];
    mnoj[1] = 1;
    mnoj[0] = (n - 1);
    proizv(mas, mnoj, n); //произведение
    int *pr = new int[n]; //производная
    for (int i = 0; i < n; i++)
    {
        pr[i] = mas[i + 1] * (i + 1);
    }
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pr[i] * pow(temp, i);
    }
    return sum;
}

int newton()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите число точек:";
    cin >> n;
    float *x = new float[n];
    float **y = new float *[n];
    cout << "Массив точек х:";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    cout << "Массив точек y:";
    for (int i = 0; i < n; i++)
    {
        y[i] = new float[n];
        cin >> y[i][0];
    }
    cout << '\n'
         << "Введите число, для которого вычислить значение:";
    float h;
    h = x[1] - x[0];
    float zn; //наше значение
    cin >> zn;
    int flag = 1;
    cout << "formula 1 or 2:";
    cin >> flag;
    float sum;
    if (flag == 1)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
                y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
        sum = y[0][1];
        float q = (zn - x[0]) / h;
        int *mas = new int[n + 1]; //mas itog
        mas[0] = 0;
        mas[1] = 1;
        for (int i = 2; i < n; i++)
        {
            sum = sum + (q_zn1(q, mas, i) * y[0][i]) / factorial(i);
        }
    }
    else if (flag == 2)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = n - 1; j >= i; j--)
                y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
        sum = y[n - 1][1];
        float q = (zn - x[n - 1]) / h;
        int *mas = new int[n + 1]; //mas itog
        mas[0] = 0;
        mas[1] = 1;
        for (int i = 2; i < n; i++)
        {
            sum += (q_zn2(q, mas, i) * y[n - 1][i]) / factorial(i);
        }
    }
    else
    {
        cout << "\nОшибочка";
        return 0;
    }
    cout << "\nДля точки: " << zn << " значение производной это: " << sum / h << endl;
    system("pause");
    return 0;
}