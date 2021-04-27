#include <bits/stdc++.h>

using namespace std;

typedef vector<double> row;
typedef vector<row> matrix;
const double eps = 0.000001;

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
    matrix res = {};
    for (int j = 0; j < a.size(); j++)
    {
        row r = {};
        for (int k = 0; k < a[j].size(); k++)
        {
            r.push_back(a[j][k] + b[j][k]);
        }
        res.push_back(r);
    }
    return res;
}

matrix mul(matrix a, matrix b)
{
    matrix res = {};
    for (int j = 0; j < a.size(); j++)
    {
        row r = {};
        for (int k = 0; k < a[j].size(); k++)
        {
            double tmp = 0;
            for (int t = 0; t < a[j].size(); t++)
            {
                tmp += a[j][t] * b[t][k];
            }
            r.push_back(tmp);
        }
        res.push_back(r);
    }
    return res;
}

bool solved(matrix a, matrix x, matrix b)
{
    matrix res = mul(a, x);
    for (int i = 0; i < res.size(); i++)
    {
        if (abs(res[i][0] - b[i][0]) > eps)
            return false;
    }
    return true;
}

matrix scan(int rows, int cols)
{
    matrix res = {};
    for (int j = 0; j < rows; j++)
    {
        row r = {};
        for (int k = 0; k < cols; k++)
        {
            double tmp;
            cin >> tmp;
            r.push_back(tmp);
        }
        res.push_back(r);
    }
    return res;
}

int main()
{
    cout << "dimension: ";
    int dim;
    cin >> dim;
    cout << "coeffs:\n";
    matrix a = scan(dim, dim);
    cout << "b:\n";
    matrix b = scan(dim, 1);

    matrix alpha = {};
    for (int i = 0; i < dim; i++)
    {
        row r = {};
        for (int j = 0; j < dim; j++)
        {
            if (i == j)
                r.push_back(0);
            else
                r.push_back(-a[i][j] / a[i][i]);
        }
        alpha.push_back(r);
    }

    matrix beta = {};
    for (int i = 0; i < dim; i++)
    {
        row r = {b[i][0] / a[i][i]};
        beta.push_back(r);
    }

    matrix x0 = beta;
    int iterations = 0;
    while (!solved(a, x0, b))
    {
        matrix x1 = add(beta, mul(alpha, x0));
        x0 = x1;
        iterations++;
    }

    cout << "solved in " << iterations << " iterations\n";
    cout << "X =\n";
    print(x0);

    return 0;
}