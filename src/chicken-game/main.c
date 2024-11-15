#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "chicken-game/strategy/strategy.h"

#define N 5            /* 車線を変えるチャンス数 */
#define OID (ID ^ 1)   /* 相手のid */
#define CLIENT_0 "ID0" /* 名前 */
#define CLIENT_1 "ID1"

/* 点数表 */
const int SCT[3][3] = {{0, -5, -10}, {10, -3, 10}, {-10, -5, 0}};

/* 関数プロトタイプ */
int play_0(int ID, int n, int *H); /* ID0の戦略 */
int play_1(int ID, int n, int *H); /* ID1の戦略 */

int main(void) {
  int j, k, n = N, rh[2];
  int *h;  // 過去の手
  int sc[2] = {0, 0};
  FILE *LOG;

  LOG = fopen("./log/log_tai.log", "w");
  if (!LOG) {
    perror("Failed to open log file");
    return EXIT_FAILURE;
  }

  setbuf(stderr, NULL);

  srand((unsigned int)19720117L);  // 乱数初期化

  // メモリ確保
  h = (int *)calloc(2 * N, sizeof(int));
  if (!h) {
    perror("Failed to allocate memory");
    fclose(LOG);
    return EXIT_FAILURE;
  }

  // メインループ
  for (j = 0; j < n; j++) {
    rh[0] = play_0(0, j, h);
    rh[1] = play_1(1, j, h);

    for (k = 0; k < 2; k++) {
      *(h + (2 * j) + k) = rh[k];
    }

    fprintf(LOG, "Turn %3d, h: %d %d, sc: %3d %3d\n", j + 1, *(h + (2 * j)),
            *(h + (2 * j) + 1), SCT[*(h + (2 * j)) + 1][*(h + (2 * j) + 1) + 1],
            SCT[*(h + (2 * j) + 1) + 1][*(h + (2 * j)) + 1]);
  }

  for (k = 0; k < 2; k++) {
    sc[k] = SCT[rh[k] + 1][rh[k ^ 1] + 1];
  }

  fprintf(LOG, "      %s : %s\n", CLIENT_0, CLIENT_1);
  fprintf(LOG, "score  %d : %d\n", sc[0], sc[1]);
  printf("      %s : %s\n", CLIENT_0, CLIENT_1);
  printf("score  %d : %d\n", sc[0], sc[1]);

  fprintf(stderr, "\n THE END\n");
  for (k = 0; k < 10; k++) printf(" %d ", h[k]);

  fclose(LOG);
  free(h);
  return 0;
}

/* ID0の戦略 */
int play_0(int ID, int n, int *H) {
  int t = chicken_game_debug_strategy(ID, n, H);

  return t;
}

/* ID1の戦略 */
int play_1(int ID, int n, int *H) {
  int t = chicken_game_random_strategy(ID, n, H);

  return t;
}
