#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD (int)(1e9 + 7)

int kvowelwords(int N, int K) {
  vector<vector<ll>> dp(N + 1, vector<ll>(K + 1));

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= K; j++) {
      if (i == 0) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = 21 * dp[i - 1][K] % MOD;
        if (j > 0) {
          dp[i][j] = dp[i][j] + (dp[i - 1][j - 1] * 5 % MOD);
          dp[i][j] %= MOD;
        }
      }
    }
  }

  return (int)dp[N][K];
}