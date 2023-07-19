#include<bits/stdc++.h>
using namespace std;
void count_sort(int arr[],int n){
    int maxi = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
    }
    // cout<<maxi<<endl;
    int temp[maxi];
    for(int i=0;i<=maxi;i++){
        temp[i] = 0;
    }
    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }
    int j=0;
    for(int i=0;i<=maxi;i++){
        while(temp[i]!=0){
            arr[j++] = i;
            temp[i]--;
        }
     }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
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
    count_sort(arr,n);
    int k;
    cout<<"enter the kth element index =" ;
    cin>>k;
    cout<<"kth smallest element = "<<arr[k-1]<<endl;
    cout<<"kth largest element = "<<arr[n-k];
    return 0;
}