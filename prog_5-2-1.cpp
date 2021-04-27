#include <bits/stdc++.h>

using namespace std;
struct Matrix
{
    int maxcount = 10000;
    int n;
    double **arrA;
    double *arrB;

    Matrix()
    {
        printf("dimension: ");
        scanf("%d", &n);
        arrB = new double[n];
        arrA = new double *[n];
        for (int i = 0; i < n; i++)
        {
            arrA[i] = new double[n];
            for (int j = 0; j < n; j++)
            {
                printf("a[%d,%d]: ", i , j);
                scanf("%lf", &arrA[i][j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("b[%d]: ", i);
            scanf("%lf", &arrB[i]);
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] arrA[i];
        }
        delete[] arrA, arrB;
    }

    void iterate()
    {
        double *curvars = new double[n];
        double *prevvars = new double[n]();
        int count = 0;
        do
        {
            for (int i = 0; i < n; i++)
            {
                curvars[i] = arrB[i];
                for (int j = 0; j < n; j++)
                {
                    if (i != j)
                    {
                        curvars[i] -= arrA[i][j] * prevvars[j];
                    }
                }
                curvars[i] /= arrA[i][i];
            }
            prevvars = curvars;
            count++;
        } while (count < maxcount);
        for (int i = 0; i < n; i++)
        {
            printf("x[%d] = %lf\n", i, prevvars[i]);
        }
        delete[] curvars, prevvars;
    }
};

int main()
{
    Matrix res;
    res.iterate();
    return 0;
}