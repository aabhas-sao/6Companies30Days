#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, long long s) {
  int i = 0, j = 0;
  long long sum = 1LL * arr[0];
  vector<int> v;

  for (int k = 0; k < n; k++) {
    while (sum > s) {
      i++;
      sum -= arr[i];
    }

    if (sum == s) {
      v.push_back(i);
      v.push_back(j);
    }

    sum += arr[k];
    j++;

    return v;
  }
}

int main() {
  int n;
  cin >> n;
  long long s;
  cin >> s;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << subarraySum(a, n, s);
  return 0;
}