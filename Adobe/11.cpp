#include <bits/stdc++.h>
using namespace std;

string amendSentence(string s) {
  string ans = "";
  s += 'A';
  int j = 0, n = s.size();

  for (int i = 1; i < n; i++) {
    if (isupper(s[i])) {
      char c = tolower(s[j]);
      ans += c + s.substr(j + 1, i - j - 1) + ' ';
      j = i;
    }
  }

  ans.pop_back();
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << amendSentence(s) << endl;
  return 0;
}