/****************************************************************************
* Filename: main.c
* Original Author: Faith E. Olusegun (propenster)
* File Creation Date: December 2nd, 2023
* Description: Entry to SLAST Dynamic programming-based sequence alignment algorithm
* LICENSE: MIT
*************************************************************************************/


#include <stdio.h>
#include "slast.h"

int main(int argc, char const* argv[])
{
    printf("Welcome to SLAST (Simple Local Alignment Search Tool in C\n");

    //char seq1[] = "ACGTACGT";
    char seq1[] = "ACTCCGAT";
    //char seq2[] = "AGTACGAC"; -> Output GCATG-A
    char seq2[] = "GCTAAGAT";

    printf("Sequence 1 to be aligned: %s\n", seq1);
    printf("Sequence 1 to be aligned: %s\n", seq2);

    printf("Alignment: \n");

    simpleLocalAlignment(seq1, seq2);

    return 0;
}
