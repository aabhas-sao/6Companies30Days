#include <climits>
#include <vector>
using namespace std;

class Solution {
 public:
  int minDifference(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = true;
    }

    for (int i = 1; i <= sum; i++) {
      dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sum; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j - a[i - 1] >= 0) dp[i][j] = dp[i][j] || dp[i - 1][j - a[i - 1]];
      }
    }

    vector<int> poss;

    // for (auto x : dp) {
    //   for (auto y : x) {
    //     cout << y << " ";
    //   }
    //   cout << endl;
    // }

    for (int i = 0; i <= sum / 2; i++) {
      if (dp[n][i]) {
        poss.push_back(i);
      }
    }

    int ans = INT_MAX;

    for (auto x : poss) {
      ans = min(sum - 2 * x, ans);
    }

    return ans;
  }
};