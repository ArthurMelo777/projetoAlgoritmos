#include <stdio.h>
#include <time.h>
#include "array_list_int.h"

void array_list_printf(struct array_list_int *a) {
    int arraySize = array_list_size(a), arrayCapacity = array_list_capacity(a);
    printf(" (%u %u)\n{ ", arraySize, arrayCapacity);
    for (int i = 0; i<arraySize; i++) {
        printf("%d ", a->data[i]);
    }
    printf("}\n");
}

int main () {
    clock_t inicio, fim;
    int erro = 0;
    int arraySize;
    // Funções de teste Array
    // 1 - Criar o array
    struct array_list_int *a1 = array_list_create();

    // 2 - Inserir elementos no final do array (OK)
    inicio = clock();
    for (int i = 0; i < 10000; i++)
        arraySize = array_list_push_back(a1, i);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));
    printf("----------------------------------------------------------------------------\n");

    inicio = clock();
    array_list_printf(a1);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));
    printf("----------------------------------------------------------------------------\n");

    // 3 - Pegar elemento do indice (ERRO)
    inicio = clock();
    int elemento = array_list_get(a1, 1, &erro);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));

    if (erro) printf("Erro ao capturar elemento");
    else printf("%d\n", elemento);
    printf("----------------------------------------------------------------------------\n");

    // 4 - Remover ultimo elemento do array (OK)
    inicio = clock();
    arraySize = array_list_pop_back(a1);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));

    //array_list_printf(a1);
    printf("----------------------------------------------------------------------------\n");

    // 5 - Tamanho da lista (OK)
    arraySize = array_list_size(a1);
    printf("%u\n", arraySize);
    printf("----------------------------------------------------------------------------\n");


    // 6 - Achar o indice do elemento (OK)
    inicio = clock();
    int ind = array_list_find(a1, 5); // ind = 5
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));
    printf("%d\n", ind);
    printf("----------------------------------------------------------------------------\n");

    // 7 - Adicionar no indice (OK) Nao adiciona para indices acima do tamanho
    inicio = clock();
    arraySize = array_list_insert_at(a1, 5, 8);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));
    //array_list_printf(a1);
    printf("----------------------------------------------------------------------------\n");

    // 8 - Remover do indice (ERRO)
    inicio = clock();
    arraySize = array_list_remove_from(a1, 1);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));
    //array_list_printf(a1);
    printf("----------------------------------------------------------------------------\n");

    // 9 - Capacidade do array
    int capacityList = array_list_capacity(a1);
    printf("%u\n", capacityList);
    printf("----------------------------------------------------------------------------\n");

    // 10 - Porcentagem de uso
    printf("%lf\n", array_list_percent_occupied(a1));

    // 11 - Destruir o array
    array_list_destroy(a1);

    return 0;
}