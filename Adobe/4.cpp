#include <bits/stdc++.h>
using namespace std;

int equalPartition(int n, int a[]) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  if (sum & 1) return false;
  sum /= 2;

  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i <= sum; i++) {
    dp[0][i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      dp[i][j] = dp[i - 1][j];

      if (j - a[i - 1] >= 0) dp[i][j] = dp[i][j] || dp[i - 1][j - a[i - 1]];
    }
  }

  return dp[n][sum];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << equalPartition(n, a);
  return 0;
}