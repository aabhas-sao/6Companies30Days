#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int *findTwoElement(int *a, int n) {
    int arr[2];
    int *ptr = arr;

    for (int i = 0; i < n; i++) {
      int idx = abs(a[i]) - 1;
      // cout << idx << endl;
      if (a[idx] > 0) {
        a[idx] *= -1;

      } else {
        arr[0] = abs(a[i]);
      }
    }

    for (int i = 0; i < n; i++) {
      if (a[i] > 0) {
        arr[1] = i + 1;
      }
    }

    return ptr;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  Solution s;
  auto b = s.findTwoElement(a, n);

  cout << b[0] << " " << b[1] << '\n';

  return 0;
}