#include <bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(vector<int> a, int n, int k) {
    deque<int> q;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (!q.empty() && i - k == q.front()) q.pop_front();

        while (!q.empty() && a[q.back()] <= a[i]) {
            q.pop_back();
        }

        q.push_back(i);

        if (i >= k - 1) {
            ans.push_back(a[q.front()]);
        }
    }

    return ans;
}

int main() {
    return 0;
}