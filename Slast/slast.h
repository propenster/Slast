#pragma once
#ifndef SLAST_H

#define SLAST_H

#define MATCH_SCORE 2
#define MISMATCH_SCORE -1
#define GAP_PENALTY -1

int max_of(int a, int b, int c);

int calculateScore(char a, char b);
void simpleLocalAlignment(char* seq1, char* seq2);



#endif //SLAST_H#pragma once
