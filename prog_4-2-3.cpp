#include <bits/stdc++.h>

using namespace std;

void colswap(double **arr, int N, int c1, int c2)
{
    for (int i = 0; i < N; i++)
    {
        double tmp = arr[i][c1];
        arr[i][c1] = arr[i][c2];
        arr[i][c2] = tmp;
    }
}

void rowswap(double **arr, int N, int r1, int r2)
{
    for (int j = 0; j < N; j++)
    {
        double tmp = arr[r1][j];
        arr[r1][j] = arr[r2][j];
        arr[r2][j] = tmp;
    }
}

int main()
{
    int N, i, j;
    int k = 0;
    int swapcount = 0;
    bool broken = true;
    cout << "Enter the size of matrix: ";
    cin >> N;
    double **arr = new double *[N];
    double det = 1;
    for (i = 0; i < N; i++)
    {
        arr[i] = new double[N];
        for (j = 0; j < N; j++)
        {
            printf("a[%d,%d]: ", i,j);
            scanf("%lf", &(arr[i][j]));
        }
    }
    while (k < N * N && broken)
    {
        broken = false;
        for (i = 0; i < N; i++)
        {
            if (arr[i][i] == 0)
            {
                if (k / N % 2 == 0)
                {
                    colswap(arr, N, k % N, i);
                }
                else
                {
                    rowswap(arr, N, k % N, i);
                }
                if (k % N != i)
                    swapcount++;
                k++;
                broken = true;
                break;
            }
        }
    }
    if (k = N * N && broken)
    {
        printf("determinant: 0\n");
        return 0;
    }
    if (swapcount % 2 == 1)
    {
        det *= -1;
    }
    for (i = 0; i < N; i++)
    {
        for (k = i + 1; k < N; k++)
        {
            for (j = N - 1; j >= i; j--)
            {
                arr[j][k] = arr[j][k] - arr[j][i] / arr[i][i] * arr[i][k];
            }
        }
        det *= arr[i][i];
    }
    printf("determinant: %lf\n", det);
    for (i = 0; i < N; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}