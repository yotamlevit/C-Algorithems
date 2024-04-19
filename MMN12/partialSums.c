//
// Created by Yotam Levit on 24/03/2024.
//

#include "stdio.h"

int* partialSums(int arr[], int length)
{
    //COde
}

int* getArrayInput(int length)
{
    int i;
    int arr[length];

    printf("Array length is %d\nEnter the first number: ", length);
    scanf("%d", arr);

    for (i = 1; i < length; i++) {
        printf("Enter the next number: ");
        scanf("%d", arr + i);
    }

    return (int*)arr;
}

void printArray(int* arr, int length)
{
    int i;

    printf("\n{ ");
    for (i = 0; i < length-1; ++i)
    {
        printf(" %d, ", arr[i]);
    }

    printf("%d }\n", arr[length-1]);
}

int main() {
    int length;
    int *pArr;

    printf("Enter the array`s length: ");
    scanf("%d", &length);

    pArr = getArrayInput(length);

    printf("The given array (length=%d) is:", length);
    printArray(pArr, length);
}

