#include<bits/stdc++.h>
using namespace std;
void duplicate(int arr[],int n){
    sort(arr,arr+n);
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            cout<<"True";
            return ;
        }
    }
    cout<<"False";
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
    duplicate(arr,n);
    return 0;
}