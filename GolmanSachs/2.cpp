#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> point;

class Solution {
 public:
  int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
    if (L2[0] > R1[0] || R2[1] > L1[1] || R2[0] < L1[0] || L2[1] < R1[1]) {
      return 0;
    }
    return 1;
  }
};

int main() {
  int L1[2];
  int L2[2];
  int R1[2];
  int R2[2];

  cin >> L1[0] >> L1[1];
  cin >> R1[0] >> R1[1];
  cin >> L2[0] >> L2[1];
  cin >> R2[0] >> R2[1];

  Solution s;

  if (s.doOverlap(L1, R1, L2, R2)) {
    cout << "The rectangles overlap." << endl;
  } else {
    cout << "The rectangles do not overlap." << endl;
  }
}