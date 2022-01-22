#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool dfs(vector<int> adj[], int root, int target, int parent,
           vector<bool>& vis) {
    vis[root] = true;

    if (root == target) return true;

    for (auto child : adj[root]) {
      if (!vis[child] && child != parent) {
        if (dfs(adj, child, target, root, vis)) return true;
      }
    }

    return false;
  }
  // Function to find if the given edge is a bridge in graph.
  int isBridge(int V, vector<int> adj[], int c, int d) {
    adj[c].erase(remove(adj[c].begin(), adj[c].end(), d));

    if (c != d) {
      adj[d].erase(remove(adj[d].begin(), adj[d].end(), c));
    }

    vector<bool> vis(V, false);

    return !dfs(adj, c, d, -1, vis);
  }
};