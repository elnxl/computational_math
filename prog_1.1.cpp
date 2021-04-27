#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

main()
{
    int size;
    cout << "number of elements = ";
    cin >> size;
    float array[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        array[i] = (rand() % 10);
        cout << array[i] << endl;
    }
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    float average_arf = sum / size;
    cout << "average arithmetic value = " << average_arf << endl;
    float min = array[0], max = array[0];
    float delta;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }
    delta = (max - min) / 2;
    cout << "absolute error = " << delta << endl;
    float sigma;
    sigma = delta * abs(1 / average_arf);
    cout << "relative error = " << sigma << endl;
    float p;
    cout << "enter dimension = ";
    cin >> p;
    sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += pow(array[i], p);
    }
    float average_geo = pow(sum, (1.0 / p));
    cout << "average geometric value = " << average_geo << endl;
    return 0;
}