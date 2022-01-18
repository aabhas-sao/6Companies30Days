#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
  TrieNode() { terminator = false; }
  char c;
  bool terminator;
  unordered_map<char, TrieNode*> children;
};

class Trie {
 public:
  TrieNode* root;

  Trie() {
    root = new TrieNode();
    root->terminator = false;
    root->c = '$';
  }

  void insert(string s) {
    TrieNode* temp = root;
    for (auto c : s) {
      if (temp->children.count(c) != 0) {
        temp = temp->children[c];
        continue;
      }
      TrieNode* t = new TrieNode;
      t->c = c;
      temp->children[c] = t;
      temp = temp->children[c];
    }

    temp->terminator = true;
  }

  void dfs(vector<string>& s, string& pre, TrieNode* root) {
    if (root->terminator) {
      s.push_back(pre);
      // cout << pre << endl;
    }

    for (auto x : root->children) {
      pre += x.first;
      dfs(s, pre, x.second);
      pre.pop_back();
    }
  }

  void rec(vector<vector<string>>& ans, int i, string s, TrieNode* root) {
    if (root->children.count(s[i]) != 0) {
      rec(ans, i + 1, s, root->children[s[i]]);
    } else {
      for (int j = i; j < s.size(); j++) {
        ans.push_back({"0"});
      }
    }

    if (i == 0) return;

    vector<string> v;
    string t = s.substr(0, i);
    dfs(v, t, root);
    sort(v.begin(), v.end());
    // cout << i << " " << root->c << endl;
    ans.push_back(v);
  }

  vector<vector<string>> prefix(string s) {
    TrieNode* temp = root;
    vector<vector<string>> ans;

    rec(ans, 0, s, temp);

    reverse(ans.begin(), ans.end());
    return ans;
  }
};

class Solution {
 public:
  vector<vector<string>> displayContacts(int n, string contact[], string s) {
    Trie t;
    for (int i = 0; i < n; i++) {
      t.insert(contact[i]);
    }
    return t.prefix(s);
  }
};