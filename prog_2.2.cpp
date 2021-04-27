#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

void logarithm(double eps);
void harmony(double eps);
long fact(int i);

int main()
{
    cout << "Choose the mode" << endl
         << "1 - Logarithm function" << endl
         << "2 - Harmonic function" << endl;
    int mode;
    cin >> mode;
    cout << "Enter eps" << endl;
    double eps;
    cin >> eps;
    if (mode == 1)
    {
        logarithm(eps);
    }
    else if (mode == 2)
    {
        harmony(eps);
    }
    else
        cout << "mode error";
    return 0;
}

void logarithm(double eps)
{
    cout << "Format is ln(ax+b)" << endl;
    cout << "Enter the value of b" << endl;
    double b;
    cin >> b;
    cout << "Enter the value of a" << endl;
    double a;
    cin >> a;
    cout << "Enter the value of x" << endl;
    double x;
    cin >> x;
    if (a == 0 || b == 0 || x == 0)
        cout << "Error" << endl;
    else if (((a / b) * x <= -1) || ((a / b) * x > 1))
        cout << "Summa error";
    else
    {
        cout << "Enter the number of elements" << endl;
        int number;
        cin >> number;
        double sum_l = log(b);
        for (int i = 1; i <= number; ++i)
        {
            if (a > 0)
                sum_l += pow((-1), (i - 1)) * pow((a / b) * x, i) / i;
            else if (a < 0)
                sum_l += pow((-1), i) * pow((a / b) * x, i) / i;
        }
        cout << sum_l << endl;
        cout << "Difference :" << fabs(log(a * x + b) - sum_l) << endl;
        if (fabs(log(a * x + b) - sum_l) <= eps)
            cout << "Accuracy is OK" << endl;
        else
            cout << "Not accurate" << endl;
    }
}

void harmony(double eps)
{
    cout << "Format is sin(x)" << endl;
    cout << "Enter the value of x" << endl;
    double x;
    cin >> x;
    cout << "Enter the number of elements" << endl;
    int number;
    cin >> number;
    double sum_h = 0.0;
    for (int i = 1; i <= number; ++i)
    {
        sum_h += ((pow((-1), i + 1) * pow(x, 2 * i - 1)) / fact(2 * i - 1));
    }
    cout << sum_h << endl;
    cout << "Difference :" << fabs(sin(M_PI * x / 180) - sum_h) << endl;
    if (fabs(sin(M_PI * x / 180) - sum_h) <= eps)
        cout << "Accuracy is OK" << endl;
    else
        cout << "Not accurate" << endl;
}

long fact(int i)
{
    if (i < 0)
        return 0;
    if (i == 0)
        return 1;
    else
        return i * fact(i - 1);
}