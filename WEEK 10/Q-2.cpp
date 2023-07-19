#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, num;
    cin >> n;
    vector<int> task;
    vector<int> finish;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        task.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        finish.push_back(num);
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({finish[i], i});
    }
    sort(v.begin(), v.end());
    int i = 0;
    vector<int> res;
    res.push_back(v[i].second + 1);
    int temp = task[v[i].second];
    for (i = 1; i < n; i++)
    {
        if (finish[v[i].second] - temp >= task[v[i].second])
        {
            res.push_back(v[i].second + 1);
            temp += task[v[i].second];
        }
    }
    cout << "Max number of tasks =" << res.size() << endl;
    cout << "Selected task numbers :";
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}