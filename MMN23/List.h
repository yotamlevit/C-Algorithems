/*
* Created by Yotam Levit on 06/06/2024.
*/

#ifndef MMN23_LIST_H
#define MMN23_LIST_H


typedef struct NodeData {
    int numberCount;
    char* fileName;
} NodeData, * NodeDataPtr;

/* Node Structure */
typedef struct Node {
    NodeDataPtr data;
    struct Node *next;
} Node, * NodePtr;


/* Node Data Functions */
NodeDataPtr createNodeData(int numberCount, char* fileName);

/* List Functions */
NodePtr createNode(NodeDataPtr data);
NodePtr insertNode(NodePtr node, NodeDataPtr data);
NodePtr insertEnd(NodePtr head, NodeDataPtr data);
NodePtr insertBegin(NodePtr head, NodeDataPtr data);
NodePtr findNode(NodePtr head, char* fileName);
void updateNode(NodePtr node, NodeDataPtr data);
NodePtr deleteNodeByData(NodePtr head, NodeDataPtr data);
NodePtr deleteNode(NodePtr node);
void printList(NodePtr head);
void freeList(NodePtr head);

#endif
