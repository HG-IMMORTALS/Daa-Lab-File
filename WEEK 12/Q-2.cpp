#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, w, p;
    cin >> n;
    vector<int> wgt;
    vector<int> price;
    for (int i = 0; i < n; i++)
    {
        cin >> w;
        wgt.push_back(w);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        price.push_back(p);
    }
    cin >> w;
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    vector<int> v1, v2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wgt[i - 1] <= j)
            {
                dp[i][j] = max(price[i - 1] + dp[i - 1][j - wgt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int res = dp[n][w];
    for (int i = n; i > 0 && res > 0; i--)
    {
        if (res == dp[i - 1][w])
            continue;
        else
        {
            v1.push_back(i - 1);
            res = res - price[i - 1];
            w = w - wgt[i - 1];
        }
    }
    cout << "Value = " << dp[n][w] << endl;
    cout << "Weights selected : ";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << wgt[v1[i]] << " ";
    }
    cout << endl
         << "Weights selected : ";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << price[v1[i]] << " ";
    }
    return 0;
}