#include <bits/stdc++.h>
using namespace std;

string decToBin(int n) {
  string s;

  while (n) {
    s += (n & 1) ? '1' : '0';
    n = n >> 1;
  }

  reverse(s.begin(), s.end());
  return s;
}

vector<string> generate(int N) {
  vector<string> ans;

  for (int i = 1; i <= N; i++) {
    ans.push_back(decToBin(i));
  }

  return ans;
}