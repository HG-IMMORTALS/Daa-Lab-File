#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool comp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
    return (p1.second < p2.second);
}
int find(int src, int parent[])
{
    int i = src;
    while (parent[i] != -1)
    {
        i = parent[i];
    }
    return i;
}
bool uni(int x, int y, int parent[])
{
    int r1 = find(x, parent);
    int r2 = find(y, parent);
    if (r1 == r2)
        return true;
    parent[r1] = r2;
    return false;
}
void Krushkals(vector<pair<pair<int, int>, int>> &G, int edge, int v)
{
    int i, x, y;
    sort(G.begin(), G.end(), comp);
    vector<pair<int, int>> MST;
    int sum = 0;
    int p[v];
    for (i = 0; i < v; i++)
    {
        p[i] = -1;
    }
    for (i = 0; i < edge; i++)
    {
        x = G[i].first.first;
        y = G[i].first.second;
        bool cycle = uni(x, y, p);
        if (cycle != true)
        {
            MST.push_back(make_pair(x, y));
            sum += G[i].second;
        }
        else
            continue;
    }
    cout << "Minimum Spanning Tree is " << endl;
    for (i = 0; i != MST.size(); i++)
    {
        cout << MST[i].first << " - " << MST[i].second << endl;
    }
    cout << "Minimum Weight is : " << sum << endl;
}
int main()
{
    int ver, edge, i, j, src, dest, wt;
    cin >> ver;
    cin >> edge;
    vector<pair<pair<int, int>, int>> G;
    pair<int, int> x;
    pair<pair<int, int>, int> y;
    for (i = 0; i < edge; i++)
    {
        cin >> src >> dest >> wt;
        x = make_pair(src, dest);
        y = make_pair(x, wt);
        G.push_back(y);
    }
    Krushkals(G, edge, ver);
    return 0;
}