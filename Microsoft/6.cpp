#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Function to find list of all words possible by pressing given numbers.
  vector<string> keypad = {"",    "",    "abc",  "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};

  void helper(int i, string& s, vector<string>& ans, int a[], int n) {
    // cout << i << " " << s << endl;
    if (i == n) {
      // cout << s << endl;
      ans.push_back(s);
      return;
    }

    for (int j = 0; j < keypad[a[i]].size(); j++) {
      s += keypad[a[i]][j];
      helper(i + 1, s, ans, a, n);
      s.pop_back();
    }
  }

  vector<string> possibleWords(int a[], int n) {
    vector<string> ans;
    string s;
    helper(0, s, ans, a, n);

    return ans;
  }
};