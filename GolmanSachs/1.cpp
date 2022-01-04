#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> anagrams(vector<string>& words) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;

    for (auto x: words) {
        string s = x;
        sort(s.begin(), s.end());
        mp[s].push_back(x);
    }


    for (auto x: mp) {
        vector<string> v;
        for (auto z: x.second) {
            v.push_back(z);
        }
        ans.push_back(v);
    }

    return ans;
}

int main() {
    int n; cin >> n;
    vector<string> words;
    
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        words.push_back(t);
    }

    vector<vector<string>> s = anagrams(words);
    for (auto x: s) {
        for(auto z: x) {
            cout << z << " ";
        }
        cout << endl;
    }
}