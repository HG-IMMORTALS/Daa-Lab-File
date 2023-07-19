#include <iostream>
using namespace std;
int main()
{
    int t, n;
    cout << "Test cases : "; cin>>t; 
while (t != 0)
    {
        cout << "Size of array: ";
        cin >> n;
        int arr[n], temp, j, shift = 0, comp = 0;
        cout << "Elements: ";
        for (int i = 0;
             i < n; i++)
            cin >> arr[i];
        for (int i = 1; i < n; i++)
        {
            j = i - 1;
            temp = arr[i];
            while (j >= 0 && arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j--;
                shift++;
                comp++;
            }
            arr[j + 1] = temp;
            shift++;
        }
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\ncomparisons = " << comp << endl;
        cout << "shifts = " << shift << endl;
        t--;
    }
    return 0;
}
