#include <bits/stdc++.h>
using namespace std;

int helper(int i, int a[], int n, vector<int>& dp) {
  if (i >= n) return 0;

  if (dp[i] != -1) return dp[i];

  int dontRob = helper(i + 1, a, n, dp);
  int rob = helper(i + 2, a, n, dp) + a[i];
  return dp[i] = max(rob, dontRob);
}
int FindMaxSum(int arr[], int n) {
  vector<int> dp(n + 1, -1);
  return helper(0, arr, n, dp);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  int a[n];

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cout << FindMaxSum(a, n) << endl;
}