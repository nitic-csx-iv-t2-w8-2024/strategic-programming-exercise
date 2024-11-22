#include <stdlib.h>

#include "prisoners-dilemma/strategy/strategy.h"

int grim_trigger_strategy(int self_id, int reward_table[2][2], int attempt,
                          int overall_scores[2], int *trajectory) {
  // NOTE: 未使用の引数を無視する
  (void)reward_table;
  (void)overall_scores;

  // NOTE: 初回は協力する
  if (attempt == 0) {
    return 0;
  }

  for (int i = 0; i < attempt; i++) {
    int opponent_action = *(trajectory + (2 * i) + (self_id ^ 1));
    if (opponent_action == 1) {
      return 1;
    }
  }

  return 0;
}
