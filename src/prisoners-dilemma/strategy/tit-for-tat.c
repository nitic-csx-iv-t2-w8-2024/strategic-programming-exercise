#include <stdlib.h>

#include "prisoners-dilemma/strategy/strategy.h"

int tit_for_tat_strategy(int self_id, int reward_table[2][2], int attempt,
                         int overall_scores[2], int *trajectory) {
  // NOTE: 未使用の引数を無視する
  (void)reward_table;
  (void)overall_scores;

  // NOTE: 初回は協力する
  if (attempt == 0) {
    return 0;
  }

  int opponent_last_action =
      *(trajectory + (2 * (attempt - 1)) + (self_id ^ 1));

  return opponent_last_action;
}
