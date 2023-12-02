/****************************************************************************
* Filename: slast.h
* Original Author: Faith E. Olusegun (propenster)
* File Creation Date: December 2nd, 2023
* Description: SLAST functions, definitions  - header
* LICENSE: MIT
*************************************************************************************/

#pragma once
#ifndef SLAST_H

#define SLAST_H

/// this could be customized
#define MATCH_SCORE 2
#define MISMATCH_SCORE -1
#define GAP_PENALTY -1

int max_of(int a, int b, int c);

int calculateScore(char a, char b);
void simpleLocalAlignment(char* seq1, char* seq2);



#endif //SLAST_H#pragma once
