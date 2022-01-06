#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long squaresInChessBoard(long long N) {
    return ((2 * N + 1) * (N + 1) * (N)) / 6;
  }
};

int main() {
  long long n;
  cin >> n;
  Solution s;
  cout << s.squaresInChessBoard(n) << endl;
}