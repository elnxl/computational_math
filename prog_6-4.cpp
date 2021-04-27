#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true)
    {
        cout << "Enter N: ";
        int n;
        cin >> n;
        int m = pow(2, n);
        const double pi = M_PI;
        const double e = M_E;
        vector<vector<complex<double>>> a(m, vector<complex<double>>(m));

        for (int k = 0; k < m; k++)
        { //filling up the matrix
            for (int j = 0; j < m; j++)
            {
                a[k][j] = (1 / sqrt(m)) * ((cos((2 * pi * k * j) / m)) - 1i * sin((2 * pi * k * j) / m));
            }
        }

        //creating conjugated matrix
        vector<vector<complex<double>>> con(m, vector<complex<double>>(m));
        for (int k = 0; k < m; k++)
        {
            for (int j = 0; j < m; j++)
            {
                con[k][j] = conj(a[j][k]);
            }
        }

        //multiplying them and making sure it's unitary
        vector<vector<complex<double>>> prod(m, vector<complex<double>>(m, 0));
        bool unitary = true;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    prod[i][j] += a[i][k] * con[k][j];
                }
                if ((i == j) && (!(prod[i][j] == 1. + 0i)))
                    unitary = false;
                else if ((!(i == j)) && (prod[i][j] != 0. + 0i))
                    unitary = false;
            }
        }

        //output
        cout << "Unitary Fourier transform matrix: " << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        if (unitary)
            cout << "Matrix is unitary." << endl;
        else
            cout << "Matrix is not unitary." << endl;

        cout << "Do you want to exit? If yes, press 1: ";
        int st;
        cin >> st;
        if (st == 1)
            break;
    }
    return 0;
}