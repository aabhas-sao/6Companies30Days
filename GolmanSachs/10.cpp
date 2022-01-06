#include <bits/stdc++.h>
using namespace std;

void top10(vector<int> v) {
  priority_queue<int> pq;
  for (auto x : v) {
    pq.push(x);
    if (pq.size() > 10) {
      pq.pop();
    }
  }

  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }

  cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  top10(v);
}