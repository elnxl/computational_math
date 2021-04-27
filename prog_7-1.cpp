#include <bits/stdc++.h>

using namespace std;

struct Data
{
    double x;
    double y;
};

istream &operator>>(istream &in, Data &data)
{
    in >> data.x >> data.y;
    return in;
}

double u_cal(double u, int n)
{
    double temp = u;
    for (int i = 1; i < n; i++)
        temp *= (u - i);
    return temp;
}

double fact(int n)
{
    double f = 1.;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    size_t n = 0;
    cin >> n;
    vector<Data> f(n, Data{});
    for (int i = 0; i < n; ++i)
        cin >> f[i];
    //Таблица конечных разностей (вперёд)
    vector<vector<double>> y{n, vector<double>((const size_t)n, 0.)};
    for (int i = 0; i < n; i++)
        y[i][0] = f[i].y;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];

    double const x1 = 0;
    double const x2 = 5;
    double const dx = 0.125;

    cout.width(20);
    cout << "X";
    cout.width(20);
    cout << "Y" << endl;
    for (double x = x1; x <= x2; x += dx)
    {
        double sum = y[0][0];
        double u = (x - f[0].x) / (f[1].x - f[0].x);
        for (int i = 1; i < n; i++)
        {
            sum += (u_cal(u, i) * y[0][i]) / fact(i);
        }
        cout.width(20);
        cout.precision(14);
        cout << x;
        cout.width(20);
        cout.precision(14);
        cout << sum << endl;
    }

    return 0;
}