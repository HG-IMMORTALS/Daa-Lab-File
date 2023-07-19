#include <iostream>
using namespace std;
int main()
{
    int t, n;
    cout << "Test Cases : "; 
    cin>>t; 
while (t != 0)
    {
        cout << "Size of array: ";
        cin >> n;
        int arr[n], temp, j, k, swaps = 0, comp = 0;
        cout << "Elements: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n - 1; i++)
        {
            for (k = j = i; j < n - 1; j++)
            {
                if (arr[j] < arr[k])
                    k = j;
                comp++;
            }
            temp =
                arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
            swaps++;
        }
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\ncomparisons = "<<comp<<endl; cout<<" shifts ="<<swaps<<endl; t--; } return 0; 
    }