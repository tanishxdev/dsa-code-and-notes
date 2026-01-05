#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfsTraversal(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &result)
    {
        visited[node] = true;
        result.push_back(node);

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfsTraversal(neighbor, adj, visited, result);
            }
        }
    }

    vector<int> dfs(vector<vector<int>> &adj)
    {
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> result;

        dfsTraversal(0, adj, visited, result);

        return result;
    }
};

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0] = {2, 3, 1};
    adj[1] = {0};
    adj[2] = {0, 4};
    adj[3] = {0};
    adj[4] = {2};

    Solution obj;
    vector<int> dfsResult = obj.dfs(adj);

    cout << "DFS Traversal: ";
    for (int node : dfsResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
