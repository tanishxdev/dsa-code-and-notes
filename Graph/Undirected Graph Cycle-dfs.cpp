#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS helper to detect cycle in undirected graph
    // node    : current node
    // parent  : parent of current node
    // adj     : adjacency list
    // visited : track visited nodes
    bool dfsCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                if(dfsCycle(neighbor, node, adj, visited))
                    return true; // Cycle found in deeper DFS
            }
            else if(neighbor != parent) {
                // Visited neighbor which is not parent → cycle detected
                return true;
            }
        }
        return false; // No cycle found in this path
    }

    // Main function to detect cycle in undirected graph
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list from edges
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected
        }

        // Step 2: Track visited nodes
        vector<bool> visited(V, false);

        // Step 3: Check all connected components
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfsCycle(i, -1, adj, visited))
                    return true; // Cycle detected
            }
        }

        return false; // No cycle in any component
    }
};

// Example usage
int main() {
    Solution sol;

    int V = 4;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{2,3}};

    if(sol.isCycle(V, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
