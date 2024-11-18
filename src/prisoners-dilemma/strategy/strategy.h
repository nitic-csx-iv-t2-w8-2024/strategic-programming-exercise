#ifndef PRISONERS_DILEMMA_STRATEGY_H
#define PRISONERS_DILEMMA_STRATEGY_H

extern int equalizer_zd_strategy(int self_id, int reward_table[2][2],
                                 int attempt, int overall_scores[2],
                                 int *trajectory);
extern int extortionate_zd_strategy(int self_id, int reward_table[2][2],
                                    int attempt, int overall_scores[2],
                                    int *trajectory);
extern int random_strategy(int self_id, int reward_table[2][2], int attempt,
                           int overall_scores[2], int *trajectory);

#endif
