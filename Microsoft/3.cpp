#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
  int n = matrix.size(), m = matrix[0].size();

  for (auto& x : matrix) {
    reverse(x.begin(), x.end());
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i > j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
}