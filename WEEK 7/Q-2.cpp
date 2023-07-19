#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minDistance(int dist[], bool processed[], int V)
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
        if (processed[i] == false && dist[i] <= min)
            min = dist[i], min_index = i;
    return min_index;
}
void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    cout << j << " ";
}
void printSolution(int dist[], int V, int parent[], int src)
{
    for (int i = 0; i < V; i++)
    {
        cout << src << " ";
        printPath(parent, i);
        cout << ":" << dist[i] << endl;
    }
}
void dijkstra(vector<vector<int>> graph, int src, int *dist, int *parent)
{
    int V = graph.size();
    bool processed[V] = {false};
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, processed, V);
        processed[u] = true;
        for (int v = 0; v < V; v++)
            if (!processed[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
}
int main()
{
    int n, source, wt;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> wt;
            graph[i][j] = wt;
        }
    }
    cin >> source;
    int dist[n];
    int parent[n] = {-1};
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[source] = 0;
    for (int i = 0; i < n; i++)
        dijkstra(graph, source, dist, parent);
    printSolution(dist, n, parent, source);
    return 0;
}