/*
* Created by Yotam Levit on 06/06/2024.
*/

#ifndef MMN23_LIST_H
#define MMN23_LIST_H


typedef struct Node {
    int data;
    struct Node *next;
} Node, * NodePtr;

NodePtr createNode(int data);
NodePtr insertNode(NodePtr node, int data);
NodePtr insertEnd(NodePtr head, int data);
NodePtr insertBegin(NodePtr head, int data);
NodePtr findNode(NodePtr head, int data);
NodePtr deleteNodeByData(NodePtr head, int data);
NodePtr deleteNode(NodePtr node);
void printList(NodePtr head);
void freeList(NodePtr head);

#endif
