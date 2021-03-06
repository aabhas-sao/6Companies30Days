#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lis(vector<int>& v) {
    vector<int> res;
    if (v.size() > 0) res.push_back(v[0]);
    for (int i = 1; i < v.size(); i++) {
      if (v[i] > res.back()) {
        res.push_back(v[i]);
      } else {
        int id = lower_bound(res.begin(), res.end(), v[i]) - res.begin();
        res[id] = v[i];
      }
    }

    return res.size();
  }

  int minInsAndDel(int A[], int B[], int N, int M) {
    // code here
    vector<int> v;
    for (int i = 0; i < N; i++) {
      if (binary_search(B, B + M, A[i])) {
        v.push_back(A[i]);
      }
    }

    return N + M - 2 * lis(v);
  }
};