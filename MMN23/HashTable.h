/**
* Created by Yotam Levit on 07/06/2024.
*/

#ifndef MMN23_HASHTABLE_H
#define MMN23_HASHTABLE_H

#include "List.h"

typedef struct HashTable {
    NodePtr* buckets;
    int numOfBuckets;
} HashTable, * HashTablePtr;


/* Hash Table Functions */
HashTablePtr createHashTable(int numOfBuckets);
NodePtr insertHashTable(HashTablePtr table, int key, NodeDataPtr value);
NodePtr findHashTable(HashTablePtr table, int key);
void printHashTable(HashTablePtr table);
void freeHashTable(HashTablePtr table);


#endif
