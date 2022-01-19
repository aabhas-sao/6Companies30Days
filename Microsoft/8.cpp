#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node* nextRight;
};

void connect(Node* root) {
  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    Node* curr = q.front();
    q.pop();
    if (!curr) {
      if (q.empty()) break;
      q.push(NULL);
      continue;
    }

    if (!q.empty() && q.front()) {
      curr->nextRight = q.front();
    }

    if (curr->left) {
      q.push(curr->left);
    }

    if (curr->right) {
      q.push(curr->right);
    }
  }
}