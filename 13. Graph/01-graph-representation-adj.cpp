#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// GOAL:
// - Convert prerequisite list into a graph
// - ONLY graph representation
// - No DFS / BFS / cycle detection here
// ============================================================================

bool canFinish(vector<vector<int>> &preRequiest)
{
    // =========================================================================
    // SECTION 1: GRAPH DECLARATION
    //
    // Using adjacency list representation
    // adj[u] -> list of nodes v such that u -> v
    //
    // Meaning:
    // If (u -> v) exists, then u must be done before v
    // =========================================================================

    unordered_map<int, vector<int>> adj;

    // =========================================================================
    // SECTION 2: BUILD GRAPH FROM PREREQUISITES
    //
    // Each pair:
    // vec[0] = course
    // vec[1] = prerequisite
    //
    // Edge direction:
    // prerequisite -> course
    // =========================================================================

    for (vector<int> &vec : preRequiest)
    {
        int course = vec[0];
        int prereq = vec[1];

        // Build directed edge: prereq -> course
        adj[prereq].push_back(course);
    }

    // =========================================================================
    // NOTE:
    // - Graph is now correctly represented
    // - Traversal / logic will be added later
    // =========================================================================

    return true; // placeholder (goal is only representation)
}

int main()
{
    // Example input (not required, just for clarity)
    vector<vector<int>> preRequiest = {
        {1, 0},
        {2, 1},
        {3, 2}};

    canFinish(preRequiest);

    return 0;
}
