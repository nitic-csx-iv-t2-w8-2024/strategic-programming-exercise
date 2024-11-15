#include <stdlib.h>

#include "prisoners-dilemma/strategy/strategy.h"

int prisoners_dilemma_extortionate_zd_strategy(int ID, int n, int SC[2],
                                               int *H) {
  (void)SC;

  // 初回の手は協力
  if (n == 0) {
    return 0;
  }

  // 相手のIDを取得
  int opponent = 1 - ID;

  // 過去の最後の手を取得
  int last_opponent_move = H[2 * (n - 1) + opponent];
  // int last_own_move = H[2 * (n - 1) + ID];

  // 搾取係数chiを設定
  double chi = 1.5;  // 例として1.5を使用

  // 戦略のパラメータをchiに基づいて設定
  // ここでは単純化のため、chiに応じて協力の確率を調整
  double cooperation_prob;
  if (last_opponent_move == 0) {  // 相手が協力した場合
    // chiが大きいほど協力する傾向が強くなる
    cooperation_prob = 0.8 + 0.1 * chi;  // 例えば0.8 + 0.15 = 0.95
    if (cooperation_prob > 1.0) cooperation_prob = 1.0;
  } else {  // 相手が裏切った場合
    // chiが大きいほど裏切りを選びやすくなる
    cooperation_prob = 0.2 / chi;  // 例えば0.2 / 1.5 ≈ 0.133
  }

  // 確率に基づいて次の手を決定
  double rand_val = (double)rand() / RAND_MAX;
  if (rand_val < cooperation_prob) {
    return 0;  // 協力
  } else {
    return 1;  // 裏切り
  }
}
