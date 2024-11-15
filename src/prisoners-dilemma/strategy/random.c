#include <stdlib.h>

int prisoners_dilemma_random_strategy(int ID, int n, int SC[2], int *H) {
  // NOTE: Ignore unused arguments
  (void)n;
  (void)SC;
  (void)H;

  int t = 0;
  if (ID == 0) {
    t = rand() & 1;
  }
  if (ID == 1) {
    t = (rand() >> 1) & 1;
  }

  return t;
}
