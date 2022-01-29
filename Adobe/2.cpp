#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Function to find a continuous sub-array which adds up to a given number.
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
};