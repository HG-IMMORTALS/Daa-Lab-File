#include <iostream>
using namespace std;
int main()
{
    int t;
    cout <<"Enter the number of test cases:"; cin>>t; while(t != 0) 
    {
        int n, key = -1, i;
        cout <<"Enter the size of array:"; cin>>n; int arr[n]; 
            cout
             << "Enter the elements: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << "Enter the key: ";
        cin >> key;
        for (i = 0; i < n; i++)
        {
            if (key == arr[i])
            {
                cout << "Element found!" << endl;
                break;
            }
        }
        if (i == n)
        {
            cout << "Element not found!" << endl;
            cout << "Total number of comparison: " << i << endl;
        }
        else
        {
            cout<<"Total number of comparison : "<<i+1<< endl;
        }
        t--;
    }
    return 0;
}