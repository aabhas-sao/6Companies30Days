#include <bits/stdc++.h>
using namespace std;

int longestMountain(vector<int>& arr) {
  int ans = 0, n = arr.size();
  int i = 1;

  while (i < n) {
    int increasing = 0;
    int decreasing = 0;

    while (i < n && arr[i] > arr[i - 1]) i++, increasing++;
    while (i < n && arr[i] < arr[i - 1]) i++, decreasing++;

    if (increasing && decreasing) {
      ans = max(ans, increasing + decreasing + 1);
    }

    while (i < n && arr[i - 1] == arr[i]) i++;
  }

  return ans;
}

int main() { return 0; }