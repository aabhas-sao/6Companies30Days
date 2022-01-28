#include <bits/stdc++.h>
using namespace std;

int diff(string& a, string& b) {
  //  1000 998
  // 10 9
  // 10 8
  // 150 149
  int i = a.size(), j = b.size();
}

string helper(const string& s, int x) {
  int n = s.size();
  int digitSize = x;
  int skip = n % x == 0 ? 0 : ceil(n / (x * 1.0));

  int i = 0;
  int step;

  vector<string> v;

  while (i < n) {
    string p;
    int len;

    if (skip) {
      len = digitSize - 1;
      skip--;
    } else {
      len = digitSize;
    }

    p = s.substr(i, len);
    v.push_back(p);
    i += len;
  }

  for (auto x : v) cout << x << " ";
  cout << endl;
  cout << v.size() << endl;

  int temp = 0;
  int idx = -1;
  for (int i = 0; i < v.size() - 1; i++) {
    int c = diff(v[i], v[i + 1]);
    if (c == 2) {
      if (idx != -1) return "-1";
      idx = i;
    } else if (c == -1) {
      return "-1";
    }
    cout << "diff: " << diff(v[i], v[i + 1]) << endl;
    temp += diff(v[i], v[i + 1]);
  }

  // cout << temp << endl;
  if (temp != v.size()) {
    return "-1";
  }

  return v[idx];
}

int missingNumber(const string& s) {
  for (int x = 1; x < 6; x++) {
    string local = helper(s, x);
    cout << x << " : " << local << endl;
    if (local != "-1") {
      return stoi(local) + 1;
    }
  }
  return -1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  string s;
  cin >> s;
  cout << missingNumber(s) << endl;
  return 0;
}