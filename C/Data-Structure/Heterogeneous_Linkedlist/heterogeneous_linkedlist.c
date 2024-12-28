#include "heterogeneous_linkedlist.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/* 
Create a linkedlist with 3 variables

head: (*hNode) First node of the list
tail: (*hNode) Last node of the list
length: (int) Number of itemns in the list

Returns:
    Will return a linkedlist if the memory allocation was a success, else return NULL
*/
linkedlist *createLinkedlist() {
    linkedlist *list = (linkedlist*) malloc(sizeof(linkedlist));

    // If the allocation filed
    if (!list)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}


/*
Create a node with dynamic memory allocation to add on list

data: (TypedData) Heterogenous data which will be inserted into the node
type: (int) Type of the data

Returns:
    Will return a hNode if the memory allocation was a success, else return NULL
*/
hNode *createNode(TypedData data, int type) {

    // Create a memory allocation to the node
    hNode *node;
    node = (hNode*) malloc(sizeof(hNode));
    
    // If the allocation filed
    if (node == NULL) 
        return NULL;

    node->next = NULL;
    node->previous = NULL;

    // If choiced type exist, type will be assigned, else, type will be VOID
    if (type >= 0 && type <= 6) {
      node->type = type;
    } else {
      node->type = VOID;
    }

    node->data = data;

    return node;
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
void addHead(linkedlist *list, hNode *node) {
    
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
void addTail(linkedlist *list, hNode *node) {

    // If don't have any item in the list
    if (list->tail == NULL) {

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

Returns:
    Return the node pointer if it found, else return NULL pointer
*/
hNode *search(linkedlist *list, int index) {

    hNode *aux;
    int counter;
    bool reverse;

    // Otimization to reduce the loop
    if (index <= (int) list->length / 2) {
        reverse = false;
    } else {
        reverse = true;
    }


    if (!reverse) {
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
            counter--;
        }

        return aux;
    }
}


/*
Function to insert on list with index number

list: (*list) List which will be add a node
node: (*hNode) Node with data storage
index: (int) New index of the node in the list
*/
void insert(linkedlist *list, hNode *node, int index) {

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
return_node: (bool) Will return removed node of the list if is true, else return a NULL pointer

Returns: 
    NULL pointer if return_node is false and return the removed node if is true
*/
hNode *pop(linkedlist *list, int index, bool return_node) {

    hNode *aux1, *aux2;

    if (list->head == NULL) {
        return NULL;

    // If index equals to 0, so delete the head of list
    } else if (index == 0) {

        aux1 = list->head;

        list->head = aux1->next;

        // If the list has more than one item
        if (aux1->next) {
            aux2 = aux1->next;
            aux2->previous = NULL;
        }

    // If index is equal the final index or -1
    } else if (index == list->length-1 || index == -1) {

        aux1 = list->tail;

        list->tail = aux1->previous;

        // If the list has more than one item
        if (aux1->previous) {
            aux2 = aux1->previous;
            aux2->next = NULL;
        }

    // If index is out off the list range
   } else if (index < 0 || index >= list->length) {

    return NULL;

    } else {

        hNode *previous_aux, *next_aux;
        
        aux1 = search(list, index);

        previous_aux = aux1->previous;
        next_aux = aux1->next;

        previous_aux->next = next_aux;
        next_aux->previous = previous_aux;


    }

    // Updating length of the list
    list->length--;

    // Will return the node if is return_node is true
    if (!return_node) {

        deleteNode(aux1);
        return NULL;

    } else {

        return aux1;

    }
}


/*
Function to delete all list

list: (*linkedlist) List which will be clean from memory
 */
void deleteList(linkedlist *list) {

    // Create an auxiliar pointers
    hNode *aux1 = list->head;
    hNode *aux2;

    // While aux1 ins"t a NULL pointer"
    while (aux1) {
        
        aux2 = aux1;
        aux1 = aux1->next;

        free(aux2);

    }

    // Finally, free list from memory
    free(list);

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
        printf("%lld", data.intNumber);
        break;
    
    case FLOAT:
        printf("%f", data.floatNumber);
        break;

    case DOUBLE:
        printf("%lf", data.doubleNumber);
        break;

    case STRING:
        printf("\"%s\"", data.string);
        break;

    case BOOL:
        printf("%s", data.boolean ? "true" : "false");
        break;

    case VOID:
        printf("NULL");
        break;

    default:
        printf("Type undefined");
        break;
    }
}


/*
Print all with indexes list with select order

list: (*list) List which will be printed
reverse: (bool) If true, will print reverse list
*/
void printDebugList(linkedlist *list, bool reverse) {

    int counter;

    if (!reverse) {
        
        hNode *aux = list->head;
        counter = 0;

        while (aux)
        {
            printf("Node %d -> ", counter);
            typedPrint(aux->data, aux->type);
            printf("\n");

            aux = aux->next;
            counter++;
        }

    } else {
        
        hNode *aux = list->tail;
        counter = -1;

        while (aux) 
        {
        printf("Node %d -> ", counter);
        typedPrint(aux->data, aux->type);
        printf("\n");

        aux = aux->previous;
        counter--;
        }
    }
}


/*
Print all list in order: init->final

list: (*list) List which will be printed
reverse: (bool) If true, will print reverse list
*/
void printList(linkedlist *list) {

    printf("[ ");

    hNode *aux = list->head;

    while (aux)
    {

        typedPrint(aux->data, aux->type);
        if (aux->next)
            printf(", ");
        else 
            printf(" ");

        aux = aux->next;
    }

    printf("]\n");

}