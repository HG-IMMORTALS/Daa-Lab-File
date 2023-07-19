#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int s, int e)
{
 
    int pivot = arr[s];
    int c = 0;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot)
            c++;
    }
    int pivotIndex = s + c;
    swap(arr[pivotIndex], arr[s]);
    int i = s, j = e;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot)j--;
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}
int main()
{
    int n;
    cout<<"enter the size of array = ";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for(auto i:arr) cout<<i<<" ";
    return 0;
}
