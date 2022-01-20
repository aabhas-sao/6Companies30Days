#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, long long s) {
  int i = 0, j = -1;
  long long sum = 1LL * 0;
  vector<int> v(1, -1);

  for (int k = 0; k < n; k++) {
    sum += arr[k];
    j++;

    while (sum > s && i < j) {
      sum -= arr[i];
      i++;
    }

    if (sum == s) {
      v[0] = i + 1;
      v.push_back(j + 1);
      break;
    }
  }

  return v;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  long long s;
  cin >> s;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans = subarraySum(a, n, s);

  cout << ans[0] << " " << ans[1] << endl;

  return 0;
}