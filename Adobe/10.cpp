#include <bits/stdc++.h>
using namespace std;

vector<string> winner(string arr[], int n) {
  unordered_map<string, int> mp;
  string s;
  int cnt = INT_MIN;

  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;

    if (s.empty()) s = arr[i];

    if (mp[arr[i]] > cnt || (mp[arr[i]] == cnt && arr[i] <= s)) {
      cnt = mp[arr[i]];
      s = arr[i];
    }
  }

  vector<string> ans;
  ans.push_back(s);
  ans.push_back(to_string(cnt));

  return ans;
}