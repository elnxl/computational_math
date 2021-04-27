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
    cout << "1) 2x^3+x^2-7=0" << endl;
    cout << "2) 5cos(3x)+0.5x=2   x=[0;2pi]" << endl;
    cout << "3) x^5-2x^4+6x^2+2x-4=0" << endl;
    cout << "4) x^3-0.2x^2-0.2x-1.2=0" << endl;
    cout << "5) ln(|x^3|+1)+x^3=2" << endl;
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
    return 2 * pow(x, 3) + pow(x, 2) - 7;
}

double eq_2(double x)
{
    return 5 * cos(3 * x) + 0.5 * x - 2;
}

double eq_3(double x)
{
    return pow(x, 5) - 2 * pow(x, 4) + 6 * pow(x, 2) + 2 * x - 4;
}

double eq_4(double x)
{
    return pow(x, 3) - 0.2 * pow(x, 2) - 0.2 * x - 1.2;
}

double eq_5(double x)
{
    return log(fabs(pow(x, 3)) + 1) + pow(x, 3) - 2;
}

double find(double x0, double x1, double eps, int n)
{
    double left = x0, right = x1, x, fl, fr, f;
    int iter = 0;
    do
    {
        x = (left + right) / 2;
        switch (n)
        {
        case (1):
            f = eq_1(x);
            break;
        case (2):
            f = eq_2(x);
            break;
        case (3):
            f = eq_3(x);
            break;
        case (4):
            f = eq_4(x);
        case (5):
            f = eq_5(x);
            break;
        default:
            break;
        }
        if (f > 0)
            right = x;
        else
            left = x;
        iter++;
    } while (fabs(f) > eps && iter < 20000);
    if (fabs(f) > eps)
        cout << "Not this segment" << endl;
    else
        return x;
}