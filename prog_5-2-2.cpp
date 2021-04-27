#include <bits/stdc++.h>

using namespace std;

struct Complex
{
    double a, b;
    Complex operator+(const Complex &c)
    {
        return {a + c.a, b + c.b};
    }

    Complex operator-(const Complex &c)
    {
        return {a - c.a, b - c.b};
    }

    Complex operator*(const Complex &c)
    {
        return {a * c.a - b * c.b, a * c.b + b * c.a};
    }

    Complex operator/(const Complex &c)
    {
        double t = c.a * c.a + c.b * c.b;
        return {(a * c.a + b * c.b) / t, (c.a * b - a * c.b) / t};
    }
};

typedef vector<vector<Complex>> complex_matrix;
const double EPS = 1E-9;

void input_complex_matrix(complex_matrix &arr, int n)
{
    double a, b;
    cout << "enter real and imagine parts" << endl;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cout << "enter row " << to_string(i) << endl;

        arr[i].resize(n);

        for (int j = 0; j < n; j++)
        {
            cin >> a;
            cin >> b;
            arr[i][j] = {a, b};
        }
    }
}

double abs(Complex x)
{
    return x.a * x.a + x.b * x.b;
}

vector<Complex> gauss_method(complex_matrix a, vector<Complex> b, int n)
{

    double max;
    int index;
    int k = 0;
    vector<Complex> x(n);

    while (k < n)
    {
        max = abs(a[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
            auto t = abs(a[i][k]);
            if (t > max)
            {
                max = t;
                index = i;
            }
        }

        if (max < EPS)
        {
            cout << "no solutions" << endl;
            return vector<Complex>(0, {0, 0});
        }

        for (int j = 0; j < n; j++)
        {
            auto temp = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = temp;
        }

        auto t = b[k];
        b[k] = b[index];
        b[index] = t;
        for (int i = k; i < n; i++)
        {
            t = a[i][k];
            if (abs(t) < EPS)
                continue;
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] / t;
            b[i] = b[i] / t;
            if (i == k)
                continue;
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
            b[i] = b[i] - b[k];
        }
        k++;
    }

    for (k = n - 1; k >= 0; k--)
    {
        x[k] = b[k];
        for (int i = 0; i < k; i++)
            b[i] = b[i] - a[i][k] * x[k];
    }
    return x;
}

int main()
{
    int n;
    cout << "enter n: " << endl;
    cin >> n;
    complex_matrix a;
    input_complex_matrix(a, n);
    vector<Complex> b;
    b.resize(n);
    cout << "enter b" << endl;

    double t1, t2;

    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        b[i] = {t1, t2};
    }

    vector<Complex> x = gauss_method(a, b, n);

    for (int i = 0; i < x.size(); i++)
        cout << "x" << to_string(i) << " = " << x[i].a << " + i(" << x[i].b << ")" << endl;
    return 0;
}