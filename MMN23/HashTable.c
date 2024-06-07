/**
* Created by Yotam Levit on 07/06/2024.
*/


#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"
#include "List.h"


HashTablePtr createHashTable(int numOfBuckets)
{
    HashTablePtr table = malloc(sizeof(struct HashTable));
    table->buckets = malloc(numOfBuckets * sizeof(NodePtr));
    table->numOfBuckets = numOfBuckets;
    return table;
}

NodePtr search(HashTablePtr table, int key)
{
    return table->buckets[key];
}

void insert(HashTablePtr table, int key, NodeDataPtr value)
{
    insertEnd(search(table, key), value);
}

void printHashTable(HashTablePtr table)
{
    int i;
    for (i = 0; i < table->numOfBuckets; i++)
    {
        printList(table->buckets[i]);
    }
}

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
