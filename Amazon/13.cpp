#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool validCoordinate(int i, int j, int n, int m) {
    return i < n && j < m && i >= 0 && j >= 0;
  }

  vector<int> DIR = {-1, 0, 1, 0, -1};

  int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int n = grid.size(), m = grid[0].size();

    int time = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }

    q.push({-1, -1});

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      if (curr.first == -1) {
        if (q.empty()) {
          break;
        }
        time++;
        q.push({-1, -1});
        continue;
      }

      int i = curr.first, j = curr.second;

      for (int k = 0; k < 4; k++) {
        int x = i + DIR[k], y = j + DIR[k + 1];

        if (validCoordinate(x, y, n, m) && grid[x][y] == 1) {
          q.push({x, y});
          grid[x][y] = 2;
        }
      }
    }

    for (auto x : grid) {
      for (auto z : x) {
        if (z == 1) {
          return -1;
        }
      }
    }

    return time;
  }
};