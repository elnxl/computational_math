#include <bits/stdc++.h>

using namespace std;

double det(int n, double **matrix);
void Kramer(int n, double **matrix, double *free_var, double *answer);

int main()
{
    int n;
    cout << "Enter a number of variables ";
    cin >> n;
    double **matrix;
    matrix = new double *[n];
    double *free_var;
    free_var = new double[n];
    double *answer = new double[n];

    for (int i = 0; i < n; i++)
        matrix[i] = new double[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cout << "A[" << i << "][" << j << "]=";
            cin >> matrix[i][j];
        }

    cout << "Please enter free variables" << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << "B[" << i << "]=";
        cin >> free_var[i];
    }

    Kramer(n, matrix, free_var, answer);

    delete[] matrix;
    delete[] free_var;
    delete[] answer;
    return 0;
}

double det(int n, double **matrix)
{
    double d = 0;
    int c, subi, i, j, subj;
    double **submat;
    submat = new double *[n];
    for (int i = 0; i < n; i++)
        submat[i] = new double[n];
    if (n < 1)
    {
        cout << "error size" << endl;
        return 0;
    }
    else if (n == 1)
        d = matrix[0][0];
    if (n == 2)
    {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    }
    else
    {
        for (c = 0; c < n; c++)
        {
            subi = 0;
            for (i = 1; i < n; i++)
            {
                subj = 0;
                for (j = 0; j < n; j++)
                {
                    if (j == c)
                    {
                        continue;
                    }
                    submat[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            d = d + (pow(-1, c) * matrix[0][c] * det(n - 1, submat));
        }
    }
    delete[] submat;
    return d;
}

void Kramer(int n, double **matrix, double *free_var, double *answer)
{
    double *detArray = new double[n];
    double deterMain;
    double *temp = new double[n];
    cout << "Finding determinant of main matrix" << endl;
    cout << "deterMain = ";
    deterMain = det(n, matrix);
    cout << deterMain << endl;
    if (deterMain == 0)
        cout << "error in matrix" << '\n';
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp[j] = matrix[i][j];
                matrix[i][j] = free_var[j];
            }
            detArray[i] = det(n, matrix);
            cout << "determinant_" << i << " = " << detArray[i] << '\n';
            for (int k = 0; k < n; k++)
            {
                matrix[i][k] = temp[k];
            }
        }

        for (int i = 0; i < n; i++)
        {
            answer[i] = detArray[i] / deterMain;
            cout << "X_" << i << " = " << answer[i] << endl;
        }
        delete[] detArray;
        delete[] temp;
    }
}