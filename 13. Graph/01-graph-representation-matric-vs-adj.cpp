// ============================================================================
// GRAPH REPRESENTATION IN C++
//
// This file demonstrates THREE STANDARD ways to store a graph:
//
// 1. Adjacency List   -> Most commonly used in DSA (BFS, DFS, shortest paths)
// 2. Adjacency Matrix-> Useful for dense graphs and quick edge lookup
// 3. Edge List       -> Useful in Kruskal's algorithm and simple storage
//
// IMPORTANT:
// - This file focuses ONLY on *representation*, not traversal.
// - No BFS / DFS / Cycle detection here.
// - Graph is assumed to be UNDIRECTED unless stated otherwise.
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{

    // ============================================================================
    // STEP 0: DEFINE GRAPH SIZE
    //
    // n = number of nodes in the graph
    // We are using 1-based indexing (nodes from 1 to n)
    // ============================================================================

    int n = 5;

    // ============================================================================
    // STEP 1: DEFINE EDGE LIST (RAW GRAPH INPUT)
    //
    // This is the MOST BASIC form of graph input.
    // Each pair (u, v) means there is an edge between u and v.
    //
    // Graph structure:
    //
    // 1 -- 2 -- 3
    // |
    // 4 -- 5
    //
    // NOTE:
    // - Graph is undirected
    // - Each edge will be added in BOTH directions later
    // ============================================================================

    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {1, 4},
        {4, 5}};

    // ============================================================================
    // SECTION 1: ADJACENCY LIST REPRESENTATION
    //
    // Definition:
    // adj_list[u] stores all neighbors directly connected to node u.
    //
    // Why adjacency list?
    // - Best for BFS / DFS
    // - Space efficient for sparse graphs
    // - Most commonly used in interviews & CP
    //
    // Space Complexity: O(V + E)
    // ============================================================================

    // STEP 1.1: Create adjacency list container
    // n + 1 because we are using 1-based indexing
    vector<vector<int>> adj_list(n + 1);

    // STEP 1.2: Convert edge list into adjacency list
    for (auto &edge : edges)
    {

        int u = edge.first;  // first node of edge
        int v = edge.second; // second node of edge

        // Since graph is UNDIRECTED, add both directions
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    // STEP 1.3: Print adjacency list
    // Format: node -> list of neighbors
    cout << "Adjacency List:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";

        for (auto &nbr : adj_list[i])
        {
            cout << nbr << " ";
        }

        cout << "\n";
    }
    cout << "\n";

    // ============================================================================
    // SECTION 2: ADJACENCY MATRIX REPRESENTATION
    //
    // Definition:
    // adj_matrix[u][v] = 1  => edge exists between u and v
    // adj_matrix[u][v] = 0  => no edge
    //
    // Why adjacency matrix?
    // - O(1) edge existence check
    // - Simple implementation
    //
    // Drawbacks:
    // - Space complexity O(V^2)
    // - Not suitable for large graphs
    // ============================================================================

    // STEP 2.1: Create adjacency matrix initialized with 0
    vector<vector<int>> adj_matrix(n + 1, vector<int>(n + 1, 0));

    // STEP 2.2: Fill adjacency matrix using edge list
    for (auto &edge : edges)
    {

        int u = edge.first;
        int v = edge.second;

        // Mark edge in both directions (undirected graph)
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    // STEP 2.3: Print adjacency matrix
    cout << "Adjacency Matrix:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // ============================================================================
    // SECTION 3: EDGE LIST REPRESENTATION
    //
    // Definition:
    // Graph is stored as a simple list of edges (u, v)
    //
    // Why edge list?
    // - Very easy to store
    // - Used in Kruskal's Algorithm (MST)
    // - Useful when edge processing is more important than traversal
    //
    // Drawback:
    // - Inefficient neighbor lookup
    // ============================================================================

    // STEP 3.1: Print edge list
    cout << "Edge List:\n";
    for (auto &edge : edges)
    {
        cout << edge.first << " -- " << edge.second << "\n";
    }
    cout << "\n";

    return 0;
}
