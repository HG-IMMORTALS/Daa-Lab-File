#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int shortestPath(vector<vector<int>> graph, int u, int v, int k, int V)
{
    if (k == 0 && u == v)
        return 0;
    if (k == 1 && graph[u][v] != 0)
        return graph[u][v];
    if (k <= 0)
        return -1;
    int res = INT_MAX;
    for (int i = 0; i < V; i++)
    {
        if (graph[u][i] != 0 && u != i && v != i)
        {
            int rec_res = shortestPath(graph, i, v, k - 1, V);
            if (rec_res != INT_MAX)
                res = min(res, graph[u][i] + rec_res);
        }
    }
    return res;
}
int main()
{
    int V, n, src, dest, k;
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> n;
            graph[i][j] = n;
        }
    }
    cin >> src >> dest >> k;
    int ans = shortestPath(graph, src, dest, k, V);
    if (ans == -1)
        cout << "no path of length k is available" << endl;
    else
        cout << "Weight of shortest Path(" << src << "," << dest << ") with " << k << "edges ="<<ans;
            return 0;
}