#include <bits/stdc++.h>
using namespace std;

string encode(string src) {
  string ans = "";

  int i = 0;

  while (i < src.size()) {
    int cnt = 1;

    while (i + 1 < src.size() && src[i + 1] == src[i]) {
      cnt++;
      i++;
    }

    ans += src[i];
    ans += (cnt + '0');

    i++;
  }

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  string s;
  cin >> s;

  cout << encode(s) << endl;
}