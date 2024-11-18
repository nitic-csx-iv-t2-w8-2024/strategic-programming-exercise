#include <stdlib.h>

#include "prisoners-dilemma/strategy/strategy.h"

int equalizer_zd_strategy(int self_id, int reward_table[2][2], int attempt,
                          int overall_scores[2], int *trajectory) {
  // NOTE: 未使用の引数を無視する
  (void)overall_scores;

  // NOTE: 初回は協力する
  if (attempt == 0) {
    return 0;
  }

  int T = reward_table[1][0];
  int R = reward_table[0][0];
  int P = reward_table[1][1];
  int S = reward_table[0][1];

  // NOTE: 相手の期待利得 s_Y を 3.5 に設定する場合
  double p1 = 2.0 / 3.0;
  double p4 = 1.0 / 3.0;
  double p2 = (p1 * (T - P) - (1 + p4) * (T - R)) / (R - P);
  double p3 = ((1 - p1) * (P - S) + p4 * (R - S)) / (R - P);

  double cooperation_probability[2][2] = {{p1, p2}, {p3, p4}};

  int self_last_action = *(trajectory + (2 * (attempt - 1)) + self_id);
  int opponent_last_action =
      *(trajectory + (2 * (attempt - 1)) + (self_id ^ 1));

  int action = ((double)rand() / RAND_MAX <
                cooperation_probability[self_last_action][opponent_last_action])
                   ? 0
                   : 1;

  return action;
}
