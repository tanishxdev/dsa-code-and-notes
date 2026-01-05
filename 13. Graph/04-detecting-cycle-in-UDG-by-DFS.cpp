#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // =====================================================================
    // Helper Function: dfsCycle
    //
    // Purpose:
    // - Performs DFS to detect cycle in an undirected graph
    //
    // Parameters:
    // node    -> current node being visited
    // parent  -> node from which current node was called
    // adj     -> adjacency list of the graph
    // visited -> tracks visited nodes
    //
    // Returns:
    // true  -> cycle detected
    // false -> no cycle from this path
    // =====================================================================
    bool dfsCycle(int node, int parent,
                  vector<vector<int>>& adj,
                  vector<bool>& visited) {

        // Mark current node as visited
        visited[node] = true;

        // Traverse all neighbors of the current node
        for (int neighbor : adj[node]) {

            // Case 1: Neighbor not visited
            // Continue DFS deeper
            if (!visited[neighbor]) {
                if (dfsCycle(neighbor, node, adj, visited))
                    return true;   // Cycle found in deeper call
            }
            // Case 2: Neighbor already visited AND not parent
            // This indicates a back-edge -> cycle
            else if (neighbor != parent) {
                return true;
            }
        }

        // No cycle found starting from this node
        return false;
    }

    // =====================================================================
    // Function: isCycle
    //
    // Purpose:
    // - Builds the graph
    // - Checks for cycle in all connected components
    //
    // Parameters:
    // V     -> number of vertices
    // edges -> edge list representation
    //
    // Returns:
    // true  -> cycle exists
    // false -> no cycle
    // =====================================================================
    bool isCycle(int V, vector<vector<int>>& edges) {

        // ---------------------------------------------------------------
        // STEP 1: Build adjacency list from edge list
        // ---------------------------------------------------------------
        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            // Since graph is undirected, add both directions
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // ---------------------------------------------------------------
        // STEP 2: Visited array initialization
        // ---------------------------------------------------------------
        vector<bool> visited(V, false);

        // ---------------------------------------------------------------
        // STEP 3: Check each connected component
        // ---------------------------------------------------------------
        for (int i = 0; i < V; i++) {

            // If node is not visited, start DFS from it
            if (!visited[i]) {
                if (dfsCycle(i, -1, adj, visited))
                    return true;   // Cycle detected
            }
        }

        // No cycle found in any component
        return false;
    }
};

int main() {
    Solution sol;

    int V = 4;

    // Edge list of the graph
    vector<vector<int>> edges = {
        {0,1}, {0,2}, {1,2}, {2,3}
    };

    // Check if cycle exists
    if (sol.isCycle(V, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
