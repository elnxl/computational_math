#include <bits/stdc++.h>

using namespace std;

int N;

double CR(int N, double M[10][10])
{
    double a;
    double sM[10][10];
    if (N == 2)
    {
        return ((M[0][0] * M[1][1]) - (M[1][0] * M[0][1]));
    }
    else
    {
        for (int k = 0; k < N; k++)
        {
            int subi = 0;
            for (int i = 1; i < N; i++)
            {
                int subj = 0;
                for (int j = 0; j < N; j++)
                {
                    if (j == k)
                        continue;
                    sM[subi][subj] = M[i][j];
                    subj++;
                }
                subi++;
            }
            a = (pow(-1, k) * M[0][k] * CR(N - 1, sM));
            cout << a << " ";
        }
        return 0;
    }
}

double SC(double M[10][10])
{
    double rez;
    for (int j = 0; j < N; j++)
    {
        int p = 1;
        for (int i = 0; i < N; i++)
            p *= M[i][j];
        rez += p;
    }
    return rez;
}

int main()
{
    double M[10][10];
    cout << "What is the dimension of your space?" << endl;
    cin >> N;
    cout << "Want to read data from a file? Yes or No? " << endl;
    char ans;
    cin >> ans;
    cout << endl;
    ans = tolower(ans);
    if (ans == 'y')
    {
        ifstream F;
        F.open("input.txt");
        for (int j = 0; j < N; j++)
            M[0][j] = 0;
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                F >> M[i][j];
            }
        }
        F.close();
    }
    else if (ans == 'n')
    {
        cout << "Enter Vectors " << endl;
        for (int j = 0; j < N; j++)
            M[0][j] = 0;
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> M[i][j];
            }
        }
    }
    else
        cout << "error" << '\n';
    cout << endl
         << "Scalar product of vectors = " << SC(M) << endl;
    cout << "Vector product of vectors = " << CR(N, M) << endl;
    return 0;
}