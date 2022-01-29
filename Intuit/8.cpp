#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int ans = 0;

    for (int i = 0; i < points.size(); i++) {
      unordered_map<long, int> u(points.size());

      for (int j = 0; j < points.size(); j++) {
        if (j == i) continue;

        long dx = points[i][1] - points[j][1];
        long dy = points[i][0] - points[j][0];

        long key = dx * dx;
        key += dy * dy;

        u[key]++;
      }

      for (auto x : u) {
        if (x.second > 1) {
          ans += x.second * (x.second - 1);
        }
      }
    }

    return ans;
  }
};