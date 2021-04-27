#include <bits/stdc++.h>

using namespace std;

int n;

complex<double> Det(vector<vector<complex<double>>> a)
{
    if (a.size() == 1)
        return a[0][0];

    int k = 0;
    while (a[k][0] == 0. + 0i)
        k++;
    if (k != 0)
    {
        for (unsigned int i = 0; i < a[k].size(); i++)
        {
            a[k][i] *= -1;
        }
        vector<complex<double>> tmp = a[k];
        a[k] = a[0];
        a[0] = tmp;
    }

    complex<double> firstElem = a[0][0];
    for (unsigned int i = 0; i < a.size(); i++)
    {
        a[i][0] /= firstElem;
    }
    for (unsigned int i = 1; i < a.size(); i++)
    {
        complex<double> k = a[0][i];
        for (unsigned int j = 0; j < a.size(); j++)
        {
            a[j][i] -= k * a[j][0];
        }
    }

    vector<vector<complex<double>>> b(a.size() - 1, vector<complex<double>>(a.size() - 1, 0. + 0i));
    for (unsigned int i = 1; i < a.size(); i++)
    {
        for (unsigned int j = 1; j < a.size(); j++)
        {
            b[i - 1][j - 1] = a[i][j];
        }
    }

    return firstElem * Det(b);
}

int main()
{
    cout << "Enter the size of matrix: ";
    cin >> n;
    vector<vector<complex<double>>> matrix(n, vector<complex<double>>(n));
    cout << "Read from file [y/n] ? ";
    char answer;
    cin >> answer;
    answer = tolower(answer);
    if (answer == 'y')
    {
        ifstream file;
        file.open("matrix.txt");
        cout << "\nEnter the elements:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                file >> matrix[i][j];
        file.close();
    }
    else if (answer == 'n')
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "A[" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
    }
    else
        cout << "error " << '\n';
    complex<double>
        det = Det(matrix);
    cout << "Determinant: " << det << '\n';
    return 0;
}
