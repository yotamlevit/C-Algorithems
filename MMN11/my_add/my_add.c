//
// Created by Yotam Levit on 24/03/2024.
//
#include "stdio.h"

#define BYTE_SIZE 8
#define SHIFT_RIGHT(a, c) a >> c
#define SHIFT_LEFT(a, c) a << c

unsigned int my_add(unsigned int a, unsigned int b)
{
    unsigned int sum = 0, carry = 0, result = 0;

    for (int i = 0; i < sizeof(int) * BYTE_SIZE;i++) {
        // Calculate the sum of bits and carry
        sum = SHIFT_RIGHT(a, i) ^ SHIFT_RIGHT(b, i) ^ carry;

        // Update the result with the sum at the current bit position
        result |= SHIFT_LEFT(sum, i);

        // Calculate the new carry
        carry = (SHIFT_RIGHT(a, i) & SHIFT_RIGHT(b, i)) | (SHIFT_RIGHT(a, i) & carry) | (SHIFT_RIGHT(b, i) & carry);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    unsigned int num1, num2, sum;

    // Prompt user for input
    printf("Enter two integers: ");

    // Read two integers
    scanf("%d %d", &num1, &num2);

    // Calculate the sum
    sum = my_add(num1, num2);

    // Print the sum
    printf("The binary addition: %d + %d =  %d\n", num1, num2, sum);

    return 0;
}

