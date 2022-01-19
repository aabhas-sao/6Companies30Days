#include <bits/stdc++.h>
using namespace std;

vector<int> DIR = {-1, 0, 1, 0, -1, 1, 1, -1, -1};

bool valid(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int findMaxArea(vector<vector<int>>& grid) {
  int n = grid.size(), m = grid[0].size();
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int val = grid[i][j];
      if (val == 1 && !vis[i][j]) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        int count = 0;

        while (!q.empty()) {
          auto curr = q.front();
          q.pop();
          count++;

          for (int k = 0; k < 8; k++) {
            int x = curr.first + DIR[k];
            int y = curr.second + DIR[k + 1];

            if (valid(x, y, n, m) && grid[x][y] == 1 && !vis[x][y]) {
              vis[x][y] = true;
              q.push({x, y});
            }
          }
        }

        ans = max(ans, count);
      }
    }
  }

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  cout << findMaxArea(grid) << endl;
  return 0;
}