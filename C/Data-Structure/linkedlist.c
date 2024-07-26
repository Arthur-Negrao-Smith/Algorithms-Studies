#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura do nó
typedef struct Node
{
    // Cada nó receberá um valor inteiro que busque guardar, um ponteiro do próximo nó e um ponteiro do nó anterior
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

// Devolverá o endereço de memória ao qual o nó da posição desejada pertence
Node *searchNodeInPos(Node **list, int pos)
{
    Node *aux = *list;
    if (aux)
    {
        for (int i=0; i < pos + 1; i++)
        {   
            if (aux)
            {
                aux = aux->next;
            }
            else
            {
                printf("Ponteiro inexistente encontrado. Não existe valor para esse índice");
                return NULL;
            }
        }
        return aux;   
    }
    return NULL;
}

// Devolverá o endereço da memória ao qual o último nó pertence
Node *searchLastNode(Node **list)
{
    Node *aux = *list;

    while (aux)
    {
        aux = aux->next;            
    }
    return aux;
}

// Irá inserir no início da lista ligada
void insertBeginning(Node **list, int value)
{
    Node *new_node = malloc(sizeof(Node));

    // Verifica se o ponteiro dado pelo malloc é nulo
    if (new_node)
    {
        new_node->value = value;
        new_node->next = *list;
        new_node->previous = NULL;
        *list = new_node;
    }
    else
    {
        printf("A alocação do novo nó falhou");
    }

}

// Irá inserir no final da lista ligada
void insertEnd(Node **list, int value)
{
    Node *new_node = malloc(sizeof(Node));

    // Verifica se o ponteiro dado pelo malloc é nulo
    if (new_node)
    {
        new_node->value;
        new_node->next = NULL;
        if (*list == NULL)
        {
            // Caso ele seja o primeiro nó a lista irá adicionar ele ao início
            *list = new_node;
        }
        else
        {
            // Irá pegar o último item da lista e linkar com o novo nó
            Node *aux = searchLastNode(*list);
            aux->next = new_node;
            // Irá pegar o novo nó e linkar o anterior a ele
            new_node->previous = aux;
            
        }
    }
    else
    {
        printf("A alocação do nó falhou");
    }
}


int main()
{
    setlocale(LC_ALL, "Portuguese");

    Node *list = createNode(7, NULL, NULL);


    return 0;
}