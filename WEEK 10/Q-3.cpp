#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 0, arr + n);
    if (((arr[0] == arr[n / 2]) || (arr[n / 2] == arr[n - 1])) && n % 2 != 0)
        cout << "Yes" << endl;
    else if (n % 2 == 0 && ((arr[0] == arr[n / 2]) || (arr[n / 2] == arr[n - 1] && arr[n / 2] == arr[n / 2 -
                                                                                                     1])))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    if (n % 2 != 0)
        cout << arr[n / 2] << endl;
    else
    {
        cout << (arr[(n - 1) / 2] + arr[n / 2]) / 2.0 << endl;
    }
    return 0;
}