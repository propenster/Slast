#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slast.h"

/// @brief 
/// @param a - 
/// @param b 
/// @param c 
/// @return 
///
int max_of(int a, int b, int c) {
    int max_of_ab = (a > b) ? a : b;
    return (max_of_ab > c) ? max_of_ab : c;
}

/// @brief calculates match/alignment Score
/// @param a first nucleotide (a) to be compared to another (b)
/// @param b second nucleotide (b) to be compared with a
/// @return match or mismatch score
int calculateScore(char a, char b) {
    return (a == b) ? MATCH_SCORE : MISMATCH_SCORE;
}

/// @brief performs the local alignment
/// @param seq1 sequence 1
/// @param seq2 sequence 2 or reference sequence
void simpleLocalAlignment(char* seq1, char* seq2) {
    size_t len1 = strlen(seq1);
    size_t len2 = strlen(seq2);
    //create our dp matrix and allocate memory for it...
    //we will use it to store scores as we compute
    int** dp = (int**)malloc((len1 + 1) * sizeof(int*));
    for (size_t i = 0; i < len1; ++i) {
        dp[i] = (int*)malloc((len2 + 1) * sizeof(int));
    }

    int maxScore = 0;
    int endRow, endCol = 0;

    //init alignment matrix
    for (size_t row = 0; row < len1; ++row) {
        for (size_t col = 0; col < len2; ++col) {
            if (row == 0 || col == 0) {
                
                if (row <= len1 && col <= len2) {
                    dp[row][col] = 0;
                }
                else {
                    return 1;
                }
            }
            else {
                int match = dp[row - 1][col - 1] + calculateScore(seq1[row - 1], seq2[col - 1]);
                int delete = dp[row - 1][col] + GAP_PENALTY;
                int insert = dp[row][col - 1] + GAP_PENALTY;
                dp[row][col] = max(match, delete, insert);

                if (dp[row][col] > maxScore) {
                    maxScore = dp[row][col];
                    endRow = row;
                    endCol = col;
                }
            }
        }
    }

    //find && print new alignment
    int i = endRow;
    int j = endCol;
    while (i > 0 && j > 0 && dp[i][j] != 0) {
        int score = dp[i][j];
        int diagonal = dp[i - 1][j - 1];
        int left = dp[i][j - 1];
        int up = dp[i - 1][j];

        if (score == diagonal + calculateScore(seq1[i - 1], seq2[j - 1])) {
            printf("%c", seq1[i - 1]);
            i--;
            j--;
        }
        else if (score == up + GAP_PENALTY) {
            printf("-"); //
            i--;
        }
        else {
            printf("-");
            j--;
        }

    }

    //free
    for (size_t i = 0; i < len1; ++i) {
        free(dp[i]);
    }

    free(dp);


}

