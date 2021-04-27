#include <bits/stdc++.h>

using namespace std;

double func(double x)
{
    return (2 * pow(x, 4) + pow(x, 3) + 2 * pow(x, 2) + 3 * x + 24);
}
double I(double a, double b, int n, double y)
{
    return ((b - a) / (2 * n) * y);
}
int main()
{
    int n;
    double a, b, y, dy, In;
    cout << "Enter the left and right integration boundaries" << '\n';
    cin >> a >> b;
    cout << "Enter the number of crushing segments" << '\n';
    cin >> n;
    if (n > 1)
    {
        dy = (b - a) / n;
        y += func(a) + func(b);
        for (int i = 1; i < n; i++)
        {
            y += 2 * (func(a + dy * i));
        }
        In = I(a, b, n, y);
        cout << In;
    }
    else
    {
        cout << "Wrong data";
    }
}