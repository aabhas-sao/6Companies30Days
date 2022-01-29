#include <bits/stdc++.h>
using namespace std;

int diff(string a, string b) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int i = 0, j = 0;
  int x = a.size(), y = b.size();
  int diff = 0, carry = 0;

  while (i < x && j < y) {
    int digB = (b[j] - '0');
    int digA = (a[i] - '0');

    digA += carry;
    int localDiff;

    if (digB < digA) {
      localDiff = ((digB + 10) - (digA + carry));
      carry = 1;
    } else {
      localDiff = (digB - digA);
    }

    if (i > 0 && localDiff != 0) return -1;
    diff += localDiff;
    if (abs(diff) > 2) {
      return -1;
    }
    i++;
    j++;
  }

  return diff;
}

string helper(const string& s, int x, int skip) {
  int n = s.size();
  int digitSize = x;

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
    cout << i << " "
         << "diff: " << diff(v[i], v[i + 1]) << endl;
    if (c == 2) {
      if (idx != -1) return "-1";
      cout << c << endl;
      idx = i;
    } else if (c == -1) {
      return "-1";
    }

    temp += diff(v[i], v[i + 1]);
  }

  cout << temp << endl;
  if (temp != v.size()) {
    return "-1";
  }

  return v[idx];
}

int missingNumber(const string& s) {
  for (int x = 1; x < 6; x++) {
    for (int skip = 1; skip < x; skip++) {
      string local = helper(s, x, skip);
      cout << x << " : " << local << endl;
      if (local != "-1") {
        return stoi(local) + 1;
      }
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
  string a = "38";
  string b = "40";

  cout << diff(a, b) << endl;
  cout << missingNumber(s) << endl;
  return 0;
}