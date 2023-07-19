#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str1, str2;
    cout << "Sequence1: ";
    cin >> str1;
    cout << "Sequence2: ";
    cin >> str2;
    int n = str1.size(), m = str2.size();
    int t[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }
    string str = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            str += str1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (t[i][j - 1] > t[i - 1][j])
                j--;
            else
                i--;
        }
    }
    reverse(str.begin(), str.end());
    cout << "Longest Common Subsequence: " << str << endl;
    cout << "Length = " << t[n][m] << endl;
}