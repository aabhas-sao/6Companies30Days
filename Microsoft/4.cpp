#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) {
  int left = 0, top = 0;
  int bottom = r - 1, right = c - 1;

  vector<int> res;
  if (r == 0 || c == 0) return res;
  int direction = 1;

  while (left <= right && top <= bottom) {
    if (direction == 1) {
      for (int i = left; i <= right; i++) res.push_back(matrix[top][i]);
      direction = 2;
      top++;
    } else if (direction == 2) {
      for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
      direction = 3;
      right--;
    } else if (direction == 3) {
      for (int i = right; i >= left; i--) res.push_back(matrix[bottom][i]);
      direction = 4;
      bottom--;
    } else if (direction == 4) {
      for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
      direction = 1;
      left++;
    }
  }

  return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  vector<int> ans = spirallyTraverse(v, n, m);

  for (auto x : ans) {
    cout << x << " ";
  }
  return 0;
}