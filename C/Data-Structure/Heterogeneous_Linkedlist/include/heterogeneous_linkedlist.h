#ifndef HETEROGENEOUS_LINKEDLIST_H_INCLUDED
#define HETEROGENEOUS_LINKEDLIST_H_INCLUDED

    #include <stdbool.h>
    #define DEFAULT_STRING_SIZE 8

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
    typedef union TypedData {
        long long int intNumber;
        float floatNumber;
        double doubleNumber;
        char string[DEFAULT_STRING_SIZE];
        bool boolean;
        void *v;
    } TypedData;


    /* 
    Node to add on list

    next: (*hNode) Next node in the list
    previous: (*hNode) Previous node in the list
    type: (unsigned short int) Type of storaged data
    continuous: (bool) Marker of a continuous data
    data: (TypedData) Data storaged
    */
    typedef struct hNode {
        struct hNode *next;
        struct hNode *previous;
        short unsigned int type;
        TypedData data;
    } hNode;


    /*
    Linkedlist type to create our list

    head: (*hNode) Initial node of the list
    tail: (*hNode) Final node of the list
    length: (int) Length of itemns in the list
    */
    typedef struct linkedlist
    {
        struct hNode *head;
        struct hNode *tail;
        int length;
    } linkedlist;

    linkedlist *createLinkedlist();
    hNode *createNode(TypedData data, int type);
    void deleteNode(hNode *node);
    void addHead(linkedlist *list, hNode *node);
    void addTail(linkedlist *list, hNode *node);
    hNode *search(linkedlist *list, int index);
    void insert(linkedlist *list, hNode *node, int index);
    hNode *pop(linkedlist *list, int index, bool return_node);
    void deleteList(linkedlist *list);
    void printDebugList(linkedlist *list, bool reverse);
    void printList(linkedlist *list);


#endif // HETEROGENEOUS_LINKEDLIST_H_INCLUDED
