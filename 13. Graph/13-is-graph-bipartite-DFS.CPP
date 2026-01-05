#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int currColor,
         vector<vector<int>> &adj,
         vector<int> &color)
{
    color[node] = currColor;

    for (int neighbor : adj[node])
    {
        if (color[neighbor] == -1)
        {
            if (!dfs(neighbor, !currColor, adj, color))
                return false;
        }
        else if (color[neighbor] == currColor)
            return false;
    }
    return true;
}

bool isBipartiteDFS(int V, vector<vector<int>> &adj)
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, adj, color))
                return false;
        }
    }
    return true;
}

int main()
{
    int V = 4;

    vector<vector<int>> adj = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}};

    if (isBipartiteDFS(V, adj))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
