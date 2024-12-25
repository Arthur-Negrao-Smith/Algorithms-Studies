#include "include/heterogeneous_linkedlist.h"

#include <stdio.h>
#include <locale.h>


char *input(char*, int);
char printMenu(void);


int main() {

    setlocale(LC_ALL, "");

    linkedlist *list = createLinkedlist();

    char resp = '0';

    while (resp != '6') {

        switch (resp) {
        case '1': 
            typesMenu(list);
            break;

        case '2':
            break;
        
        case '3':
            break;

        case '4':
            break;

        case '5':
            break;

        case '6':
            break;

        default: puts("Valor inválido."); break;
        }
    }

    return 0;
}


char *input(char *text, int max_length) {
    char *resp = fgets(text, max_length, stdin);
    fflush(stdin);
    return resp;
}


char printMenu(void) {
    puts("Menu de opções da lista heterogênea");
    puts("1. Adicionar um valor");
    puts("2. Remover um valor");
    puts("3. Procurar um nó");
    puts("4. Printar lista");
    puts("5. Apagar lista");
    puts("6. sair");
    char resp[1] = input("Qual opção você deseja? ", 1);

    return resp[0];
}


void typesMenu(linkedlist *list) {
    int pos;
    printf("Qual a posição que deseja adicionar? ");
    scanf("%d", pos);
    fflush(stdin);

    pust("Tipos de dados:");
    puts("1. int");
    puts("2. float");
    puts("3. double");
    puts("4. string");
    puts("5. bool [0 ou 1]");
    puts("6. void");
    char resp[1] = input("Qual o tipo de dado que deseja adicionar? ", 1);
    printf("Digite o valor do dado selecionado: ");

    TypedData data;
    short unsigned int type;

    switch (resp[0])
    {
    case '1': 
        scanf("%d", data.intNumber);
        fflush(stdin);
        type = INT;
        break;

    case '2':
        scanf("%f", data.floatNumber);
        fflush(stdin);
        type = FLOAT;
        break;
    
    case '3':
        scanf("%f", data.doubleNumber);
        fflush(stdin);
        type = DOUBLE;
        break;

    case '4':
        scanf("%s", data.string);
        fflush(stdin);
        type = STRING;
        break;

    case '5':
        scanf("%i", data.boolean);
        fflush(stdin);
        type = BOOL;
        break;

    case '6':
        data.v = NULL;
        break;

    default: puts("Valor inválido."); return;
    }

    hNode *node = createNode(data, type);
    insert(list, node, pos);
}