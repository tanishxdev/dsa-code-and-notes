#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
  vector<int> parent;

  // Constructor
  // Initially, every node is its own parent (separate sets)
  DSU(int n)
  {
    parent.resize(n);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }

  // Find the leader (root) of the set
  int find(int x)
  {
    // If node is its own parent, it is the leader
    if (parent[x] == x)
      return x;

    // Otherwise, move upward recursively
    return find(parent[x]);
  }

  // Merge sets of x and y
  void unionSet(int x, int y)
  {
    int px = find(x); // leader of x
    int py = find(y); // leader of y

    // If leaders are different, merge them
    if (px != py)
    {
      parent[px] = py; // attach x's root under y's root
    }
  }
};

int main()
{
  DSU dsu(5);

  dsu.unionSet(1, 2);
  dsu.unionSet(2, 3);
  dsu.unionSet(3, 4);

  // Leader can be 4 due to chaining
  cout << dsu.find(4) << endl;

  return 0;
}

/*

🔑 Key Note (IMPORTANT)

Output leader is not fixed

Correctness = all nodes have same leader*/
