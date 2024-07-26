#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct Node
{
    int value;
    Node *next;
    Node *previous;

} Node;

Node *createNode(int value, Node *next, Node *previous)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->value = value;

    if (previous) // Observa se o ponteiro é NULL, se for o primeiro ele é nulo
    {
        node->previous = previous;
    }

    return node;
}

void insertBeginning(Node **list, int value)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node)
    {
        new_node->value = value;
        new_node->next = *list;
        new_node->previous = NULL;
        *list = new_node;
    }
    else
    {
        printf("Alocação do novo nó falhou");
    }    

}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    return 0;
}