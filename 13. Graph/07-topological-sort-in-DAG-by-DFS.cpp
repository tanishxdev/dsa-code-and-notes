#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node,
             vector<vector<int>> &adj,
             vector<bool> &visited,
             stack<int> &st)
    {

        visited[node] = true;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, adj, visited, st);
            }
        }

        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>> &adj)
    {

        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }

        vector<int> result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

int main()
{
    int V = 6;
    vector<vector<int>> adj = {
        {2, 3},
        {3, 4},
        {},
        {5},
        {5},
        {}};

    Solution sol;
    vector<int> topo = sol.topoSort(V, adj);

    cout << "Topological Order: ";
    for (int x : topo)
        cout << x << " ";
    cout << endl;

    return 0;
}
