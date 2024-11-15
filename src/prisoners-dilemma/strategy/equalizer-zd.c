#include <stdlib.h>

#include "prisoners-dilemma/strategy/strategy.h"

int prisoners_dilemma_equalizer_zd_strategy(int ID, int n, int SC[2], int *H) {
  // NOTE: 未使用の引数を無視する
  (void)SC;

  // NOTE: 固定する相手のペイオフ (0.0 - 10.0)
  double target_payoff = 5.0;
  // NOTE: 協力確率の基準 (0.0 - 1.0)
  double base_cooperation_probability = 0.5;

  // NOTE: 初回は協力する
  if (n == 0) {
    return 0;
  }

  int opponent_last_move = *(H + (2 * (n - 1)) + (ID ^ 1));

  double response_probability;
  if (opponent_last_move == 0) {
    // NOTE: 相手が協力していた場合の反応
    response_probability =
        base_cooperation_probability +
        (target_payoff / 10.0) * (1.0 - base_cooperation_probability);
  } else {
    // NOTE: 相手が裏切っていた場合の反応
    response_probability =
        base_cooperation_probability * (1.0 - target_payoff / 10.0);
  }

  int t = (rand() < response_probability * RAND_MAX) ? 0 : 1;

  return t;
}
