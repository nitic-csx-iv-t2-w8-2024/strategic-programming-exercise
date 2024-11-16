#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include "prisoners-dilemma/strategy/strategy.h"
#include "util/log.h"

#define ATTEMPT_LIMIT 50

int player0_policy(int self_id, int attempt, int overall_scores[2],
                   int *trajectory);
int player1_policy(int self_id, int attempt, int overall_scores[2],
                   int *trajectory);

int main(void) {
  char log_file_path[64];
  sprintf(log_file_path, "./log/prisoners-dilemma-%ld.log", time(NULL));
  FILE *log_file = fopen(log_file_path, "w");

  // // NOTE: 時間依存の動的な乱数を生成するためのシード設定
  // srand((unsigned int)time(NULL));
  // NOTE: 定数依存の静的な乱数を生成するためのシード設定
  srand((unsigned int)19720117L);

  const int reward_table[2][2] = {{5, 0}, {10, 2}};
  int (*action_determiner[])(int, int, int[2], int *) = {player0_policy,
                                                         player1_policy};

  int overall_scores[2] = {0, 0};
  int *trajectory = (int *)calloc(2 * ATTEMPT_LIMIT, sizeof(int));
  if (trajectory == NULL) {
    log_error("Failed to allocate memory.");

    return EXIT_FAILURE;
  }

  for (int attempt = 0; attempt < ATTEMPT_LIMIT; attempt++) {
    int determined_actions[2];
    for (int i = 0; i < 2; i++) {
      determined_actions[i] =
          (*action_determiner[i])(i, attempt, overall_scores, trajectory);
    }
    for (int i = 0; i < 2; i++) {
      *(trajectory + (2 * attempt) + i) = determined_actions[i];
      overall_scores[i] +=
          reward_table[determined_actions[i]][determined_actions[i ^ 1]];
    }

    fprintf(
        log_file,
        "turn %3d, action: %d %d, reward: %3d %3d, overall score: %3d %3d\n",
        attempt + 1, *(trajectory + (2 * attempt)),
        *(trajectory + (2 * attempt) + 1),
        reward_table[*(trajectory + (2 * attempt))]
                    [*(trajectory + (2 * attempt) + 1)],
        reward_table[*(trajectory + (2 * attempt) + 1)]
                    [*(trajectory + (2 * attempt))],
        overall_scores[0], overall_scores[1]);
  }

  free(trajectory);

  fprintf(log_file, "\n");
  fprintf(log_file, "Player1 Overall Score: %d\n", overall_scores[0]);
  fprintf(log_file, "Player2 Overall Score: %d\n", overall_scores[1]);
  fprintf(log_file, "Sum of Overall Scores: %d\n",
          overall_scores[0] + overall_scores[1]);

  fclose(log_file);

  log_info("Player1 Overall Score: %d", overall_scores[0]);
  log_info("Player2 Overall Score: %d", overall_scores[1]);
  log_info("Sum of Overall Scores: %d", overall_scores[0] + overall_scores[1]);

  return EXIT_SUCCESS;
}

int player0_policy(int self_id, int attempt, int overall_scores[2],
                   int *trajectory) {
  int action = prisoners_dilemma_random_strategy(self_id, attempt,
                                                 overall_scores, trajectory);

  return action;
}

int player1_policy(int self_id, int attempt, int overall_scores[2],
                   int *trajectory) {
  int action = prisoners_dilemma_random_strategy(self_id, attempt,
                                                 overall_scores, trajectory);

  return action;
}
