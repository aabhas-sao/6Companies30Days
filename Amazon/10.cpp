#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void matchPairs(char nuts[], char bolts[], int n) {
    // ! # $ % & * @ ^ ~
    vector<char> c = {'!', '#', '$', '%', '&', '*', '@', '^', '~'};
    unordered_set<char> nutset;
    unordered_set<char> boltset;

    for (int i = 0; i < n; i++) {
      nutset.insert(nuts[i]);
    }

    for (int i = 0; i < n; i++) {
      boltset.insert(bolts[i]);
    }

    vector<char> ans;
    vector<char> nutRem;
    vector<char> boltRem;

    for (auto x : c) {
      if (nutset.find(x) != nutset.end() && boltset.find(x) != boltset.end()) {
        ans.push_back(x);
      }
    }

    int i = 0;

    for (; i < ans.size(); i++) {
      nuts[i] = ans[i];
      bolts[i] = ans[i];
    }
  }
};