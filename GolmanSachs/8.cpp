#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD (int)(1e9 + 7)

class Solution {
 public:
  int CountWays(string s) {
    int p = 1, pp, n = s.size();

    for (int i = n - 1; i >= 0; i--) {
      int curr = s[i] == '0' ? 0 : p % MOD;
      if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) {
        curr += (pp % MOD);
      }
      pp = p % MOD;
      p = curr % MOD;
    }

    return s.empty() ? 0 : p % MOD;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  string s;
  cin >> s;
  Solution a;
  cout << a.CountWays(s) << endl;

  return 0;
}