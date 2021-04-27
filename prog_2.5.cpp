#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

double eq_1(double x);
double eq_2(double x);
double eq_3(double x);
double eq_4(double x);
double eq_5(double x);
double find(double x0, double x1, double eps, int n);

int main()
{
    cout << "Choose the equation" << endl;
    cout << "1) 5^x*sqrt(8^(x-1))-189=0" << endl;
    cout << "2) x^3-x^2+2x-5=0" << endl;
    cout << "3) 2*lg*x^2-5*lg^2(x)-4=0" << endl;
    cout << "4) 2*sin(2x)-cos(3x)=0.5   x=[0;2pi]" << endl;
    cout << "5) 2*x^3-7*x^2-7*x-2.5=0" << endl;
    int x;
    cin >> x;
    cout << "Enter x_0 and x_1" << endl;
    double x_0, x_1;
    cin >> x_0 >> x_1;
    cout << "Enter the eps" << endl;
    double eps;
    cin >> eps;
    switch (x)
    {
    case (1):
        cout << "x = " << find(x_0, x_1, eps, 1);
        break;
    case (2):
        cout << "x = " << find(x_0, x_1, eps, 2);
        break;
    case (3):
        cout << "x = " << find(x_0, x_1, eps, 3);
        break;
    case (4):
        cout << "x = " << find(x_0, x_1, eps, 4);
        break;
    case (5):
        cout << "x = " << find(x_0, x_1, eps, 5);
        break;
    default:
        cout << "mode error" << endl;
        break;
    }
    return 0;
}

double eq_1(double x)
{
    return pow(5, x) * sqrt(pow(8, (x - 1))) - 189;
}

double eq_2(double x)
{
    return pow(x, 3) - pow(x, 2) + 2 * x - 5;
}

double eq_3(double x)
{
    return 2 * log10(pow(x, 2)) - 5 * pow(log10(x), 2) - 4;
}

double eq_4(double x)
{
    return 2 * sin(2 * x) - cos(3 * x) - 0.5;
}

double eq_5(double x)
{
    return 2 * pow(x, 3) - 7 * pow(x, 2) - 7 * x - 2.5;
}

double find(double x0, double x1, double eps, int n)
{
    double rez = x1, f0, f;
    int iter = 0;
    do
    {
        switch (n)
        {
        case (1):
            f = eq_1(rez);
            f0 = eq_1(x0);
            break;
        case (2):
            f = eq_2(rez);
            f0 = eq_2(x0);
            break;
        case (3):
            f = eq_3(rez);
            f0 = eq_3(x0);
            break;
        case (4):
            f = eq_4(rez);
            f0 = eq_4(x0);
            break;
        case (5):
            f = eq_5(rez);
            f0 = eq_5(x0);
            break;
        default:
            break;
        }
        rez = rez - f / (f - f0) * (rez - x0);
        iter++;
    } while (fabs(f) > eps && iter < 20000);
    if (fabs(f) > eps)
        cout << "Not this segment" << endl;
    else
        return rez;
}