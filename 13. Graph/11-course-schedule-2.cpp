#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> result;

        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            result.push_back(course);

            for (int next : adj[course])
            {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return result.size() == numCourses ? result : vector<int>();
    }
};

int main()
{
    Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> result = sol.findOrder(numCourses, prerequisites);
    for (int course : result)
        cout << course << " ";
    cout << endl;
    return 0;
}
