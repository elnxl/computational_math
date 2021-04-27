#include <bits/stdc++.h>

using namespace std;

struct dat
{
    double y;
    double x;
};

int main()
{
    int n;
    vector<dat> arr;
    vector<dat> arr1;
    dat z;
    cout << "Enter the number of points" << endl;
    cin >> n;
    cout << "Enter your dots, separating y and x with spaces" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> z.y >> z.x;
        arr.push_back(z);
    }
    arr1 = arr;
    for (int i = 0; i < (n - 1); i++)
    {
        arr[i + 1].y = (arr[i + 1].y - arr[i].y) / (arr[i + 1].x - arr[i].x);
    }
    cout << "First derivative of right finite differences";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].y << " ";
    }
    cout << endl;
    for (int i = 0; i < (n - 1); i++)
    {
        arr[i + 1].y = (arr[i + 1].y - arr[i].y) / (arr[i + 1].x - arr[i].x);
    }
    cout << "Second derivative of right finite differences ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].y << " ";
    }
    cout << endl;
    for (int i = 0; i < (n - 1); i++)
    {
        arr[i + 1].y = (arr[i + 1].y - arr[i].y) / (arr[i + 1].x - arr[i].x);
    }
    cout << "Third derivative of right finite differences";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].y << " ";
    }
    cout << endl;

    for (int i = 1; i < n; i++)
    {
        arr[i].y = (arr[i].y - arr[i - 1].y) / (arr[i].x - arr[i - 1].x);
    }
    cout << "First derivative of left finite differences";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].y << " ";
    }
    cout << endl;
    for (int i = 1; i < n; i++)
    {
        arr[i].y = (arr[i].y - arr[i - 1].y) / (arr[i].x - arr[i - 1].x);
    }
    cout << "Second derivative of left finite differences ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].y << " ";
    }
    cout << endl;
    for (int i = 1; i < n; i++)
    {
        arr[i].y = (arr[i].y - arr[i - 1].y) / (arr[i].x - arr[i - 1].x);
    }
    cout << "Third derivative of left finite differences";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].y << " ";
    }
    cout << endl;
}