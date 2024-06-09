/**
* Created by Yotam Levit on 07/06/2024.
*/


#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"
#include "List.h"


/**
 * Create a new hash table
 *
 * @param numOfBuckets - the number of buckets
 * @return HashTablePtr - a pointer to the new hash table
 */
HashTablePtr createHashTable(int numOfBuckets)
{
    HashTablePtr table = malloc(sizeof(struct HashTable));
    table->buckets = malloc(numOfBuckets * sizeof(NodePtr));
    table->numOfBuckets = numOfBuckets;
    return table;
}


/**
 * Find the bucket in the hash table
 *
 * @param table - a pointer to the hash table
 * @param key - the key for the bucket
 * @return NodePtr - a pointer to the bucket
 */
NodePtr findHashTable(HashTablePtr table, int key)
{
    return table->buckets[key];
}


/**
 * Insert a file to the correspond bucket with the number key
 *
 * @param table - a pointer to the hash table
 * @param key - the number key
 * @param data - the file name and the number of occurences
 * @return NodePtr - a pointer new Node
 */
NodePtr insertHashTable(HashTablePtr table, int key, NodeDataPtr data)
{
    table->buckets[key] = insertEnd(findHashTable(table, key) , data);
    return table->buckets[key];
}


/**
 * Checks if the bucket is empty
 * @param table - a pointer to the hash table
 * @param key - the number key
 * @return int - 1 if the bucket is empty, 0 otherwise
 */
int isBucketEmpty(HashTablePtr table, int key)
{
    return table->buckets[key] == NULL;
}


/**
 * This function prints the hash table
 *
 * @param table - a pointer to the hash table
 */
void printHashTable(HashTablePtr table)
{
    int i;
    for (i = 0; i < table->numOfBuckets; i++)
    {
        if (!isBucketEmpty(table, i))
        {
            printf("%d appears in ", i);
            printList(table->buckets[i]);
            printf("\n");
        }

    }
}


/**
 * Free the hash table
 *
 * @param table - a pointer to the hash table
 */
void freeHashTable(HashTablePtr table)
{
    int i;
    for (i = 0; i < table->numOfBuckets; i++)
    {
        freeList(table->buckets[i]);
    }
    free(table->buckets);
    free(table);
}
