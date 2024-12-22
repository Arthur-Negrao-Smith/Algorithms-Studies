#ifdef HETEROGENEOUS_LINKEDLIST_H_INCLUDED
#define HETEROGENEOUS_LINKEDLIST_H_INCLUDED

typedef union TypedData {
    long long int intNumber;
    float floatNumber;
    double doubleNumber;
    char *string;
    bool boolean;
    void *v;} TypedData;

typedef struct hNode {
    struct hNode *next;
    struct hNode *previous;
    short unsigned int type;
    bool continuous;
    TypedData data;
} hNode;

typedef struct linkelist
{
    struct hNode *head;
    struct hNode *tail;
    int length;
} linkelist;

linkelist *createLinkedlist();
hNode *createNode(TypedData data, int type);
void deleteNode(hNode *node);
void addHead(linkelist *list, hNode *node);
void addTail(linkelist *list, hNode *node);
hNode *search(linkelist *list, int index);
void insert(linkelist *list, hNode *node, int index);
hNode *pop(linkelist *list, int index, bool return_node);
void deleteList(linkelist *list);
void printDebugList(linkelist *list, bool reverse);
void printList(linkelist *list);


#endif // HETEROGENEOUS_LINKEDLIST_H_INCLUDED
