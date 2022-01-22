#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // arr[] : int input array of integers
  // k : the quadruple sum required
  vector<vector<int>> fourSum(vector<int> &a, int k) {
    vector<vector<int>> ans;
    int n = a.size();

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int left = j + 1, right = n - 1;
        int target = k - a[i] - a[j];

        while (left < right) {
          int sum = a[left] + a[right];
          // cout << sum << endl;
          if (sum < target)
            left++;
          else if (sum > target)
            right--;
          else {
            vector<int> quadruplet(4);
            quadruplet[0] = a[i];
            quadruplet[1] = a[j];
            quadruplet[2] = a[left];
            quadruplet[3] = a[right];

            ans.push_back(quadruplet);

            while (left < right && quadruplet[2] == a[left]) left++;
            while (left < right && quadruplet[3] == a[right]) right--;
          }
        }

        while (j + 1 < n && a[j + 1] == a[j]) ++j;
      }

      while (i + 1 < n && a[i + 1] == a[i]) ++i;
    }

    return ans;
  };