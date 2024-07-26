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
                printf("Ponteiro inexistente encontrado. Não existe valor para esse índice: %d\n", i);
                return NULL;
            }
        }
        return aux;   
    }
    printf("Lista inexistente\n");
    return NULL;
}

// Devolverá o endereço da memória ao qual o último nó pertence
Node *searchLastNode(Node **list)
{
    Node *aux = *list;

    while (aux->next)
    {
        aux = aux->next;            
    }
    return aux;
}

// Irá devolver a posição do último nó
int searchLastNodePos(Node **list)
{
    int i = -1;
    Node *aux = *list;

    while (aux->next)
    {
        aux = aux->next;
        i++;            
    }
    // Se devolver -1 a lista não existe
    if (i == -1)
        printf("Sua lista é inexistente\n");
    return i;
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
        printf("A alocação do novo nó falhou\n");
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
        printf("A alocação do nó falhou\n");
    }
}

// Irá adicionar o novo nó na posição desejada na lista
void insertMiddle(Node **list, int value, int pos)
{
    Node *new_node = malloc(sizeof(Node));

    // Verifica se o ponteiro é NULL
    if (new_node)
    {
        new_node->value = value;

        // Irá procurar a última posição da lista
        int last_node_pos = searchLastNodePos(*list);
        
        // Irá observar se a lista está vazia ou é o primeiro índice
        if (*list == NULL || pos == 0)
        {
            insertBeginning(list, value);
        }
        // Caso seja a última posição da lista
        else if (pos == last_node_pos)
        {
            insertEnd(*list, value);
        }
        // Caso seja uma posição inválida
        else if (pos > last_node_pos || pos < 0)
        {
            printf("Valores inválidos. Nenhuma alteração foi feita na lista.\n");
        }
        // Caso seja uma posição válida no meio
        else
        {
            // Irá procurar o nó dessa posição e da anterior
            Node *next_node = searchNodeInPos(list, pos);
            Node *previous_node = searchNodeInPos(list, pos - 1);

            // Irá ligar os nós antigos ao novo nó
            new_node->next = next_node;
            new_node->previous = previous_node;

            // Irá alterar os antigos nós para manter a continuídade da lista
            previous_node->next = new_node;
            next_node->previous = new_node;

        }
    }
    else
    {
        printf("A alocação do novo nó falhou\n");
    }
}

// Irá imprimir toda a lista escolhida
void printList(Node **list)
{
    Node *aux = *list;
    int i = 0;
    if (aux)
    {
        while (aux)
        {
            printf("O valor da posição %d: %d\n", i, aux->value);
            i++;
        }
    }
    else
    {
        printf("Sua lista está vazia\n");
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");



    return 0;
}