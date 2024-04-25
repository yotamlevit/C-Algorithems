/*
  Created by Yotam Levit on 24/03/2024.
*/

#include <stdio.h>
#include <stdlib.h>


/*
 This function calculates the partial sums of an array.
 It iterates over the array, adding each element to a cumulative sum
 and stores this cumulative sum in a new array at the corresponding index.

 param arr: (int*) pointer to the array of integers
 param length: (int) number of elements in the array

 @return: (int*) pointer to the new array containing partial sums
*/
int* partialSums(int* arr, int length)
{
    int i, sum = 0;
    int* partialSums = (int*)malloc(sizeof(int) * length);

    for (i = 0; i < length; ++i) {
        sum += arr[i];
        partialSums[i] = sum;
    }

    return partialSums;

}


/*
 This function retrieves an array of integers from the user input.
 It prompts the user to enter integers one by one and stores them in a dynamically allocated array.

 param length: (int) number of integers to be read

 @return: (int*) pointer to the dynamically allocated array of integers
*/
int* getArrayInput(int length)
{
    int i;
    int* arr = (int*)malloc(sizeof(int) * length);


    printf("Array length is %d\n\nEnter the first number: ", length);
    scanf("%d", arr);

    for (i = 1; i < length; i++) {
        printf("\nEnter the %d number: ", i+1);
        scanf("%d", arr + i);
    }

    return arr;
}


/*
 This function prints an array of integers in a formatted manner.
 It iterates over the array, printing each integer followed by a comma except for the last integer.

 param arr: (int*) pointer to the array of integers
 param length: (int) number of elements in the array
*/
void printArray(int* arr, int length)
{
    int i;

    printf("\n{");
    for (i = 0; i < length-1; ++i)
    {
        printf("%d, ", arr[i]);
    }

    printf("%d}\n", arr[length-1]);
}


int main() {
    int length;
    int* pArr;
    int* pPartialSums;

    printf("Enter the array`s length: ");
    scanf("%d", &length);

    pArr = getArrayInput(length);

    printf("The given array (length=%d) is:", length);
    printArray(pArr, length);

    pPartialSums = partialSums(pArr, length);

    printf("The returned partial sums array (length=%d) is:", length);
    printArray(pPartialSums, length);

    free(pPartialSums);
    free(pArr);
}

