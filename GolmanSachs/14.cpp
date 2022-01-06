#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int> &nums) {
    deque<int> q;
    int sum = 0;
    int ms = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
      q.push_back(nums[i]);
      sum += nums[i];

      if (sum >= target) {
        while (sum >= target) {
          if (q.size() < ms) {
            ms = q.size();
          }

          sum -= q.front();
          q.pop_front();
        }
      }
    }

    if (ms == INT_MAX) return 0;
    return ms;
  }
};