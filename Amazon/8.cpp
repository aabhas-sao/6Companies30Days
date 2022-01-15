#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define iofile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define cases int t; cin >> t; while(t--)

long long countWays(int m) {
    long long ans =  m / 2 + 1LL;
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    iofile
#endif

    cases {
        int n; cin >> n;
        cout << countWays(n) << endl;
    }

    return 0;
}