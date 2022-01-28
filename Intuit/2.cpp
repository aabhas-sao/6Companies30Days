#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> DIR = {0, 1, 0, -1, 0};

  bool valid(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
  }

  bool search(int i, int j, int k, vector<vector<char>>& board, string& word,
              vector<vector<bool>>& vis) {
    if (k >= word.size()) {
      return true;
    }

    bool found = false;
    // cout << board[i][j] << endl;
    vis[i][j] = true;

    for (int p = 0; p < 4; p++) {
      int x = i + DIR[p];
      int y = j + DIR[p + 1];

      if (valid(x, y, board.size(), board[0].size()) && !vis[x][y] &&
          board[x][y] == word[k]) {
        found = found || search(x, y, k + 1, board, word, vis);
      }
    }

    vis[i][j] = false;

    return found;
  }

  bool isWordExist(vector<vector<char>>& board, string word) {
    int n = board.size(), m = board[0].size();
    bool found = false;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == word[0]) {
          found = found || search(i, j, 1, board, word, vis);
        }
      }
    }

    return found;
  }
};