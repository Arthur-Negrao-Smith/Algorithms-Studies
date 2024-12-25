#include "include/heterogeneous_linkedlist.h"

#include <stdio.h>
#include <locale.h>


char *input(char*, char*);
char printMenu(void);
void typesMenu(linkedlist*);

int main() {

    setlocale(LC_ALL, "");

    linkedlist *list = createLinkedlist();


    char resp[1];
    resp[0] = '0';

    while (resp[0] != '6') {

        resp[0] = printMenu();

        switch (resp[0]) {
        case '1': 
            typesMenu(list);
            break;

        case '2':
            break;
        
        case '3':
            break;

        case '4':
            printList(list);
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


char *input(char *string, char *text) {
    printf("%s", text);
    fgets(string, sizeof(string), stdin);
    fflush(stdin);
    return string;
}


char printMenu(void) {
    puts("Menu de opções da lista heterogênea");
    puts("1. Adicionar um valor");
    puts("2. Remover um valor");
    puts("3. Procurar um nó");
    puts("4. Printar lista");
    puts("5. Apagar lista");
    puts("6. sair");
    char resp[1];
    input(resp, "Qual opção você deseja? ");

    return resp[0];
}


void typesMenu(linkedlist *list) {

    puts("Tipos de dados:");
    puts("1. int");
    puts("2. float");
    puts("3. double");
    puts("4. string");
    puts("5. bool [0 ou 1]");
    puts("6. void");
    char resp[1];
    input(resp, "Qual o tipo de dado que deseja adicionar? ");
    printf("Digite o valor do dado selecionado: ");

    TypedData data;
    short unsigned int type;

    switch (resp[0])
    {
    case '1': 
        scanf("%lld", data.intNumber);
        fflush(stdin);
        type = INT;
        break;

    case '2':
        scanf("%f", data.floatNumber);
        fflush(stdin);
        type = FLOAT;
        break;
    
    case '3':
        scanf("%lf", data.doubleNumber);
        fflush(stdin);
        type = DOUBLE;
        break;

    case '4':
        fgets(data.string, sizeof(data.string), stdin);
        fflush(stdin);
        type = STRING;
        break;

    case '5':
        scanf("%d", data.boolean);
        fflush(stdin);
        type = BOOL;
        break;

    case '6':
        data.v = NULL;
        break;

    default: puts("Valor inválido."); return;
    }

    int pos = 0;
    printf("Qual a posição que deseja adicionar? ");
    scanf("%d", &pos);
    fflush(stdin);

    hNode *node = createNode(data, type);
    insert(list, node, pos);
}