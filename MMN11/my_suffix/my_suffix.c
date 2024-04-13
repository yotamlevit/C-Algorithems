//
// Created by Yotam Levit on 24/03/2024.
//
#include "stdio.h"

#define END_OF_STRING = '\0'

/*
 * This function finds suffix in a string that start with a given char
 * When the function finds the suffix it prints it and counts it

 *
 * The function iterates over the string using a for loop.
 *
 * param str: (char[]) the string to iterate over
 * param c: (char) the char that start the suffix.
 *
 * @return: (int) the number of suffix in the string.
 *          if a suffix is found the program prints it.
 */
int suffix(char str[], char c)
{
    int count = 0;
    char* currChar;

    for (currChar = str; *currChar != '\0'; currChar++)
    {
        if (*currChar == c)
        {
            printf("%s\n", currChar);
            count++;
        }
    }

    return count;
}

int main()
{
    char c, str[128];
    int suffixResult;

    // Read a char
    printf("Enter a char: ");
    scanf("%s", &c);

    // Read a string
    printf("Enter a string: ");
    scanf("%s", str);

    printf("The given string is: %s \nThe given char is: %c\n", str, c);
    // Run suffix the sum
    suffixResult = suffix(str, c);

    // Print the sum
    printf("The number of suffix is: %d\n", suffixResult);

    return 0;
}
