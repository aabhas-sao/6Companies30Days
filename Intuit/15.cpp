#include <bits/stdc++.h>
using namespace std;

bool canFinish(vector<int>& piles, int k, int h) {
  int local = 0;
  for (int i = 0; i < piles.size(); i++) {
    local += ceil(piles[i] / (1.0 * k));
  }

  // cout << k << " " << local << endl;

  if (local <= h) {
    return true;
  }

  return false;
}

int minEatingSpeed(vector<int>& piles, int h) {
  int lo = 1, hi = INT_MIN;
  for (auto x : piles) {
    hi = max(hi, x);
  }

  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    // cout << mid << endl;
    if (canFinish(piles, mid, h)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  return lo;
}