#include <stdlib.h>

#include "prisoners-dilemma/strategy/strategy.h"

#define TEST_PERIOD 10

int tullock_strategy(int self_id, int reward_table[2][2], int attempt,
                     int overall_scores[2], int *trajectory) {
  // NOTE: 未使用の引数を無視する
  (void)reward_table;
  (void)overall_scores;

  // NOTE: 最初のN回は常に協力する
  if (attempt < TEST_PERIOD) {
    return 0;
  }

  int opponent_cooperation_count = 0;
  for (int i = 0; i < 10; i++) {
    int opponent_action = *(trajectory + (2 * i) + (self_id ^ 1));
    if (opponent_action == 0) {
      opponent_cooperation_count++;
    }
  }

  double cooperation_probability =
      (opponent_cooperation_count / (double)TEST_PERIOD) - 0.1;
  if (cooperation_probability < 0.0) {
    cooperation_probability = 0.0;
  } else if (cooperation_probability > 1.0) {
    cooperation_probability = 1.0;
  }

  int action = ((double)rand() / RAND_MAX < cooperation_probability) ? 0 : 1;

  return action;
}
