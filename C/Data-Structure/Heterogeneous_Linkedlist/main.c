#include "include/heterogeneous_linkedlist.h"

#include <stdio.h>
#include <locale.h>
#include <string.h>


void clean_stdin();
void input(int*, char*);
void printMenu(int*);
void typesMenu(linkedlist*);

int main() {

    setlocale(LC_ALL, "");

    linkedlist *list = createLinkedlist();

    int *user = (int*) malloc(sizeof(int*));
    *user = 0;

    short unsigned int await = 0;


    while (*user != 6) {
        printMenu(user);

        switch (*user) {
        case 1: 
            typesMenu(list);
            break;

        case 2:
            int *index = (int*) malloc(sizeof(int*));
            input(index, "Digite o índice do nó que deseja apagar: ");
            pop(list, *index, false);
            break;
        
        case 3:
            break;

        case 4:
            printf("A lista possui %d nós\n", list->length);
            printList(list);
            break;

        case 5:
            deleteList(list);
            linkedlist *list = createLinkedlist();
            printf("A lista foi apagada com sucesso\n");
            break;

        case 6:
            break;

        default: puts("Valor inválido."); break;
        }
    }

    return 0;
}


// Function to clean the buffer
void clean_stdin() {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}


/*
Collect input from the user keyboard

user: (int*) Pointer to user input
text: (char*)  String with text to print on screen
*/
void input(int *user, char *text) {
    printf("%s", text);
    scanf("%d", user);
    clean_stdin();
}


/*
Print the main menu

user: (int*) Pointer to user input
*/
void printMenu(int *user) {
    // clear();
    puts("\nMenu de opções da lista heterogênea");
    puts("1. Adicionar um valor");
    puts("2. Remover um valor");
    puts("3. Procurar um nó");
    puts("4. Printar lista");
    puts("5. Apagar lista");
    puts("6. sair");
    input(user, "Qual opção você deseja? ");
}


/*
Menu with types options

list: (linkedlist*) List with all data storage
*/
void typesMenu(linkedlist *list) {

    // clear();
    puts("\nTipos de dados:");
    puts("0. int");
    puts("1. float");
    puts("2. double");
    puts("3. string");
    puts("4. bool [0 ou 1]");
    puts("5. void");
    int *data_type = (int*) malloc(sizeof(int*));
    input(data_type, "Qual o tipo de dado que deseja adicionar? ");
    if (*data_type < VOID)
        printf("Digite o valor do dado selecionado: ");

    TypedData data;
    short unsigned int type;

    switch (*data_type)
    {
    case INT: 
        scanf("%lld", &data.intNumber);
        clean_stdin();
        type = INT;
        break;

    case FLOAT:
        scanf("%f", &data.floatNumber);
        clean_stdin();
        type = FLOAT;
        break;
    
    case DOUBLE:
        scanf("%lf", &data.doubleNumber);
        clean_stdin();
        type = DOUBLE;
        break;

    case STRING:
        fgets(data.string, sizeof(data.string), stdin);
        data.string[strcspn(data.string, "\n")] = '\0';
        clean_stdin();
        type = STRING;
        break;

    case BOOL:
        scanf("%d", &data.boolean);
        clean_stdin();
        type = BOOL;
        break;

    case VOID:
        data.v = NULL;
        break;

    default: 
        puts("Valor inválido."); 
        free(data_type);
        return;
    }

    free(data_type);
    int pos = 0;
    printf("Qual a posição que deseja adicionar? ");
    scanf("%d", &pos);
    clean_stdin();

    hNode *node = createNode(data, type);
    insert(list, node, pos);
}