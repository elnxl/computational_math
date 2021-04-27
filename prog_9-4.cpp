#include <bits/stdc++.h>

using namespace std;

double f(double x)
{
    return (2 * pow(x, 4) + pow(x, 3) + 2 * pow(x, 2) + 3 * x + 24);
}

int main()
{
    double a, b, eps; //Нижний и верхний пределы интегрирования (a, b), погрешность (eps).
    cout << "Enter the left and right integration boundaries" << '\n';
    cin >> a >> b;
    cout << "Enter the eps \n";
    cin >> eps;
    double I = eps + 1, I1 = 0; //I-предыдущее вычисленное значение интеграла, I1-новое, с большим N.
    for (int N = 2; (N <= 4) || (fabs(I1 - I) > eps); N *= 2)
    {
        double h, sum2 = 0, sum4 = 0, sum = 0;
        h = (b - a) / (2 * N); //Шаг интегрирования.
        for (int i = 1; i <= 2 * N - 1; i += 2)
        {
            sum4 += f(a + h * i);       //Значения с нечётными индексами, которые нужно умножить на 4.
            sum2 += f(a + h * (i + 1)); //Значения с чётными индексами, которые нужно умножить на 2.
        }
        sum = f(a) + 4 * sum4 + 2 * sum2 - f(b); //Отнимаем значение f(b) так как ранее прибавили его дважды.
        I = I1;
        I1 = (h / 3) * sum;
    }
    cout << I1 << endl;
    return 0;
}