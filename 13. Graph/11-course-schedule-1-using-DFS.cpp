#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int node,
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
                if (dfs(neighbor, adj, visited, recStack))
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

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, recStack))
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << (sol.canFinish(numCourses, prerequisites) ? "true" : "false");
}
