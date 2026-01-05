#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &adj)
    {

        vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++)
        {
            for (int v : adj[u])
            {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            result.push_back(node);

            for (int neighbor : adj[node])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        return result;
    }
};

int main()
{
    int V = 6;
    vector<vector<int>> adj = {
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2}};

    Solution sol;
    vector<int> topo = sol.topoSort(V, adj);

    cout << "Topological Order: ";
    for (int x : topo)
        cout << x << " ";
    cout << endl;

    return 0;
}
