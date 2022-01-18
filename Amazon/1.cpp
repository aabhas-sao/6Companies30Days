#include <bits/stdc++.h>
using namespace std;

#define vvvi vector<vector<vector<int>>>

int mp(int k, int i, int n, int a[], int buy, vvvi& dp) {
  if (k == 0 || i == n) {
    return 0;
  }

  if (dp[n - i][k][buy] != -1) return dp[n - i][k][buy];

  if (buy) {
    int skip = mp(k, i + 1, n, a, 1, dp);
    int sell = a[i] + mp(k - 1, i + 1, n, a, 0, dp);
    return dp[n - i][k][buy] = max(skip, sell);
  } else {
    int skip = mp(k, i + 1, n, a, 0, dp);
    int by = -a[i] + mp(k, i + 1, n, a, 1, dp);
    return dp[n - i][k][buy] = max(skip, by);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int k;
  cin >> k;
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  vvvi dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));

  bool buy = false;
  int stockPrice = -1;
  cout << mp(k, 0, n, a, 0, dp) << endl;

  return 0;
}