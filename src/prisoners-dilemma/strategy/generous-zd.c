#include <stdlib.h>

#include "prisoners-dilemma/strategy/strategy.h"

int prisoners_dilemma_generous_zd_strategy(int ID, int n, int SC[2], int *H) {
  // NOTE: 未使用の引数を無視する
  (void)SC;

  // NOTE: 寛容性 (0.0 - 1.0)
  double generosity = 0.25;
  // NOTE: 裏切りへの応答確率 (0.0 - 1.0)
  double punishment = 0.75;

  // NOTE: 初回は協力する
  if (n == 0) {
    return 0;
  }

  int opponent_last_move = *(H + (2 * (n - 1)) + (ID ^ 1));

  int t;
  if (opponent_last_move == 0) {
    // NOTE: 相手が協力していた場合、主に協力する
    t = (rand() < generosity * RAND_MAX) ? 0 : 1;
  } else {
    // NOTE: 相手が裏切っていた場合、主に裏切る
    t = (rand() < punishment * RAND_MAX) ? 1 : 0;
  }

  return t;
}
