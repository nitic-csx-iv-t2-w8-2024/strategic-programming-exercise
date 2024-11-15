#include <stdlib.h>

#include "prisoners-dilemma/strategy/strategy.h"

int prisoners_dilemma_generous_zd_strategy(int self_id, int attempt,
                                           int overall_scores[2],
                                           int *trajectory) {
  // NOTE: 未使用の引数を無視する
  (void)overall_scores;

  // NOTE: 寛容性 (0.0 - 1.0)
  double generosity = 0.25;
  // NOTE: 裏切りへの応答確率 (0.0 - 1.0)
  double punishment = 0.75;

  // NOTE: 初回は協力する
  if (attempt == 0) {
    return 0;
  }

  int opponent_last_action =
      *(trajectory + (2 * (attempt - 1)) + (self_id ^ 1));

  int action;
  if (opponent_last_action == 0) {
    // NOTE: 相手が協力していた場合の反応
    action = (rand() < generosity * RAND_MAX) ? 0 : 1;
  } else {
    // NOTE: 相手が裏切っていた場合の反応
    action = (rand() < punishment * RAND_MAX) ? 1 : 0;
  }

  return action;
}
