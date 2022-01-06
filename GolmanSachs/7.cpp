#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findPosition(int N, int M, int K) {
    int s = M % N;
    if (s == 0) s = N;

    K = K % N;
    if (K == 0) K = N;
    int diff = K - 1;
    s += diff;

    s %= N;
    if (s == 0) {
      s = N;
    }

    return s;
  }
};

int main() {}