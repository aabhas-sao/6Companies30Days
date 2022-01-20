#include <bits/stdc++.h>
using namespace std;

int minSteps(int D) {
  int x = 0;
  int i = 1;
  int steps = 0;

  while (x + i < D) {
    x += i;
    i++;
    steps++;
  }

  steps += 2 * D - i;

  return steps;
}