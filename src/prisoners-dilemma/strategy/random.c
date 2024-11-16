#include <stdlib.h>

#include "prisoners-dilemma/strategy/strategy.h"

int prisoners_dilemma_random_strategy(int self_id, int attempt,
                                      int overall_scores[2], int *trajectory) {
  // NOTE: 未使用の引数を無視する
  (void)self_id;
  (void)attempt;
  (void)overall_scores;
  (void)trajectory;

  int action = rand() & 1;

  return action;
}
