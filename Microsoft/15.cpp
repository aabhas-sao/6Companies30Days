#include <bits/stdc++.h>
using namespace std;

void dfs(char root, unordered_map<char, set<char>>& g,
         unordered_map<char, bool>& vis, string& v) {
  vis[root] = true;
  for (auto x : g[root]) {
    if (!vis[x]) {
      dfs(x, g, vis, v);
    }
  }
  v.push_back(root);
}

string findOrder(string dict[], int N, int K) {
  unordered_map<char, set<char>> g;
  unordered_map<char, bool> vis;

  for (int i = 0; i <= N - 2; i++) {
    int x = 0, y = 0;
    while (x < dict[i].size() && y < dict[i + 1].size()) {
      char a = dict[i][x];
      char b = dict[i + 1][y];
      vis[a] = false;
      vis[b] = false;
      x++;
      y++;
      if (a == b) continue;

      g[a].insert(b);
      break;
    }
  }

  string ans;

  // for (auto x : g) {
  //   cout << x.first << ": ";
  //   for (auto y : x.second) {
  //     cout << y << " ";
  //   }
  //   cout << endl;
  // }

  while (1) {
    bool ran = false;
    string v;
    for (auto x : vis) {
      if (!x.second) {
        ran = true;
        dfs(x.first, g, vis, v);
        break;
      }
    }
    reverse(v.begin(), v.end());
    ans.insert(ans.begin(), v.begin(), v.end());

    if (!ran) break;
  }

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, k;
  cin >> n >> k;
  string dict[n];

  for (int i = 0; i < n; i++) {
    cin >> dict[i];
  }

  cout << findOrder(dict, n, k);

  return 0;
}