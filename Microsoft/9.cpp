#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

int helper(Node* root, int X, int& count) {
  if (!root) return 0;

  int left = helper(root->left, X, count);
  int right = helper(root->right, X, count);

  if (root->data + left + right == X) count++;

  return root->data + left + right;
}

int countSubtreesWithSumX(Node* root, int X) {
  int count = 0;
  helper(root, X, count);
  return count;
}