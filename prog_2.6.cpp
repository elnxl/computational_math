#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

double find(double x, double eps, int n);
double eq_1(double x);
double eq_1_df(double x);
double eq_2(double x);
double eq_2_df(double x);
double eq_3(double x);
double eq_3_df(double x);
double eq_4(double x);
double eq_4_df(double x);
double eq_5(double x);
double eq_5_df(double x);

int main()
{
    cout << "Choose the equation" << endl;
    cout << "1) 2*lg1(x)-cos(x)=0   x=(0;4pi]" << endl;
    cout << "2) 2*x^3-5*x^2-1=0" << endl;
    cout << "3) 2*sin^3(2*x)-cos(x)=0   x=[0;pi]" << endl;
    cout << "4) x^5-3*x^4+8*x^2+2*x-7=0" << endl;
    cout << "5) 0.5*x^2+5*cos(2*x)-2=0  x=[-pi;pi]" << endl;
    int x;
    cin >> x;
    cout << "Enter x_0" << endl;
    double x_0;
    cin >> x_0;
    cout << "Enter the eps" << endl;
    double eps;
    cin >> eps;
    switch (x)
    {
    case (1):
        cout << "x = " << find(x_0, eps, 1);
        break;
    case (2):
        cout << "x = " << find(x_0, eps, 2);
        break;
    case (3):
        cout << "x = " << find(x_0, eps, 3);
        break;
    case (4):
        cout << "x = " << find(x_0, eps, 4);
        break;
    case 5:
        cout << "x = " << find(x_0, eps, 5);
        break;
    default:
        cout << "mode error" << endl;
        break;
    }

    return 0;
}

double find(double x, double eps, int n)
{
    double f, df;
    int iter = 0;
    do
    {
        switch (n)
        {
        case (1):
            f = eq_1(x);
            df = eq_1_df(x);
            break;
        case (2):
            f = eq_2(x);
            df = eq_2_df(x);
            break;
        case (3):
            f = eq_3(x);
            df = eq_3_df(x);
            break;
        case (4):
            f = eq_4(x);
            df = eq_4_df(x);
            break;
        case (5):
            f = eq_5(x);
            df = eq_5_df(x);
            break;
        default:
            break;
        }
        x = x - f / df;
        iter++;
    } while (fabs(f) > eps && iter < 20000);
    if (fabs(f) > eps)
        cout << "Not this segment" << endl;
    else
        return x;
}

double eq_1(double x)
{
    return 2 * log10(x) - cos(x);
}

double eq_1_df(double x)
{
    return 2 / (x * log(10)) + sin(x);
}

double eq_2(double x)
{
    return 2 * pow(x, 3) - 5 * pow(x, 2) - 1;
}

double eq_2_df(double x)
{
    return 6 * pow(x, 2) - 10 * x;
}

double eq_3(double x)
{
    return 2 * pow(sin(2 * x), 3) - cos(x);
}
double eq_3_df(double x)
{
    return sin(x) + 12 * pow(sin(2 * x), 2) * cos(2 * x);
}

double eq_4(double x)
{
    return pow(x, 5) - 3 * pow(x, 4) + 8 * pow(x, 2) + 2 * x - 7;
}

double eq_4_df(double x)
{
    return 5 * pow(x, 4) - 12 * pow(x, 3) + 16 * x + 2;
}

double eq_5(double x)
{
    return 0.5 * pow(x, 2) + 5 * cos(2 * x) - 2;
}

double eq_5_df(double x)
{
    return x - 10 * sin(2 * x);
}