
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Helper function to detect a cycle in an undirected graph using BFS
    bool bfsCycle(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        // Queue stores pairs of {current_node, parent_node}
        queue<pair<int,int>> q;
        visited[start] = true;               // Mark starting node as visited
        q.push({start, -1});                 // Push root node with no parent (-1)

        // Continue BFS until all reachable nodes are processed
        while(!q.empty()) {
            int node = q.front().first;      // Current node
            int parent = q.front().second;   // Its parent
            q.pop();

            // Traverse all adjacent (neighboring) nodes
            for(int neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    // If neighbor not visited, mark visited and push to queue
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                }
                else if(neighbor != parent) {
                    // If neighbor is visited and not parent → Cycle found
                    return true;
                }
            }
        }

        // No cycle found in this connected component
        return false;
    }

    // Main function to detect a cycle in an undirected graph
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list from the given edge list
        vector<vector<int>> adj(V);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Undirected graph → add both directions
        }

        // Step 2: Initialize visited array for all nodes
        vector<bool> visited(V, false);

        // Step 3: Traverse each connected component of the graph
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                // If the component has a cycle → return true
                if(bfsCycle(i, adj, visited))
                    return true;
            }
        }

        // Step 4: If no cycle found in any component → return false
        return false;
    }
};

// Example usage
int main() {
    Solution sol;

    int V = 4;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 3}
    };

    if(sol.isCycle(V, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}