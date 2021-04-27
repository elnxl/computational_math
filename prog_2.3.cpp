#include <iostream>
#include <cmath>

using namespace std;

double eq_1();
double func_1(double x);
double eq_2();
double func_2(double x);

int main()
{
    cout << "Choose the equation:" << endl;
    cout << "1) 5x^4-2x^3+3x^2+x-4=0" << endl;
    cout << "2) x^5-3x^4+7x^2+x-8=0" << endl;
    int x;
    cin >> x;
    if (x == 1)
        eq_1();
    else if (x == 2)
        eq_2();
    else
        cout << "error" << endl;
    return 0;
}

double eq_1()
{
    cout << "the roots are x_1=-0.789083 and x_2=0.820381" << endl;
    cout << "check the theorem" << endl;
    cout << "Enter l_1 and r_1 for first root" << endl;
    double l_1, r_1;
    cin >> l_1 >> r_1;
    double lf_1 = 0.0, rf_1 = 0.0;
    double x_1 = -0.789083;
    double eps;
    cout << "enter eps" << endl;
    cin >> eps;
    double n_1 = (fabs(l_1 + r_1) / 2);
    double step_1 = n_1 * eps / 100;
    cout << "first root:";
    for (double i = l_1; i <= n_1; i += step_1)
    {
        if (func_1(i) * func_1(r_1) < 0)
        {
            if (fabs(x_1 - i) <= eps)
                lf_1 = i;
            if (fabs(r_1 - x_1) <= eps)
                rf_1 = r_1;
        }
        r_1 -= step_1;
    }
    if (rf_1 < lf_1)
        cout << "[" << rf_1 << ";" << lf_1 << "]" << endl;
    else
        cout << "[" << lf_1 << ";" << rf_1 << "]" << endl;
    cout << "Enter l_2 and r_2 for second root" << endl;
    double l_2, r_2;
    cin >> l_2 >> r_2;
    double lf_2 = 0.0, rf_2 = 0.0;
    double x_2 = 0.820381;
    double n_2 = (fabs(l_2 + r_2) / 2);
    double step_2 = n_2 * eps / 100;
    cout << "second root:";
    for (double i = l_2; i <= n_2; i += step_2)
    {
        if (func_1(i) * func_1(r_2) < 0)
        {
            if (fabs(x_2 - i) <= eps)
                lf_2 = i;
            if (fabs(r_2 - x_2) <= eps)
                rf_2 = r_2;
        }
        r_2 -= step_2;
    }
    if (rf_2 < lf_2)
        cout << "[" << rf_2 << ";" << lf_2 << "]" << endl;
    else
        cout << "[" << lf_2 << ";" << rf_2 << "]" << endl;
}

double func_1(double x)
{
    return 5 * pow(x, 4) - 2 * pow(x, 3) + 3 * pow(x, 2) + x - 4;
}

double eq_2()
{
    cout << "the root x=1.26172" << endl;
    cout << "check the theorem" << endl;
    cout << "Enter l and r for root" << endl;
    double l, r;
    cin >> l >> r;
    double lf, rf;
    double x = 1.26172;
    double eps;
    cout << "enter eps" << endl;
    cin >> eps;
    double n = (fabs(l + r) / 2);
    double step = n * eps / 100;
    cout << "root:";
    for (double i = l; i <= n; i += step)
    {
        if (func_2(i) * func_2(r) < 0)
        {
            if (fabs(x - i) <= eps)
                lf = i;
            if (fabs(r - x) <= eps)
                rf = r;
        }
        r -= step;
    }
    if (rf < lf)
        cout << "[" << rf << ";" << lf << "]" << endl;
    else
        cout << "[" << lf << ";" << rf << "]" << endl;
}

double func_2(double x)
{
    return pow(x, 5) - 3 * pow(x, 4) + 7 * pow(x, 2) + x - 8;
}