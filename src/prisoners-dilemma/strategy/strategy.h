#ifndef PRISONERS_DILEMMA_STRATEGY_H
#define PRISONERS_DILEMMA_STRATEGY_H

extern int all_c_strategy(int self_id, int reward_table[2][2], int attempt,
                          int overall_scores[2], int *trajectory);
extern int all_d_strategy(int self_id, int reward_table[2][2], int attempt,
                          int overall_scores[2], int *trajectory);
extern int equalizer_zd_strategy(int self_id, int reward_table[2][2],
                                 int attempt, int overall_scores[2],
                                 int *trajectory);
extern int extortionate_zd_strategy(int self_id, int reward_table[2][2],
                                    int attempt, int overall_scores[2],
                                    int *trajectory);
extern int random_strategy(int self_id, int reward_table[2][2], int attempt,
                           int overall_scores[2], int *trajectory);
extern int grim_trigger_strategy(int self_id, int reward_table[2][2],
                                 int attempt, int overall_scores[2],
                                 int *trajectory);
extern int tit_for_tat_strategy(int self_id, int reward_table[2][2],
                                int attempt, int overall_scores[2],
                                int *trajectory);
extern int tullock_strategy(int self_id, int reward_table[2][2], int attempt,
                            int overall_scores[2], int *trajectory);

#endif
