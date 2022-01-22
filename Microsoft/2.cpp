#include <bits/stdc++.h>
using namespace std;

bool dfs(int root, unordered_map<int, vector<int>>& graph,
         unordered_map<int, bool>& vis, unordered_map<int, bool>& dfsvis) {
  bool res = true;
  vis[root] = true;
  dfsvis[root] = true;

  for (auto x : graph[root]) {
    if (!vis[x]) {
      res = res && dfs(x, graph, vis, dfsvis);
    }
    if (dfsvis[x]) return false;
  }

  dfsvis[root] = false;

  return res;
}

bool isPossible(int N, vector<pair<int, int>>& prerequisites) {
  unordered_map<int, vector<int>> g;
  unordered_map<int, bool> vis;
  unordered_map<int, bool> dfsvis;

  for (auto x : prerequisites) {
    g[x.second].push_back(x.first);
    vis[x.first] = false;
    vis[x.second] = false;
    dfsvis[x.first] = false;
    dfsvis[x.second] = false;
  }

  while (1) {
    bool ran = false;
    for (auto x : vis) {
      if (!x.second) {
        ran = true;
        bool ans = dfs(x.first, g, vis, dfsvis);
        if (!ans) return false;
      }
    }

    if (!ran) break;
  }

  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, p;
  cin >> n >> p;

  vector<pair<int, int>> v(p);
  for (int i = 0; i < p; i++) {
    cin >> v[i].first >> v[i].second;
  }
  cout << isPossible(n, v);
}