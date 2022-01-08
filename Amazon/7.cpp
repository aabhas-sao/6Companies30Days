#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A) {
    int hash[26] = {0};
    deque<char> q;
    string ans;

    for (int i = 0; i < A.size(); i++) {
        int idx = A[i] - 'a';

        if (hash[idx] == 0) {
            hash[idx] = 1;
            q.push_back(A[i]);
        } else {
            hash[idx] = 2;
        }

        while (!q.empty() && hash[q.front() - 'a'] == 2) {
            q.pop_front();
        }

        if (q.empty()) {
            ans += '#';
        } else {
            ans += q.front();
        }
    }

    return ans;
}