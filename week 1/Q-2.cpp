#include <iostream>
using namespace std;
int binary_search(int arr[], int l, int r, int key)
{
    if (r < l)
        return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[mid] > key)
        return binary_search(arr, l, mid - 1, key);
    return binary_search(arr, mid + 1, r, key);
}
int countFrequency(int arr[], int n, int key)
{
    int pos = binary_search(arr, 0, n - 1, key);
    if (pos == -1)
        return -1;
    int count = 1;
    int left = pos - 1, right = pos + 1;
    while (left >= 0 && arr[left] == key)
    {
        count++;
        left--;
    }
    while (right < n && arr[right] == key)
    {
        count++;
        right++;
    }
    return count;
}
int main()
{
    int n, key;
    int t;
    cout <<"\nEnter no. of times:"; cin>>t; while(t != 0) 
    {
        cout << "\nEnter the size of array: ";
        cin >> n;
        int a[n];
        cout <<"\nEnter the elements of array:"; 
        for(int i=0 ; i<n ; i++) cin>>a[i]; 
            cout<< "\nEnter the key element: ";
        cin >> key;
        cout << key << " " << countFrequency(a, n, key);
        t--;
    }
    return 0;
}