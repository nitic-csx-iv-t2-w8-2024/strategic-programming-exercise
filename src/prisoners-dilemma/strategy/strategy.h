#ifndef PRISONERS_DILEMMA_STRATEGY_H
#define PRISONERS_DILEMMA_STRATEGY_H

extern int prisoners_dilemma_equalizer_zd_strategy(int self_id, int attempt,
                                                   int overall_scores[2],
                                                   int *trajectory);
extern int prisoners_dilemma_extortionate_zd_strategy(int self_id, int attempt,
                                                      int overall_scores[2],
                                                      int *trajectory);
extern int prisoners_dilemma_generous_zd_strategy(int self_id, int attempt,
                                                  int overall_scores[2],
                                                  int *trajectory);
extern int prisoners_dilemma_random_strategy(int self_id, int attempt,
                                             int overall_scores[2],
                                             int *trajectory);

#endif
