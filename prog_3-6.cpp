#include <bits/stdc++.h>
using namespace std;

const double eps = 0.000001;
const double e = exp(1);

complex<double> fz1(complex<double> z)
{
    return 4.0 * pow(z, 4) + 2.0 * pow(z, 2) + 1.3;
}
complex<double> dfz1(complex<double> z)
{
    return 16.0 * pow(z, 3) + 4.0 * z;
}

complex<double> fz2(complex<double> z)
{
    return pow(z, 2) + 2.71;
}
complex<double> dfz2(complex<double> z)
{
    return 2.0 * z;
}

complex<double> fz3(complex<double> z)
{
    return 2.0 * exp(z) + sqrt(2.0);
}
complex<double> dfz3(complex<double> z)
{
    return 2.0 * exp(z);
}

complex<double> solve(
    complex<double> fz(complex<double>),
    complex<double> dfz(complex<double>),
    complex<double> z0)
{
    complex<double> z1 = z0 - fz(z0) / dfz(z0);
    int iterations = 0;
    while (abs(z1.real() - z0.real()) > eps || abs(z1.imag() - z0.imag()) > eps)
    {
        iterations++;
        z0 = z1;
        z1 = z0 - fz(z0) / dfz(z0);
    }
    cout << "solve(): " << iterations << " iterations" << endl;
    return z1;
}

int main()
{
    complex<double> z0 = 1.0 + 1.0i;
    cout << solve(fz1, dfz1, z0) << endl;
    cout << solve(fz2, dfz2, z0) << endl;
    cout << solve(fz3, dfz3, z0) << endl;
    return 0;
}