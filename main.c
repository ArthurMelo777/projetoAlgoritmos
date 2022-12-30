#include <stdio.h>
#include "array_list_int.h"
#include "linked_list_int.h"

void array_list_printf(struct array_list_int *a) {
    int arraySize = array_list_size(a), arrayCapacity = array_list_capacity(a);
    printf(" (%u %u)\n{ ", arraySize, arrayCapacity);
    for (int i = 0; i<arraySize; i++) {
        printf("%d ", a[i]);
    }
    printf("}\n");
}

void linked_list_printf(struct linked_list_int * l) {
    int listSize = linked_list_size(l), erro;
    struct linked_list_int_node * no = l->first; 
    printf(" (%u)\n{ ", listSize);
    for (int i = 0; i<listSize; i++) {
        printf("%d ", linked_list_get(l, i));
    }
    printf("}\n");
}

int main () {
    int erro = 0;
    int arraySize;
    // Funções de teste Array
    // 1 - Criar o array
    struct array_list_int *a1 = array_list_create();

    // 2 - Inserir elementos no final do array (OK)

    for (int i = 0; i < 8; i++)
        arraySize = array_list_push_back(a1, i);

    array_list_printf(a1);
    printf("----------------------------------------------------------------------------\n");

    // 3 - Pegar elemento do indice (ERRO)
    int elemento = array_list_get(a1, 1, &erro);

    if (erro) printf("Erro ao capturar elemento");
    else printf("%d\n", elemento);
    printf("----------------------------------------------------------------------------\n");

    // 4 - Remover ultimo elemento do array (OK)
    arraySize = array_list_pop_back(a1);

    array_list_printf(a1);
    printf("----------------------------------------------------------------------------\n");

    // 5 - Tamanho da lista (OK)
    arraySize = array_list_size(a1);
    printf("%u\n", arraySize);
    printf("----------------------------------------------------------------------------\n");


    // 6 - Achar o indice do elemento (OK)
    int ind = array_list_find(a1, 5); // ind = 4
    printf("%d\n", ind);
    printf("----------------------------------------------------------------------------\n");

    // 7 - Adicionar no indice (ERRO)
    arraySize = array_list_insert_at(a1, 15, 8);
    array_list_printf(a1);
    printf("----------------------------------------------------------------------------\n");

    // 8 - Remover do indice (ERRO)
    arraySize = array_list_remove_from(a1, 15);
    array_list_printf(a1);
    printf("----------------------------------------------------------------------------\n");

    // 9 - Capacidade do array
    int capacityList = array_list_capacity(a1);
    printf("%u\n", capacityList);
    printf("----------------------------------------------------------------------------\n");

    // 10 - Porcentagem de uso
    double percent = array_list_percent_occupied(a1);
    printf("%lf\n", percent);

    // 11 - Destruir o array
    array_list_destroy(a1);
    printf("****************************************************************************\n");
    // Funções de teste Lista
    int listSize;

    // 1 - Criar a lista
    struct linked_list_int * l1 = linked_list_create();

    // 2 - Inserir elementos no final da lista
    for (int i = 0; i < 9; i++)
        listSize = linked_list_push_back(l1, i);
    linked_list_printf(l1);
    printf("----------------------------------------------------------------------------\n");

    // 3 - Pegar elemento do indice
    elemento = linked_list_get(l1, 1);

    printf("%d\n", elemento);
    printf("----------------------------------------------------------------------------\n");

    // 4 - Remover ultimo elemento da lista
    listSize = linked_list_pop_back(l1);

    linked_list_printf(l1);
    printf("----------------------------------------------------------------------------\n");

    // 5 - Tamanho da lista
    listSize = linked_list_size(l1);
    printf("%u", listSize);
    printf("----------------------------------------------------------------------------\n");

    // 6 - Achar o indice do elemento
    ind = linked_list_find(l1, 4);
    printf("%d", ind);
    printf("----------------------------------------------------------------------------\n");

    // 7 - Adicionar no indice
    listSize = linked_list_insert_at(l1, 7, 2);

    linked_list_printf(l1);
    printf("----------------------------------------------------------------------------\n");

    // 8 - Remover do indice
    listSize = linked_list_remove_from(l1, 7);

    linked_list_printf(l1);
    printf("----------------------------------------------------------------------------\n");

    // 9 - Porcentagem de uso
    linked_list_percent_occupied(l1);
    printf("----------------------------------------------------------------------------\n");

    // 10 - Destruir a lista
    linked_list_destroy(l1);

    return 0;
}