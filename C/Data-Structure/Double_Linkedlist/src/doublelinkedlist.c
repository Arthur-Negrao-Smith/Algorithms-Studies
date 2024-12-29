/*
Esse código não pertence inteiramente a mim, uma parte bem considerável foi baseada e até copiada para fins de estudo do site: www.geeksforgeeks.org
Contudo, fiz várias modificações no código adicionando uma interface e explicações, além de adicionar funções e testes ao código
Esse código pode ser utilizado por qualquer pessoa e espero que ajude nos estudos de estrutura de dados
Bons estudos e em caso de dúvidas a fonte original talvez sirva melhor para qualquer explicação
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *previous;

} Node;

Node *head = NULL;
Node *tail = NULL;

Node *crateNode(int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node)
    {
    new_node->value = value;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
    }
    // Caso o malloc devolva um NULL pointer
    printf("A alocação de memória do nó falhou\n");
    return NULL;
}

void insertAtHead(int value)
{
    Node *new_node = crateNode(value);
    if (new_node)
    {
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->previous = new_node;
            head = new_node;
        }
    }
}

void insertAtTail(int value)
{
   Node *new_node = crateNode(value);
   if (new_node)
   {
        if (tail == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->previous = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }
}

void deleteAtHead()
{
    if (head == NULL)
    {
        printf("Sua lista está vazia. Nenhum valor foi apagado\n");
        return;
    }
    Node *aux = head;
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        head->previous = NULL;
    }
    free(aux);
    printf("Seu valor foi apagado com sucesso da Cabeça da lista\n");
}

void deleteAtTail()
{
    if (tail == NULL)
    {
        printf("Sua lista está vazia. Nenhum valor foi apagado\n");
        return;
    }
    Node *aux = tail;
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->previous;
        tail->next = NULL;
    }
    free(aux);
    printf("Seu valor foi apagado com sucesso da Calda da lista\n");
}

void printFoward()
{
    Node *aux = head;
    int i = 0;
    if (aux)
    {
        while(aux)
        {
            printf("O valor da posição %d: %d\n", i, aux->value);
            aux = aux->next;
            i++;
        }
        return;
    }
    printf("Sua lista está vazia\n");
}

void printBackaward()
{
    Node *aux = tail;
    int i = -1;
    if (aux)
    {
        while(aux)
        {
            printf("O valor da posição %d: %d\n", i, aux->value);
            aux = aux->previous;
            i--;
        }
        return;
    }
    printf("Sua lista está vazia\n");
}

void printAtPos(int pos)
{
    if (head == NULL)
    {
        printf("Sua lista está vazia\n");
        return;
    }
    Node *aux = head;
    int i = 0;
    while (aux->next && i != pos)
    {
        aux = aux->next;
        i++;
    }
    if (pos == i)
        printf("O nó da posição %d contém o valor: %d\n", pos, aux->value);
    else
        printf("O índice escolhido não está na lista\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int op, value, pos;
    do
    {
        printf("\nDigite a opção desejada:\n");
        printf("0 -> Fechar Programa\n1 -> Adicionar a cabeça da lista\n2 -> Adicionar a calda da lista\n3 -> Remover a cabeça da lista\n4 -> Remover a cauda da lista\n5 -> Mostrar lista\n6 -> Mostrar lista reversa\n7 -> Mostrar valor da posição escolhida\n");
        printf("Sua opção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Digite o valor que deseja adicionar a cabeça: ");
            scanf("%d", &value);
            insertAtHead(value);
            break;
        
        case 2:
            printf("Digite o valor que deseja adicionar a calda: ");
            scanf("%d", &value);
            insertAtTail(value);
            break;

        case 3:
            deleteAtHead();
            break;

        case 4:
            deleteAtTail();
            break;

        case 5:
            printFoward();
            break;

        case 6:
            printBackaward();
            break;

        case 7:
            printf("Digite o valor da posição que deseja ver: ");
            scanf("%d", &pos);
            printAtPos(pos);
            break;
            
        default:
            if (op != 0)
                printf("Opção inválida\n");
            break;
        }
    } while (op != 0);
    
    return 0;
}