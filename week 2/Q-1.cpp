#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, flag = 0;
    cin >> t;
    while (t != 0)
    {
        int n;
        cout <<"Enter the size of array: "; cin>>n; int arr[n], key; 
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        for (int i = 1; i < n; i++)
            if (arr[i] == arr[i - 1])
            {
                flag = 1;
                break;
            }
        if (flag == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
        t--;
    }
}