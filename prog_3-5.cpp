#include <bits/stdc++.h>
using namespace std;

string iter(double Function(double), double x, double p)
{
    int iterNumber = 0;
    double diff = 0;
    while (abs(Function(x) - x) > p)
    {
        iterNumber += 1;
        if ((iterNumber == 3) && (abs(diff) < abs(Function(x) - x)))
        {
            return "Method diverges.";
        }
        diff = Function(x) - x;
        x = Function(x);
    }
    return to_string(x) + "; total amount of iterations: " + to_string(iterNumber);
}

double f1(double x)
{
    return acos(0.1);
}

double f2(double x)
{
    return double(1000) - pow(x, 3);
}

double f3(double x)
{
    return pow(x, 5) - pow(x, 4) - pow(x, 2) - double(5);
}

double f4(double x)
{
    return pow(x, 3) - double(1);
}

double f5(double x)
{
    return 2.25 - log(x);
}

int main()
{
    double p;
    cout << "Enter precision: ";
    cin >> p;

    cout << "cos(x) = 0.01: " << iter(f1, 0.5, p) << endl;
    cout << "x^3 + x = 1000: " << iter(f2, 10, p) << endl;
    cout << "x^5 - x^4 - x^2 - x - 5 = 0: " << iter(f3, 2, p) << endl;
    cout << "x^3 - x - 1 = 0: " << iter(f4, 2, p) << endl;
    cout << "ln(x) + x = 2.25: " << iter(f5, 2, p) << endl;

    return 0;
}