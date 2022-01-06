#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string printMinNumberForPattern(string a) {
    set<int> s;
    for (int i = 1; i <= 9; i++) {
      s.insert(i);
    }

    int i = 0;
    int n = a.size();

    string ans = "";

    bool noI = true;

    for (int i = 0; i < a.size(); i++) {
      if (a[i] == 'D') {
        noI = false;
      }
    }

    while (i < n) {
      char f = a[i];
      int size = 1;

      bool picheD = false;
      if (i - 1 >= 0 && a[i - 1] == 'D') picheD = true;

      while (i + 1 < n && a[i + 1] == f) {
        i++;
        size++;
      }

      if (f == 'D') {
        size++;

        auto it = s.begin();

        for (int j = 0; j < size - 1; j++) {
          it++;
        }

        for (int j = 0; j < size; j++) {
          ans += (*it + '0');
          auto bt = it;
          it--;
          s.erase(bt);
        }
      } else {
        bool aageD = false;
        if (i + 1 < n && a[i + 1] == 'D') aageD = true;
        if (aageD && picheD) size--;
        if (noI) size++;
        auto it = s.begin();

        for (int j = 0; j < size; j++) {
          ans += (*it + '0');
          auto bt = it;
          it++;
          s.erase(bt);
        }
      }

      i++;
    }

    return ans;
  }
};