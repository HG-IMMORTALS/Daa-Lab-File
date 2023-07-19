#include <iostream>
using namespace std;
void js(int arr[], int n, int key)
{
    int i = 0;
    int j = 2;
    int
        comp = 0;
    while (arr[j] <= key && j < n)
    {
        comp++;
        i = j;
        j = j + 2;
        if (j > n-1)
        {
            j = n;
        }
    }
    for (int k = i; k < j; k++)
    {
        int count = 0;
        count++;
        if (arr[k] == key)
        {
            cout << "Key is present !\n"<< (comp + count) << endl;
        }
        else
        {
            cout << "Key is not present !\n"<< (comp + count) << endl;
            break;
        }
    }
}
int main()
{
    int t, n, arr[100], key;
    cout <<"Enter test cases:"; cin>>t; 
    while(t--) 
    {
        cout << "\nEnter the no. of element in the array: ";
        cin >> n;
        cout << "\nEnter the elements in the array: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout <<"Enter the value which you want to search:"; cin>>key; 
        js(arr,n,key); 
    }
    return 0;
}