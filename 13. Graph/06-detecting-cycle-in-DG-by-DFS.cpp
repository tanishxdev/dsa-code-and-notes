#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfsCycle(int node,
                  vector<vector<int>> &adj,
                  vector<bool> &visited,
                  vector<bool> &recStack)
    {

        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                if (dfsCycle(neighbor, adj, visited, recStack))
                    return true;
            }
            else if (recStack[neighbor])
            {
                return true;
            }
        }

        recStack[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfsCycle(i, adj, visited, recStack))
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, {2, 3}};

    Solution sol;

    if (sol.isCyclic(V, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
