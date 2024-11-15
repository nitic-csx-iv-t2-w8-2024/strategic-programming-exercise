#include <stdlib.h>

#include "chicken-game/strategy/strategy.h"

int chicken_game_random_strategy(int ID, int n, int *H) {
  // NOTE: Ignore unused arguments
  (void)ID;
  (void)n;
  (void)H;

  int t;

  t = rand() % 3; /* tは０から２ */
  switch (t) {
    case 0:
      return -1;
      break;
    case 1:
      return 0;
      break;
    case 2:
      return 1;
      break;
    default:
      return 0;
      break;
  }
}
