#include <bits/stdc++.h>
using namespace std;

string comp(string a, string b) {
  vector<string> x;
  vector<string> y;

  int s1 = 0, s2 = 0, e1 = a.size(), e2 = b.size();

  e1 = a.find('.');
  e2 = b.find('.');

  while (e1 != -1 && e2 != -1) {
    string p = a.substr(s1, e1 - s1);
    string q = b.substr(s2, e2 - s2);
    int digA = stoi(p);
    int digB = stoi(q);

    if (digA != digB) {
      return digA < digB ? b : a;
    }
    s1 = e1 + 1;
    s2 = e2 + 1;
    e1 = a.find('.', s1);
    e2 = b.find('.', s2);
  }

  return stoi(a) < stoi(b) ? b : a;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  string a, b;
  cin >> a >> b;
  cout << comp(a, b);
  return 0;
}