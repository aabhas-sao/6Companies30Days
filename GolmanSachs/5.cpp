#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int

class Solution {
 public:
  // #define ull unsigned long long
  /* Function to get the nth ugly number*/
  ull getNthUglyNo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<ull> v(n);
    v[0] = 1;
    int t2 = 0, t3 = 0, t5 = 0;

    for (int i = 1; i < n; i++) {
      v[i] = min({v[t2] * 2, v[t3] * 3, v[t5] * 5});

      if (v[i] == v[t2] * 2) t2++;
      if (v[i] == v[t3] * 3) t3++;
      if (v[i] == v[t5] * 5) t5++;
    }

    return v[n - 1];
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  Solution s;
  cout << s.getNthUglyNo(n) << endl;
}