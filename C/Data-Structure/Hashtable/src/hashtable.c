#include <stdio.h>
#include <stdlib.h>
#define array_size 10




typedef struct Hashtable
{
    int *key;
    int *item;

} Hashtable;

typedef struct HashtableItem
{
    int hash;
    char name[100];
    int *next;
    int *previous;

} HashtableItem;


int main() 
{
    return 0;
}
