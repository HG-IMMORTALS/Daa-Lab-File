#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, s, f;
    cin >> n;
    vector<int> start, finish;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        start.push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> f;
        finish.push_back(f);
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({finish[i], i});
    }
    sort(v.begin(), v.end());
    int count = 1, i = v[0].second;
    vector<int> ans;
    ans.push_back(i + 1);
    for (int j = 1; j < n; j++)
    {
        if (start[v[j].second] >= finish[i])
        {
            count++;
            ans.push_back(v[j].second + 1);
            i = v[j].second;
        }
    }
    cout << "No. of non-conflicting activities: " << count << endl;
    cout << "List of selected activities: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}