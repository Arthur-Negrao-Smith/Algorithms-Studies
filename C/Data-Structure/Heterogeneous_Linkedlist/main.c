#include "include/heterogeneous_linkedlist.h"

#include <stdio.h>
#include <locale.h>

void clear(void);
void input(int*, char*);
void printMenu(int*);
void typesMenu(linkedlist*);

int main() {

    setlocale(LC_ALL, "");

    linkedlist *list = createLinkedlist();

    int *user = (int*) malloc(sizeof(int*));
    *user = 0;


    while (*user != 6) {
        printMenu(user);

        switch (*user) {
        case 1: 
            typesMenu(list);
            break;

        case 2:
            break;
        
        case 3:
            break;

        case 4:
            printList(list);
            break;

        case 5:
            break;

        case 6:
            break;

        default: puts("Valor inválido."); break;
        }
    }

    return 0;
}

// Function to clear the terminal
void clear(void) {
    printf("\e[1;1H\e[2J");
}

/*
Collect input from the user keyboard

user: (int*) Pointer to user input
text: (char*)  String with text to print on screen
*/
void input(int *user, char *text) {
    printf("%s", text);
    scanf("%d", user);
    fflush(stdin);
}


/*
Print the main menu

user: (int*) Pointer to user input
*/
void printMenu(int *user) {
    clear();
    puts("Menu de opções da lista heterogênea");
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

    clear();
    puts("Tipos de dados:");
    puts("0. int");
    puts("1. float");
    puts("2. double");
    puts("3. string");
    puts("4. bool [0 ou 1]");
    puts("5. void");
    int *data_type = (int*) malloc(sizeof(int*));
    input(data_type, "Qual o tipo de dado que deseja adicionar? ");
    printf("Digite o valor do dado selecionado: ");

    TypedData data;
    short unsigned int type;

    switch (*data_type)
    {
    case INT: 
        scanf("%lld", &data.intNumber);
        fflush(stdin);
        type = INT;
        break;

    case FLOAT:
        scanf("%f", &data.floatNumber);
        fflush(stdin);
        type = FLOAT;
        break;
    
    case DOUBLE:
        scanf("%lf", &data.doubleNumber);
        fflush(stdin);
        type = DOUBLE;
        break;

    case STRING:
        fgets(data.string, sizeof(data.string), stdin);
        fflush(stdin);
        type = STRING;
        break;

    case BOOL:
        scanf("%d", &data.boolean);
        fflush(stdin);
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
    fflush(stdin);

    hNode *node = createNode(data, type);
    insert(list, node, pos);
}