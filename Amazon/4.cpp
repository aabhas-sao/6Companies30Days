#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  pair<int, string> mcm(int a[], int i, int j, int n, string& ans,
                        vector<vector<pair<int, string>>>& dp) {
    // base case ( smalles valid input or largest invalid input)
    if (i >= j) return dp[i][j] = {0, ans};

    if (dp[i][j].first != -1) return dp[i][j];

    int temp = INT_MAX, partition;
    int z = 1;
    string tmp;

    for (int k = i; k <= j - 1; k++) {
      // cout << "z: " << z << " " << ans.size() << endl;
      string p1 = ans.substr(0, z);
      // cout << p1 << endl;
      string p2 = ans.substr(z, ans.size() - z);
      // cout << p2 << endl;
      auto a1 = mcm(a, i, k, n, p1, dp);
      auto a2 = mcm(a, k + 1, j, n, p2, dp);

      int cost = a1.first + a2.first + a[i - 1] * a[k] * a[j];

      if (cost < temp) {
        temp = cost;
        partition = k;
        if (a1.second.size() == 1) {
          if (a2.second.size() == 1) {
            tmp = a1.second + a2.second;
          } else {
            tmp = a1.second + '(' + a2.second + ')';
          }
        } else {
          if (a2.second.size() == 1) {
            tmp = '(' + a1.second + ')' + a2.second;
          } else {
            tmp = '(' + a1.second + ')' + '(' + a2.second + ')';
          }
        }
      }
      z += 1;
    }

    if (ans.size() <= 2) {
      tmp = ans;
    }

    return dp[i][j] = {temp, tmp};
  }

  string matrixChainOrder(int p[], int n) {
    string ans = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ans = ans.substr(0, n - 1);

    vector<vector<pair<int, string>>> dp(
        n + 1, vector<pair<int, string>>(n + 1, {-1, ""}));

    if (n <= 2) {
      return ans;
    }
    return '(' + mcm(p, 1, n - 1, n, ans, dp).second + ')';
  }
};