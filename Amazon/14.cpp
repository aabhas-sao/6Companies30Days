#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node(int d) { this->data = d; }
  int data;
  Node* left;
  Node* right;
};

class Solution {
 public:
  void levelOrder(Node* root, unordered_map<int, Node*>& parent) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      Node* curr = q.front();
      q.pop();

      if (curr->left) {
        parent[curr->left->data] = curr;
        q.push(curr->left);
      }

      if (curr->right) {
        parent[curr->right->data] = curr;
        q.push(curr->right);
      }
    }
  }

  void find(Node** targetRef, bool& found, Node* root, int target) {
    if (!root) return;
    if (root->data == target) {
      *targetRef = root;
      found = true;
      return;
    }

    if (found) return;

    find(targetRef, found, root->left, target);
    find(targetRef, found, root->right, target);
  }

  int minTime(Node* root, int target) {
    unordered_map<int, Node*> parent;
    levelOrder(root, parent);

    queue<Node*> q;
    int time = 0;
    Node* node = new Node(-1);
    Node** targetRef = &node;
    bool found = false;
    find(targetRef, found, root, target);

    q.push(*targetRef);
    q.push(NULL);

    unordered_set<int> burned;
    burned.insert((*targetRef)->data);

    while (!q.empty()) {
      Node* curr = q.front();

      q.pop();

      if (curr == NULL) {
        if (q.empty()) {
          break;
        } else {
          time++;
          q.push(NULL);
          continue;
        }
      }

      if (curr->left != NULL && burned.find(curr->left->data) == burned.end()) {
        q.push(curr->left);
        burned.insert(curr->left->data);
      }
      if (curr->right != NULL &&
          burned.find(curr->right->data) == burned.end()) {
        q.push(curr->right);
        burned.insert(curr->right->data);
      }

      if (parent[curr->data] &&
          burned.find(parent[curr->data]->data) == burned.end()) {
        q.push(parent[curr->data]);
        burned.insert(parent[curr->data]->data);
      }
    }

    return time;
  }
};