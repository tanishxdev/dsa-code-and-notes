#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent;
    vector<int> rank;

    // Constructor
    // Each node starts as its own parent with rank 0
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Find with path compression
    int find(int x)
    {
        // If x is not the leader, compress path
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by rank
    void unionSet(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        // Already in same set
        if (px == py)
            return;

        // Attach smaller rank tree under larger rank tree
        if (rank[px] < rank[py])
        {
            parent[px] = py;
        }
        else if (rank[px] > rank[py])
        {
            parent[py] = px;
        }
        else
        {
            // Same rank → pick one as root and increase rank
            parent[py] = px;
            rank[px]++;
        }
    }
};

int main()
{
    DSU dsu(5);

    dsu.unionSet(1, 2);
    dsu.unionSet(2, 3);
    dsu.unionSet(3, 4);

    // Leader is stable and balanced (likely 1)
    cout << dsu.find(4) << endl;

    return 0;
}
