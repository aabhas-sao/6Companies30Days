#include <bits/stdc++.h>
using namespace std;

int minSteps(int n) {
  if (n == 0) return n;
  int steps = 1, sum = 0;

  while (sum < n) {
    sum += steps;
    steps++;
  }

  while ((sum - n) & 1) {
    sum += steps;
    steps++;
  }

  return steps - 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  cout << minSteps(n) << endl;
}