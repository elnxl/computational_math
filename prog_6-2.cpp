#include <bits/stdc++.h>

using namespace std;

vector<double> operator-(vector<double> l, vector<double> r)
{
    vector<double> otvet;
    for (int i = 0; i < l.size(); i++)
    {
        otvet.push_back(l[i] - r[i]);
    }
    return otvet;
}

vector<double> operator+(vector<double> l, vector<double> r)
{
    vector<double> otvet;
    for (int i = 0; i < l.size(); i++)
    {
        otvet.push_back(l[i] + r[i]);
    }
    return otvet;
}

double operator*(vector<double> l, vector<double> r)
{
    double otvet;
    for (int i = 0; i < l.size(); i++)
    {
        otvet += l[i] * r[i];
    }
    return otvet;
}

vector<double> operator*(double l, vector<double> r)
{
    vector<double> otvet;
    for (int i = 0; i < r.size(); i++)
    {
        otvet.push_back(l * r[i]);
    }
    return otvet;
}

vector<double> proj(vector<double> a, vector<double> b)
{
    double a1 = a * b;
    double a2 = a * b;
    return (a1 / a2) * b;
}

int main()
{
    vector<vector<double>> matrix;
    int N;
    double input;
    cout << "Enter the number of rows of matrix A" << endl;
    cin >> N;
    cout << "Enter the matrix through the space, completing the entry with the Enter button" << endl;
    for (int i = 0; i < N; i++)
    {
        vector<double> f;
        for (int j = 0; j < N; j++)
        {
            cin >> input;
            f.push_back(input);
        }
        matrix.push_back(f);
    }
    vector<vector<double>> otvet;
    for (auto &a : matrix)
    {
        vector<double> f = a;
        for (auto &b : otvet)
        {
            f = f - proj(a, b);
        }
        otvet.push_back((1.0 / sqrt(f * f)) * f);
    }
    cout << "Result " << endl;
    for (auto &i : otvet)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}