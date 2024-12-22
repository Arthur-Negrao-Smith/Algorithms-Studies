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


/*
Union to create a heterogenous type

type index:
int = 0
float = 1
double = 2
string = 3
bool = 4
void = 5
*/
typedef union TypedData
{
    long long int intNumber;
    float floatNumber;
    double doubleNumber;
    char *string;
    bool boolean;
    void *v;
} TypedData;


/* 
Node to add on list

next: (*hNode) Next node in the list
previous: (*hNode) Previous node in the list
type: (unsigned short int) Type of storaged data
continue_string: (bool) Marker of strings continuity
data: (TypedData) Data storaged
*/
typedef struct hNode
{
    struct hNode *next;
    struct hNode *previous;
    short unsigned int type;
    bool continue_string;
    TypedData data;
} hNode;


/*
Linkedlist type to create our list

head: (*hNode) Initial node of the list
tail: (*hNode) Final node of the list
length: (int) Length of itemns in the list
*/
typedef struct linkelist
{
    struct hNode *head;
    struct hNode *tail;
    int length;
} linkelist;


/* 
Create a linkedlist with 3 variables

head: (*hNode) First node of the list
tail: (*hNode) Last node of the list
length: (int) Number of itemns in the list
*/
linkelist *createLinkedlist() {
    linkelist *list;
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}


/*
Create a node with dynamic memory allocation to add on list

data: (TypedData) Heterogenous data which will be inserted into the node
type: (int) Type of the data
*/
hNode *createNode(TypedData data, int type) {
    // Create a memory allocation to the node
    hNode *node;
    node = (hNode*) malloc(sizeof(hNode));

    node->next = NULL;
    node->previous = NULL;
    node->type = type;
    node->data = data;
}


/* 
Will delete node from memory

node: (*hNode) Node which will be deleted
*/
void deleteNode(hNode *node) {
    free(node);
}


/*
Function to add a head on the list

list: (*list) List which the head will be added
node: (*hNode) Node which will be the new head
*/
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


/*
Function to add a tail on the list

list: (*list) List which the tail will be added
node: (*hNode) Node which will be the new tail
*/
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


/*
Function to search node using idex

list: (*list) List which want find out a node
index: (int) Index of the of the node in the list
*/
hNode *search(linkelist *list, int index) {

    hNode *aux;
    int counter;
    bool reverse;

    // Otimization to reduce the loop
    if (index <= (int) list->length / 2) {
        reverse = false;
    } else {
        reverse = true;
    }


    if (not reverse) {
        aux = list->head;
        counter = 0;

        while (counter < index) {
            aux = aux->next;
            counter++;
        }

        return aux;

    } else {
        aux = list->tail;
        counter = list->length-1;

        while (counter > index) {
            aux = aux->next;
            counter++;
        }

        return aux;
    }
}


/*
Function to insert on list with index number

list: (*list) List which will be add a node
index: (int) New index of the node in the list
*/
void insert(linkelist *list, hNode *node, int index) {

    // If index is equal 0 is a inital item
    if (index == 0) {

        addHead(list, node);

    // If index is equal final index of the list
    } else if (index >= list->length-1) {
        
        addTail(list, node);

    } else {

        // Auxiliar nodes to swap the pointers
        hNode *previous_aux, *next_aux;

        previous_aux = search(list, index-1);
        next_aux = previous_aux->next;

        previous_aux->next = node;
        node->previous = previous_aux;

        next_aux->previous = node;
        node->next = next_aux;

        list->length++;

    }
}


/**
Remove a list item with a index

list: (*list) List which will removed a node
index: (int) Index of the node in the list
*/
void pop(linkelist *list, int index) {

    hNode *aux1, *aux2;

    // If index equals to 0, so delete the head of list
    if (index == 0) {

        aux1 = list->head;

        list->head = aux1->next;
        aux2 = aux1->next;

        aux2->previous = NULL;

        deleteNode(aux1);

    // If index is equal the final index or -1
    } else if (index == list->length-1 || index == -1) {

        aux1 = list->tail;

        list->tail = aux1->previous;
        aux2 = aux1->previous;

        aux2->next = NULL;

        deleteNode(aux1);

    } else {

        hNode *previous_aux, *next_aux;
        
        aux1 = search(list, index);

        previous_aux = aux1->previous;
        next_aux = aux1->next;

        previous_aux->next = next_aux;
        next_aux->previous = previous_aux;

        deleteNode(aux1);

    }

    list->length--;
}


/*
Print TypedData with especific printf marker

data: (TypedData) Data which will be printed
type: (int) Type of the data
*/
void typedPrint(TypedData data, int type) {

    switch (type)
    {
    case INT:
        printf("%d", data.intNumber);
        break;
    
    case FLOAT:
        printf("%f", data.floatNumber);
        break;

    case DOUBLE:
        printf("%f", data.doubleNumber);
        break;

    case STRING:
        printf("%s", data.string);
        break;

    case BOOL:
        printf("%d", data.boolean ? "true" : "false");

    case VOID:
        printf("NULL");

    default:
        printf("Type undefined");
        break;
    }
}


/*
Print all list with select order

list: (*list) List which will be printed
reverse: (bool) If true, will print reverse list
*/
void printList(linkelist *list, bool reverse) {

    if (not reverse) {
        
        hNode *aux = list->head;

        while (aux)
        {
            printf("Node %d -> ");
            typedPrint(aux->data, aux->type);
            printf("\n");

            aux = aux->next;
        }

    } else {
        
        hNode *aux = list->tail;

        while (aux) 
        {
        printf("Node %d -> ");
        typedPrint(aux->data, aux->type);
        printf("\n");

        aux = aux->previous;
        }
    }
}