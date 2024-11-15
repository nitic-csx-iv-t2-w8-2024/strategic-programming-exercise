#include <stdio.h>

#include "chicken-game/strategy/strategy.h"

int chicken_game_debug_strategy(int ID, int n, int *H) {
  int t, i;

  /* 過去の状態を見る */
  if (H != NULL) {  // HがNULLでない場合のみ処理する
    for (i = 0; i < n; i++) {
      printf("H[%d]: %d\n", 2 * i + ID, H[2 * i + ID]);
    }
  }

  /* -1,0,1で入力 */
  do {
    printf("Input ID %d Turn %d: ", ID, n);
    if (scanf("%d", &t) != 1) {  // scanfの戻り値を確認する
      printf("Invalid input. Please try again.\n");
      while (getchar() != '\n')  // 入力バッファをクリア
        ;
      continue;
    }
  } while ((t < -1) || (t > 1));

  return t;
}
