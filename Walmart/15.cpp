#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;

    unsigned int a = abs(dividend);
    unsigned int b = abs(divisor);
    unsigned int ans = 0;
    bool isPositive = dividend < 0 == divisor < 0;

    while (a >= b) {
      short q = 0;

      while ((b << (q + 1)) < a) q++;

      ans += (1 << q);
      a -= (b << q);
    }

    if (ans == (1 << 31) && isPositive) {
      ans = INT_MAX;
    }

    return isPositive ? ans : -1 * ans;
  }
};