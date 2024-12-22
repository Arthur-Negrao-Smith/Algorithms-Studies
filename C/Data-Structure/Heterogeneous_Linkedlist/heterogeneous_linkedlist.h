#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DEFAULT_STRING_SIZE 8
#define STRING_MAX_SIZE 100

#define INT 0
#define FLOAT 1
#define DOUBLE 2
#define STRING 3
#define BOOL 4
#define VOID 5


// Union to create a heterogenous type
typedef union TypedData
{
    long long int intNumber;
    float floatNumber;
    double doubleNumber;
    char *string;
    bool boolean;
    void *v;
} TypedData;


// Node to add on list
typedef struct hNode
{
    struct hNode *next;
    struct hNode *previous;
    int type;
    bool continue_string;
    TypedData data;
} hNode;


// Linkedlist type to create our list
typedef struct linkelist
{
    struct hNode *head;
    struct hNode *tail;
    int length;
} linkelist;


/* 
Create a linkedlist with 3 variables

head: First node of the list
tail: Last node of the list
length: Number of itemns in the list
*/
linkelist *createLinkedlist() {
    linkelist *list;
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}


// Create a node with dynamic memory allocation to add on list
hNode *createNode(TypedData data, int type) {
    // Create a memory allocation to the node
    hNode *node;
    node = (hNode*) malloc(sizeof(hNode));

    node->next = NULL;
    node->previous = NULL;
    node->type = type;
    node->data = data;
}


// Will delete node from memory
void deleteNode(hNode *node) {
    free(node);
}


// Function to add a head on the list
void addHead(linkelist *list, hNode *node) {
    
    // If don't have any item in the list
    if (list->head == NULL) {

        list->head = node;
        list->tail = node;
        list->length = 1;
    
    } else {
        
        // Swapping data
        hNode *aux = list->head;
        
        list->head = node;
        aux->previous = node;
        node->next = aux;

        // Updating length counter
        list->length++;
    
    }
}

// Function to add a tail on the list
void addTail(linkelist *list, hNode *node) {

    // If don't have any item in the list
    if (list->tail) {

        list->head = node;
        list->tail = node;
        list->length = 1;

    } else {

        // Swapping data
        hNode *aux = list->tail;
        
        list->tail = node;
        node->previous = aux;
        aux->next = node;

        // Updating length counter
        list->length++;

    }
}

