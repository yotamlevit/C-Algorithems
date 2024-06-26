/*
* Created by Yotam Levit on 06/06/2024.
*/


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


#include "List.h"



/**
 * THis function create a new NodeData with the given data.
 *
 * @param numberCount - the number of times the a number appear in the file
 * @param fileName - the file name
 * @return NodeDataPtr - a pointer to the new NodeData
 */
NodeDataPtr createNodeData(int numberCount, char* fileName)
{
    NodeDataPtr newNodeData = malloc(sizeof(NodeData));
    newNodeData->numberCount = numberCount;
    newNodeData->fileName = malloc(sizeof(char) * (strlen(fileName) + 1));
    strcpy(newNodeData->fileName, fileName);
    return newNodeData;
}


/**
 * Initializes a new node with the given data.
 *
 * @param data - the data to be stored in the new node
 * @return NodePtr - a pointer to the new node
 */
NodePtr createNode(NodeDataPtr data)
{
    NodePtr newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


/**
 * Inserts a new node with the given data after the given node.
 *
 * @param node - the node to insert the new node after
 * @param data  - the data to be stored in the new node
 * @return NodePtr - a pointer to the new node
 */
NodePtr insertNode(NodePtr node, NodeDataPtr data)
{
    NodePtr newNode = createNode(data);
    newNode->next = node->next;
    node->next = newNode;
    return node;
}

/**
 * Inserts a new node with the given data at the end of the list.
 *
 * @param head - the head of the list
 * @param data  - the data to be stored in the new node
 * @return NodePtr - a pointer to the new node.
 */
NodePtr insertEnd(NodePtr head, NodeDataPtr data)
{
    NodePtr newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        NodePtr temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return newNode;
}

/**
 * Inserts a new node with the given data at the beginning of the list.
 *
 * @param head - the head of the list
 * @param data  - the data to be stored in the new node
 * @return NodePtr - a pointer to the new node.
 */
NodePtr insertBegin(NodePtr head, NodeDataPtr data)
{
    NodePtr newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

/**
 * Finds a node with the given data in the list.
 *
 * @param head - the head of the list
 * @param data - the data to be found
 * @return NodePtr - a pointer to the found node.
 */
NodePtr findNode(NodePtr head, char* fileName)
{
    NodePtr temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->data->fileName, fileName) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


/**
 * THis function updates the data of the given node.
 * @param node - the node to be updated
 * @param data - the new data
 */
void updateNode(NodePtr node, NodeDataPtr data)
{
    node->data = data;
}

/**
 * Deletes a node with the given data from the list.
 *
 * @param head - the head of the list
 * @param data - the data to be deleted
 * @return NodePtr - a pointer to the new head of the list.
 */
NodePtr deleteNodeByData(NodePtr head, NodeDataPtr data)
{
    NodePtr temp = head;
    if (temp->data == data)
    {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp->next != NULL)
    {
        if (temp->next->data == data)
        {
            NodePtr delNode = temp->next;
            temp->next = delNode->next;
            free(delNode);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

/**
 * Deletes a node from the list.
 *
 * @param node  - the node to be deleted
 * @return NodePtr - a pointer to the node before the deleted node.
 */
NodePtr deleteNode(NodePtr node)
{
    NodePtr temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    free(temp);
    return node;
}

/**
 * Prints the list.
 *
 * @param head
 */
void printList(NodePtr head)
{
    NodePtr temp = head;
    while (temp != NULL)
    {
        printf("file %s - %d %s", temp->data->fileName, temp->data->numberCount, temp->data->numberCount == 1 ? "time" : "times");
        if (temp->next != NULL)
            printf(", ");
        temp = temp->next;
    }
}

void freeList(NodePtr head)
{
    NodePtr temp = head;
    while (temp != NULL)
    {
        NodePtr delNode = temp;
        temp = temp->next;
        free(delNode->data);
        free(delNode);
    }
}
