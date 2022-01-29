#include <bits/stdc++.h>
using namespace std;

void nextPermutation(string& s) {
  int n = s.size(), i = n - 1;
  if (n == 0) return;

  while (i >= 1 && s[i - 1] >= s[i]) i--;
  i--;

  if (i == -1)
    reverse(s.begin(), s.end());
  else {
    int j = n - 1;
    while (s[j] <= s[i]) j--;
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
  }

  //   cout << s << endl;
}

string nextPalin(string s) {
  int mid = s.size() / 2;

  string s1 = s.substr(0, mid);
  nextPermutation(s);

  string s2 = s1;
  reverse(s1.begin(), s1.end());

  if (s.size() & 1) s2 += s.substr(mid, 1);

  string ans = s2 + s1;

  if (ans <= s) return "-1";

  return ans;
}

int main() {}