#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int a[], int n) {
  int x = INT_MIN;
  vector<int> ans;

  for (int i = n - 1; i >= 0; i--) {
    if (a[i] >= x) {
      ans.push_back(a[i]);
      x = a[i];
    }
  }

  reverse(ans.begin(), ans.end());
  return ans;
}