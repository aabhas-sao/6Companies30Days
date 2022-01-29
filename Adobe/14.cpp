#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k) {
    vector<int> res;
    vector<pair<int, int>> v;

    for (int i = 0; i < k; i++)
      for (int j = 0; j < n; j++) v.push_back({KSortedArray[i][j], i});

    sort(v.begin(), v.end());

    int i = 0, j = 0, groups = 0;

    unordered_map<int, int> u;

    while (j < v.size()) {
      if (u[v[j].second]++ == 0) groups++;

      while (groups == k) {
        if (res.empty() || v[j].first - v[i].first < res[1] - res[0]) {
          res = {v[i].first, v[j].first};
        }
        if (u[v[i].second]-- == 1) groups--;
        i++;
      }
      j++;
    }

    return {res[0], res[1]};
  }
};