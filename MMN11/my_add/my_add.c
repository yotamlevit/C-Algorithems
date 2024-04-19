/*
 Created by Yotam Levit on 24/03/2024.
*/
#include <stdio.h>
#include <stdlib.h>

#define BYTE_SIZE 8

/*
 This function make a *simple* binary addition.
 The binary addition is when you combine the 2 right
 bits and checks if there is a carry.

 The function iterates over all the bits using a for loop.
 To isolate the bit from the numbers function uses shifting.

 param a: (unsigned int) the first number for the addition
 param b: (unsigned int) the second number for the addition

 @return: (unsigned int) The sum of the two numbers
*/
unsigned int my_add(unsigned int a, unsigned int b)
{
    unsigned int sum = 0, carry = 0, result = 0, bitA, bitB, i;

    for (i = 0; i < sizeof(unsigned int) * BYTE_SIZE;i++) {
        bitA = (a >> i) & 1;
        bitB = (b >> i) & 1;

        /* Calculate the sum of bits and carry */
        sum = bitA ^ bitB  ^ carry;

        /* Update the result with the sum at the current bit position */
        result |= (sum << i);

        /* Calculate the new carry */
        carry = (bitA & bitB) | (bitA & carry) | (bitB & carry);
    }

    return result;
}


/*
 Converts a decimal number to its binary representation as a string.

 This function converts an unsigned integer into a binary string representation.
 It begins by checking each bit from the most significant to the least significant by right shifting.
 It skips leading zeros unless the number is zero, in which case it returns "0".

 param n: (unsigned int) the number to convert to binary

 return: (char*) A pointer to the dynamically allocated string representing
         the binary form of 'n'. Returns NULL if memory allocation fails.
*/
char* toBinaryString(unsigned int n) {
    unsigned int mask = 1 << (sizeof(unsigned int) * BYTE_SIZE -1);
    char* binaryStr = malloc(sizeof(unsigned int) * BYTE_SIZE + 1);
    int index = 0;
    int started = 0;

    /* Return NULL if memory allocation fails */
    if (!binaryStr) return NULL;

    for (; mask; mask >>= 1) {
        if (n & mask) {
            binaryStr[index++] = '1';
            started = 1;
        } else if (started) {
            binaryStr[index++] = '0';
        }
    }

    if (!started)
        binaryStr[index++] = '0';

    binaryStr[index] = '\0';
    return binaryStr;
}

int main()
{
    unsigned int num1, num2, sum;
    char* strNum1, *strNum2, *strSum;

    /* Prompt user for input */
    printf("Enter two integers (example: '11 22'):");

    /* Read two integers */
    scanf(" %u %u", &num1, &num2);

    printf("Num1: %u, num2: %u", num1, num2);

    strNum1 = toBinaryString(num1);
    strNum2 = toBinaryString(num2);
    printf("\n(In Binary) Num1: %s, num2: %s", strNum1, strNum2);

    /* Calculate the sum */
    sum = my_add(num1, num2);

    /* Print the sum */
    printf("\nThe binary addition: %u + %u =  %u", num1, num2, sum);

    strSum = toBinaryString(sum);
    printf("\n(In Binary) The binary addition: %s + %s =  %s\n", strNum1, strNum2, strSum);

    free(strNum1);
    free(strNum2);
    free(strSum);
    return 0;
}

