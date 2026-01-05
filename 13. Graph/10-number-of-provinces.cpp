#include <bits/stdc++.h>
using namespace std;

// DFS → recursion, goes deep
// BFS → queue, goes level-wise
// Both count connected components
// Time: O(N²) (matrix traversal)
// Space: O(N)

class Solution
{
public:
    // ⭐ Approach 1: DFS
    void dfs(int node,
             vector<vector<int>> &isConnected,
             vector<bool> &visited,
             int V)
    {

        visited[node] = true;

        for (int neighbor = 0; neighbor < V; neighbor++)
        {
            if (isConnected[node][neighbor] == 1 &&
                !visited[neighbor])
            {
                dfs(neighbor, isConnected, visited, V);
            }
        }
    }

    int findCircleNumDFS(vector<vector<int>> &isConnected)
    {

        int V = isConnected.size();
        vector<bool> visited(V, false);
        int provinces = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, isConnected, visited, V);
                provinces++;
            }
        }

        return provinces;
    }

    // ⭐ Approach 2: BFS
    int findCircleNumBFS(vector<vector<int>> &isConnected)
    {

        int V = isConnected.size();
        vector<bool> visited(V, false);
        int provinces = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {

                provinces++;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (int neighbor = 0; neighbor < V; neighbor++)
                    {
                        if (isConnected[node][neighbor] == 1 &&
                            !visited[neighbor])
                        {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};

int main()
{

    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};

    Solution sol;

    cout << "DFS Provinces: "
         << sol.findCircleNumDFS(isConnected) << endl;

    cout << "BFS Provinces: "
         << sol.findCircleNumBFS(isConnected) << endl;

    return 0;
}
