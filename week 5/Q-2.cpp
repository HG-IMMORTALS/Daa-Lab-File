#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n,key;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) 
        {
            cin>>arr[i];
        }
        cin>>key;
        sort(arr,arr+n);
        int i=0,j=n-1;
        bool found=false;
        while(i<j) 
        {
            if(arr[i]+arr[j]==key)
            {
                cout<<arr[i]<<" "<<arr[j]<<endl;
                found=true;
                break;
            }
            else if(arr[i]+arr[j]>key)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        if (!found)
        {
            cout<<"No Such Element Exist"<<endl;
        }
    }
    return 0;
}