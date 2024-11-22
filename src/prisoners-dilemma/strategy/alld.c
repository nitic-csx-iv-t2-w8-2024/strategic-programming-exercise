#include <stdlib.h>

#include "prisoners-dilemma/strategy/strategy.h"

int all_d_strategy(int self_id, int reward_table[2][2], int attempt,
                   int overall_scores[2], int *trajectory) {
  // NOTE: 未使用の引数を無視する
  (void)self_id;
  (void)reward_table;
  (void)attempt;
  (void)overall_scores;
  (void)trajectory;

  int action = 1;

  return action;
}
