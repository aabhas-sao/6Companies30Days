#include <bits/stdc++.h>
using namespace std;

void helper(int open, int close, int n, string& s, vector<string>& ans) {
  if (open > n || close > n) return;
  if (close > open) return;

  if (open + close == 2 * n) {
    ans.push_back(s);
    return;
  }

  s += '(';
  helper(open + 1, close, n, s, ans);
  s.pop_back();

  s += ')';
  helper(open, close + 1, n, s, ans);
  s.pop_back();
}

vector<string> AllParenthesis(int n) {
  vector<string> ans;
  string s;
  helper(0, 0, n, s, ans);
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<string> ans = AllParenthesis(n);

  for (auto x : ans) {
    cout << x << endl;
  }
}