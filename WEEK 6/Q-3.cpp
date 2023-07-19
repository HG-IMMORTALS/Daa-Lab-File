#include <bits/stdc++.h>
using namespace std;
bool iscycle(vector<int> adj[], int node, vector<int> &visited, vector<int> &dfsvisited)
{
    stack<pair<int, int>> st;
    visited[node] = 1;
    dfsvisited[node] = 1;
    for (auto i : adj[node])
    {
        if (visited[i] == 0)
        {
            if (iscycle(adj, i, visited, dfsvisited))
                return true;
        }
        else if (dfsvisited[i] == 1)
            return true;
    }
    dfsvisited[node] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> dfsvisited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            if (iscycle(adj, i, visited, dfsvisited))
                return true;
        }
    }
    return false;
}
int main()
{
    int n, e, u, v;
    cin >> n >> e;
    vector<int> adj[n];
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    if (isCyclic(n, adj))
        cout << "Yes Cycle Exists";
    else
    {
        cout << "No Cycle Exists";
    }
    return 0;
}
