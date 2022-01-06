#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k) {
    deque<int> q;
    long long int overlap = 0;
    long long int prevSize = 0;
    long long int size = 0;
    long long int product = 1;
    long long int ans = 0;
    long long int cnt = 0;

    for (int i = 0; i <= n; i++) {
      if (i < n) {
        product *= (a[i] * 1LL);
        q.push_back(a[i]);
      }

      if (product >= k || i == n) {
        ans += ((size + 1) * size) / 2;
        ans -= (overlap + 1) * overlap / 2;

        prevSize = size;

        cnt = 0;

        while (product >= k) {
          size--;
          cnt++;
          product /= q.front();
          q.pop_front();
        }

        overlap = prevSize - cnt;
      }

      size++;
    }

    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  long long k;
  cin >> n >> k;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  Solution s;
  cout << s.countSubArrayProductLessThanK(a, n, k) << endl;

  return 0;
}