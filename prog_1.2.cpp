#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

main()
{
    float value;
    float error;
    float inc;
    int step = 10;
    float error_1[step], error_2[step];
    srand((unsigned)time(0));

    for (int i = 0; i < 15; i++)
    {
        inc = rand() % 10 - 2.5;
        if (i == 0)
        {
            error_1[i] = inc;
            error_2[i] = inc;
        }
        else
        {
            error_1[i] = inc + error_1[i - 1];
            error_2[i] = inc;
        }
        cout << i << " " << error_1[i] << endl;
        cout << i << " " << error_2[i] << endl;
        cout << inc << endl;
    }
    cout << "enter value" << endl;
    cin >> value;
    for (int i = 0; i < 10000; i++)
    {
        error += sin(value);
    }
    cout << "accumulated error = " << error << endl;
    error = 10000 * sin(value);
    cout << "random error = " << error << endl;
}