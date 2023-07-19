#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int m,int r,int &comp,int &inv) {
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for (int i=0;i<n1;i++)
        L[i]=arr[l+i];
    for (int j=0;j<n2;j++)
        R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while (i<n1&&j<n2) {
        comp++;
        if (L[i]<=R[j])
            arr[k++]=L[i++];
        else 
        {
            arr[k++]=R[j++];
            inv+=n1-i;
        }
    }
    while(i<n1)
        arr[k++]=L[i++];
    while(j<n2)
        arr[k++]=R[j++];
}

void mergeSort(int arr[],int l,int r,int &comp,int &inv) 
{
    if (l>=r)
        return;
    int m=l+(r-l)/2;
    mergeSort(arr,l,m,comp,inv);
    mergeSort(arr,m+1,r,comp,inv);
    merge(arr,l,m,r,comp,inv);
}

int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int comp=0,inv=0;
        mergeSort(arr,0,n-1,comp,inv);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<"\ncomparisons = "<<comp<< "\ninversions = "<<inv<<"\n";
    }
    return 0;
}