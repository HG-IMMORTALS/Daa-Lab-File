#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, num, n1, n2;
    cin >> n;
    vector<int> file;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        file.push_back(num);
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < num; i++)
    {
        q.push(file[i]);
    }
    int res = num;
    while (q.size() > 1)
    {
        n1 = q.top();
        q.pop();
        n2 = q.top();
        q.pop();
        res += (n1 + n2);
        q.push(n1 + n2);
    }
    cout << res;
    return 0;
}