//
// Created by Yotam Levit on 24/03/2024.
//
#include "stdio.h"

#define BYTE_SIZE 8

/*
 * This function make a *simple* binary addition.
 * The binary addition is when you combine the 2 right
 * bits and checks if there is a carry.
 *
 * The function iterates over all the bits using a for loop.
 * To isolate the bit from the numbers function uses shifting.
 *
 * param a: (unsigned int) the first number for the addition
 * param b: (unsigned int) the second number for the addition
 *
 * @return: (unsigned int) The sum of the two numbers
 */
unsigned int my_add(unsigned int a, unsigned int b)
{
    unsigned int sum = 0, carry = 0, result = 0, bitA, bitB, i;

    for (i = 0; i < sizeof(int) * BYTE_SIZE;i++) {
        bitA = (a >> i) & 1;
        bitB = (b >> i) & 1;

        // Calculate the sum of bits and carry
        sum = bitA ^ bitB  ^ carry;

        // Update the result with the sum at the current bit position
        result |= (sum << i);

        // Calculate the new carry
        carry = (bitA & bitB) | (bitA & carry) | (bitB & carry);
    }

    return result;
}

int main()
{
    unsigned int num1, num2, sum;

    // Prompt user for input
    printf("Enter two integers (example: '11 22'): ");

    // Read two integers
    scanf("%u %u", &num1, &num2);

    printf("Num1: %u, num2: %u", num1, num2);
    // Calculate the sum
    sum = my_add(num1, num2);

    // Print the sum
    printf("\nThe binary addition: %u + %u =  %u\n", num1, num2, sum);

    return 0;
}

