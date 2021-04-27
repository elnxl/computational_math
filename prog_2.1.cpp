#include <iostream>

using namespace std;

int main()
{
    int n, e, i;
    cout << "Enter maximum power of polynom ";
    cin >> n;
    int a[n + 1];
    int b[n + 1];
    bool check = 1;
    for (i = n; i >= 0; --i)
    {
        cout << "Enter a[" << i << "]: ";
        cin >> a[i];
    }
    cout << "Enter free term of dividing equation ";
    cin >> e;
    b[n] = a[n];
    cout << "Equation : " << b[n] << "x^" << n - 1;
    for (i = n - 1; i > 0; i--)
    {
        b[i] = a[i] + e * b[i + 1];
        if (b[i] != 0)
        {
            if (b[i] >= 0)
                cout << "+";
            if (b[i] == 1)
                cout << "x^" << i - 1;
            else if (b[i] == -1)
                cout << "-x^" << i - 1;
            else if (b[i] != 0)
                cout << b[i] << "x^" << i - 1;
        }
    }
    b[0] = a[0] + e * b[1];
    cout << endl
         << "Surplus: " << b[0] << endl
         << "Check: ";
    for (i = n - 1; i >= 0; i--)
        if (b[i] - e * b[i + 1] != a[i])
            check = 0;
    if (check)
        cout << "OK" << endl;
    else
        cout << "Error" << endl;
    return 0;
}