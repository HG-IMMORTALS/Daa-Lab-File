#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(string &str, vector<string> &res, int freq[], string &s, int n)
{
    if (s.size() == n)
    {
        res.push_back(s);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (freq[i] == 0)
        {
            s += str[i];
            freq[i] = 1;
            solve(str, res, freq, s, n);
            freq[i] = 0;
            s.pop_back();
        }
    }
}
int main()
{
    string str;
    cin >> str;
    vector<string> res;
    string s = "";
    int n = str.size();
    int freq[n];
    memset(freq, 0, sizeof(freq));
    solve(str, res, freq, s, n);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}