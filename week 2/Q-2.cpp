#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t !=
           0)
    {
        int n, key, flag = 0;
        cout << "Enter the size of array : "; cin>>n; 
                                int a[n];
        cout << "Enter the elements of array: "; 
        for(int i=0 ; i<n ; i++) 
                cin >> a[i];
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (a[i] + a[j] == a[k])
                    {
                        flag++;
                        cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
                    }
                }
            }
        }
        if (flag == 0)
            cout << "No sequence found."; 
            t--; 
            
    } 
    return 0; 
}