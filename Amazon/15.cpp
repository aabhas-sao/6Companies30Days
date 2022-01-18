#include <iostream>
using namespace std;
/* A linked list node */

struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
 public:
  void linkdelete(struct Node *head, int m, int n) {
    Node *p = head;

    while (p) {
      for (int i = 1; i < m and p != NULL; i++) p = p->next;

      if (p == NULL) return;

      Node *t = p->next;

      for (int i = 1; i <= n and t != NULL; i++) {
        Node *temp = t;
        t = t->next;
        free(temp);
      }
      p->next = t;
      p = t;
    }
  }
};