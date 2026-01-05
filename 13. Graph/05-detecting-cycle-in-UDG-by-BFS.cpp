#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool bfsCycle(int start,
                  vector<vector<int>> &adj,
                  vector<bool> &visited)
    {

        queue<pair<int, int>> q;
        visited[start] = true;
        q.push({start, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                }
                else if (neighbor != parent)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (bfsCycle(i, adj, visited))
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;

    int V = 4;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 3}};

    if (sol.isCycle(V, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
