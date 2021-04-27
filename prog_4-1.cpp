#include <bits/stdc++.h>

using namespace std;

typedef vector<complex<double>> row;
typedef vector<row> matrix;

void print(matrix a)
{
    for (int j = 0; j < a.size(); j++)
    {
        cout << "[ ";
        for (int k = 0; k < a[j].size(); k++)
        {
            cout << a[j][k];
        }
        cout << " ]\n";
    }
}

matrix add(matrix a, matrix b)
{
    assert(a.size() == b.size());
    assert(a[0].size() == b[0].size());
    matrix res = {};
    int operations = 0;
    for (int j = 0; j < a.size(); j++)
    {
        row r = {};
        for (int k = 0; k < a[j].size(); k++)
        {
            r.push_back(a[j][k] + b[j][k]);
            operations++;
        }
        res.push_back(r);
    }
    cout << "add(matrix,matrix): " << operations << " operations\n";
    return res;
}

matrix sub(matrix a, matrix b)
{
    assert(a.size() == b.size());
    assert(a[0].size() == b[0].size());
    matrix res = {};
    int operations = 0;
    for (int j = 0; j < a.size(); j++)
    {
        row r = {};
        for (int k = 0; k < a[j].size(); k++)
        {
            r.push_back(a[j][k] - b[j][k]);
            operations++;
        }
        res.push_back(r);
    }
    cout << "sub(matrix,matrix): " << operations << " operations\n";
    return res;
}

matrix mul(matrix a, complex<double> b)
{
    matrix res = {};
    int operations = 0;
    for (int j = 0; j < a.size(); j++)
    {
        row r = {};
        for (int k = 0; k < a[j].size(); k++)
        {
            r.push_back(a[j][k] * b);
            operations++;
        }
        res.push_back(r);
    }
    cout << "mul(matrix,complex): " << operations << " operations\n";
    return res;
}

matrix mul(matrix a, matrix b)
{
    assert(a[0].size() == b.size());
    matrix res = {};
    int operations = 0;
    for (int j = 0; j < a.size(); j++)
    {
        row r = {};
        for (int k = 0; k < a[j].size(); k++)
        {
            complex<double> tmp = 0. + 0.i;
            for (int t = 0; t < a[j].size(); t++)
            {
                tmp += a[j][t] * b[t][k];
                operations++;
            }
            r.push_back(tmp);
        }
        res.push_back(r);
    }
    cout << "mul(matrix,matrix): " << operations << " operations\n";
    return res;
}

complex<double> scancomplex()
{
    double real, imag;
    cin >> real >> imag;
    return complex<double>(real, imag);
}

int main()
{
    matrix a = {};
    matrix b = {};
    int rowsA, colsA, rowsB, colsB;
    cout << "dim(A): ";
    cin >> rowsA >> colsA;
    cout << "dim(B): ";
    cin >> rowsB >> colsB;
    cout << "A:\n";
    for (int j = 0; j < rowsA; j++)
    {
        row r = {};
        for (int k = 0; k < colsA; k++)
            r.push_back(scancomplex());
        a.push_back(r);
    }
    cout << "B:\n";
    for (int j = 0; j < rowsB; j++)
    {
        row r = {};
        for (int k = 0; k < colsB; k++)
            r.push_back(scancomplex());
        b.push_back(r);
    }
    cout << "c: ";
    complex<double> c = scancomplex();
    cout << "A+B =\n";
    print(add(a, b));
    cout << "\nA-B =\n";
    print(sub(a, b));
    cout << "\nA*c =\n";
    print(mul(a, c));
    cout << "\nA*B =\n";
    print(mul(a, b));
}