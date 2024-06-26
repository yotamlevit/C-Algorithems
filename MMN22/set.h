/*
  Created by Yotam Levit on 25/04/2024.
*/

#ifndef C_ALGORITHEMS_SET_H
#define C_ALGORITHEMS_SET_H

#define BYTE_SIZE 8
#define END_OF_LIST (-1)
#define MAX_NUMBER 128
#define MIN_NUMBER 0
#define ARRAY_DATA_SIZE 16

#define SINGLE_DIGIT_NUMBERS 10
#define DOUBLE_DIGIT_NUMBERS MAX_NUMBER - SINGLE_DIGIT_NUMBERS - (MAX_NUMBER - 100)
#define TRIPLE_DIGIT_NUMBER MAX_NUMBER - 99


typedef struct set
{
    unsigned char setData[ARRAY_DATA_SIZE]; /* 16 byte array that represents the set of numbers [0-127].
                                            * Each bit represents a number. */
} Set, * SetPtr;


/* Function Headers */
SetPtr initSet();
int printSet(SetPtr set, char** setStr);
int readSet(SetPtr set, int* numbers);
int unionSet(SetPtr setA, SetPtr setB, SetPtr outputSet);
int intersectSet(SetPtr setA, SetPtr setB, SetPtr outputSet);
int subSet(SetPtr originalSet, SetPtr subSet, SetPtr outputSet);
int symDiffSet(SetPtr setA, SetPtr setB, SetPtr outputSet);

#endif /* C_ALGORITHEMS_SET_H */
