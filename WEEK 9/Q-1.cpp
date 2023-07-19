#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
void printSolution(int V, vector<vector<int>> dist)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
void floydWarshall(int V, vector<vector<int>> graph)
{
    int i, j, k;
    vector<vector<int>> dist(V, vector<int>(V));
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    cout << "Shortest Distance Matrix:" << endl;
    printSolution(V, dist);
}
int main()
{
    int V = 5;
    vector<vector<int>> graph{{0, 10, 5, 5, INF},
                              {INF, 0, 5, 5, 5},
                              {INF, INF, 0, INF, 10},
                              {INF, INF, INF, 0, 20},
                              {INF, INF, INF, 5, 0}};
    floydWarshall(V, graph);
    return 0;
}