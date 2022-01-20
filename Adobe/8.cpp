#include <bits/stdc++.h>
using namespace std;

int atoi(string str) {
  int ans = 0;
  int base = 1;

  for (int i = str.size() - 1; i >= 0; i--) {
    if (str[i] >= '0' && str[i] <= '9') {
      int dig = str[i] - '0';
      ans += base * dig;
    } else {
      if (str[i] == '-' && i == 0) {
        ans *= -1;
      } else {
        return -1;
      }
    }
    base *= 10;
  }
  return ans;
}