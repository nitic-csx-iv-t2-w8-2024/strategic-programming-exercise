#include <stdlib.h>

#include "prisoners-dilemma/strategy/strategy.h"

int extortionate_zd_strategy(int self_id, int reward_table[2][2], int attempt,
                             int overall_scores[2], int *trajectory) {
  // NOTE: 未使用の引数を無視する
  (void)overall_scores;

  // NOTE: 初回は協力する
  if (attempt == 0) {
    return 0;
  }

  // NOTE: 搾取係数
  // (1 <= chi)
  double chi = 2.0;
  // NOTE: スケーリングパラメータ
  // (0 < phi <= (P - S) / ((P - S) + chi * (T - P)))
  double phi = 0.1;

  int T = reward_table[1][0];
  int R = reward_table[0][0];
  int P = reward_table[1][1];
  int S = reward_table[0][1];

  int self_last_action = *(trajectory + (2 * (attempt - 1)) + self_id);
  int opponent_last_action =
      *(trajectory + (2 * (attempt - 1)) + (self_id ^ 1));

  double p1 = 1 - phi * (chi - 1) * (R - P) / (P - S);
  double p2 = 1 - phi * (1 + chi * (T - P) / (P - S));
  double p3 = phi * (chi + (T - P) / (P - S));
  double p4 = 0.0;

  double cooperation_probability[2][2] = {{p1, p2}, {p3, p4}};

  int action = ((double)rand() / RAND_MAX <
                cooperation_probability[self_last_action][opponent_last_action])
                   ? 0
                   : 1;

  return action;
}
