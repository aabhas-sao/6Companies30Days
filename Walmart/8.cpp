class Solution {
 public:
  int sum(int n) { return n * (n + 1) / 2; }

  int height(int N) {
    int h = 1;

    while (sum(h + 1) <= N) {
      h++;
    }

    return h;
  }
};