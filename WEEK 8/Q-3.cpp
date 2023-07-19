#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, num;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> num;
            graph[i][j] = num;
        }
    }
    int key[N];
    int parent[N];
    bool mstset[N];
    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MIN;
        mstset[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < N - 1; count++)
    {
        int mini = INT_MIN, u;
        for (int i = 0; i < N; i++)
        {
            if (mstset[i] == false && key[i] > mini)
            {
                mini = key[i];
                u = i;
            }
        }
        mstset[u] = true;
        for (int i = 0; i < N; i++)
        {
            if (graph[u][i] && mstset[i] == false && key[i] < graph[u][i])
            {
                parent[i] = u;
                key[i] = graph[u][i];
            }
        }
    }
    int res = 0;
    for (int i = 1; i < N; i++)
    {
        cout << graph[i][parent[i]] << " ";
        res += graph[i][parent[i]];
    }
    cout << "Maximum Spanning Weight: " << res << endl;
    return 0;
}