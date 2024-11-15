#include <stdlib.h>

#include "prisoners-dilemma/strategy/strategy.h"

int prisoners_dilemma_equalizer_zd_strategy(int self_id, int attempt,
                                            int overall_scores[2],
                                            int *trajectory) {
  // NOTE: 未使用の引数を無視する
  (void)overall_scores;

  // NOTE: 固定する相手のペイオフ (0.0 - 10.0)
  double target_payoff = 5.0;
  // NOTE: 協力確率の基準 (0.0 - 1.0)
  double base_cooperation_probability = 0.5;

  // NOTE: 初回は協力する
  if (attempt == 0) {
    return 0;
  }

  int opponent_last_action =
      *(trajectory + (2 * (attempt - 1)) + (self_id ^ 1));

  double response_probability;
  if (opponent_last_action == 0) {
    // NOTE: 相手が協力していた場合の反応
    response_probability =
        base_cooperation_probability +
        (target_payoff / 10.0) * (1.0 - base_cooperation_probability);
  } else {
    // NOTE: 相手が裏切っていた場合の反応
    response_probability =
        base_cooperation_probability * (1.0 - target_payoff / 10.0);
  }

  int action = (rand() < response_probability * RAND_MAX) ? 0 : 1;

  return action;
}
