#include <bits/stdc++.h>

using namespace std;

double func(double x)
{
    return (2 * pow(x, 4) + pow(x, 3) + 2 * pow(x, 2) + 3 * x + 24);
}

int main()
{
    double a, b;
    int n;
    cout << "Enter the left and right integration boundaries" << '\n';
    cin >> a >> b;
    cout << "Enter the number of crushing segments" << '\n';
    cin >> n;
    double s = (func(a) + func(b)) / 2;
    double h = (b - a) / n;
    for (int i = 1; i <= n - 1; i++)
    {
        s += func(a + i * h);
    }
    double I = h * s;
    cout << I << endl;
    return 0;
}