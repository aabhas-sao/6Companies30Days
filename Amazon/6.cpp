#include <bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(int *arr, int n, int k) {
    deque<int> q;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (!q.empty() && i - k == q.front()) q.pop_front();

        while (!q.empty() && arr[i] >= arr[q.back()]) {
            q.pop_back();
        }

        q.push_back(i);

        if (i >= k - 1) ans.push_back(arr[q.front()]);
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> res = max_of_subarrays(arr, n, k);

    for (auto x : res) {
        cout << x << " ";
    }

    return 0;
}