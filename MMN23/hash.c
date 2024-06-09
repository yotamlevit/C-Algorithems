#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "HashTable.h"

#define TOTAL_NUMBER_RANGE 29


/**
 * This function iterates through all data files from argv
 * @param hashTable
 * @param fileNames - array of file names
 * @param numFiles - number of files
 * @return int - 1 on success, 0 on failure
 */
int iterateFiles(HashTablePtr hashTable, char* fileNames[], const int numFiles) {
    struct dirent* entry;
    int i, j, num;
    FILE* filePtr;
    NodePtr bucketLocationPtr[TOTAL_NUMBER_RANGE] = {NULL}; /* A Temp ptr to the buckets nodes for efficiency */

    for ( j = 0; j < numFiles; j++) {
        filePtr = fopen(fileNames[j], "r");
        if (filePtr == NULL) {
            fprintf(stderr, "Failed to open file: %s\n", fileNames[j]);
            return EXIT_FAILURE;
        }

        while (fscanf(filePtr, "%d", &num) == 1) {
            if (bucketLocationPtr[num] == NULL)
                bucketLocationPtr[num] = insertHashTable(hashTable, num, createNodeData(1, fileNames[j]));
            else
                bucketLocationPtr[num]->data->numberCount++;
        }

        fclose(filePtr);

        /* Resetting all elements of bucketLocationPtr to NULL */
        for (i = 0; i < TOTAL_NUMBER_RANGE; i++) {
            bucketLocationPtr[i] = NULL;
        }
    }

    return EXIT_SUCCESS;
}


/**
 * The main function
 * @param argc - number of arguments
 * @param argv - array of arguments - the input files are here
 * @return int - 1 on success, 0 on failure
 */
int main(int argc, char *argv[]) {
    HashTablePtr hashTable;

    if (argc < 2) {
        fprintf(stderr, "No files in inpu. To run the program execute: ./hash <file1> <file2> ... <fileN>\n");
        return EXIT_FAILURE;
    }

    hashTable = createHashTable(TOTAL_NUMBER_RANGE);
    if (hashTable == NULL) {
        fprintf(stderr, "Failed to initialize hash table\n");
        return 0;
    }

    /* Remove the first argument which is the name of the program */
    iterateFiles(hashTable, &argv[1], argc-1);
    printHashTable(hashTable);

    freeHashTable(hashTable);
    return EXIT_SUCCESS;
}
