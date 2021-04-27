#include <bits/stdc++.h>

using namespace std;

double d = 0;
double det(int n, double mat[10][10])
{
    double submat[10][10];
    if (n == 2)
        return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
    for (int c = 0; c < n; c++)
    {
        int subi = 0;
        for (int i = 1; i < n; i++)
        {
            int subj = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == c)
                    continue;
                submat[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        d += (pow(-1, c) * mat[0][c] * det(n - 1, submat));
    }
    return d;
}

int main(int argc, char **argv)
{
    double mat[10][10];
    cout << "Enter the size of matrix:\n";
    int n;
    cin >> n;
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
                file >> mat[j][i];
        file.close();
    }
    else if (answer == 'n')
    {
        cout << "Enter the elements:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[j][i];
    }
    else
    {
        cout << "Error\n";
        return 1;
    }
    cout << "Determinant = " << det(n, mat) << "\n";
    return 0;
}