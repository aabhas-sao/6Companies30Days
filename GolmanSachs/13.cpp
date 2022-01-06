#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string decodedString(string s) {
    stack<pair<int, string>> st;
    st.push({1, ""});

    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= '1' && s[i] <= '9') {
        string tt;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
          tt += s[i];
          i++;
        }
        int dig = stoi(tt);
        st.push({dig, ""});

      } else if (s[i] == '[') {
        continue;
      } else if (s[i] == ']') {
        int times = st.top().first;
        string top = st.top().second;
        st.pop();
        for (int j = 0; j < times; j++) {
          st.top().second += top;
        }
      } else {
        st.top().second += s[i];
      }
    }

    return st.top().second;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  string a;
  cin >> a;
  Solution s;
  cout << s.decodedString(a) << endl;
  return 0;
}