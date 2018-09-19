//
//  benchmark.c
//  paa-tp1
//
//  Created by Gustavo Viegas on 19/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include "benchmark.h"

// Executa uma bateria de {TESTS_AMMOUNT} testes, com vetores e valores de x aleatórios, utilizando a solução de tabela hash e calculando o valor médio de microsegundos gastos para encontrar dois elementos cuja soma seja um x aleátorio
void hashSolutionBenchmark(void) {
    int i, x;
    double searchTime = 0;
    int array[ARRAY_SIZE];
    int hashTable[ARRAY_SIZE];
    
    for (i = 0; i < TESTS_AMMOUNT; i++) {
        x = generateRandomNumberOnMax();
        fillArrayWithRandomNumbers(array);
        initHashTable(hashTable);
        
        clock_t searchBegin = clock();
        searchElementWithHash(hashTable, array, x);
        clock_t searchEnd = clock();
        searchTime += (double)((searchEnd - searchBegin) / CLOCKS_PER_US);
    }
    searchTime = (searchTime / TESTS_AMMOUNT);
    
    printf("\n******* TESTE HASH *******\n");
    printf("\t- Pesquisa: %lf ms\n", searchTime);
    printf("******* FIM HASH *******\n");
}

// Executa uma bateria de {TESTS_AMMOUNT} testes, com vetores e valores de x aleatórios, utilizando a solução de ordenar o vetor com QuickSort e calculando o valor médio de milisegundos gastos para encontrar dois elementos cuja soma seja um x aleátorio com busca binária e para ordenar o vetor
void quickSortSolutionBenchmark(void) {
    double sortTime = 0;
    double searchTime = 0;
    int i, x;
    int array[ARRAY_SIZE];
    
    for (i = 0; i < TESTS_AMMOUNT; i++) {
        x = generateRandomNumberOnMax();
        fillArrayWithRandomNumbers(array);
        
        clock_t sortingBegin = clock();
        qsort(array, ARRAY_SIZE, sizeof(int), quickSortComparator);
        clock_t sortingEnd = clock();
        
        clock_t searchBegin = clock();
        searchElementWithBinarySearch(array, x);
        clock_t searchEnd = clock();
        
        sortTime += (double)(sortingEnd - sortingBegin) / CLOCKS_PER_MS;
        searchTime += (double)(searchEnd - searchBegin) / CLOCKS_PER_MS;
    }
    sortTime = (sortTime / TESTS_AMMOUNT);
    searchTime = (searchTime / TESTS_AMMOUNT);
    
    printf("\n******* TESTE QUICKSORT *******\n");
    printf("\t- Ordenação: %lf ms\n", sortTime);
    printf("\t- Pesquisa: %lf ms\n", searchTime);
    printf("******* FIM QUICKSORT *******\n");
}

// Executa uma bateria de {TESTS_AMMOUNT / 4} testes, com vetores e valores de x aleatórios, utilizando a solução de ordenar o vetor com BubbleSort e calculando o valor médio de milisegundos gastos para encontrar dois elementos cuja soma seja um x aleátorio com busca binária e para ordenar o vetor
void bubbleSortSolutionBenchmark(void) {
    double sortTime = 0;
    double searchTime = 0;
    int i, x;
    int array[ARRAY_SIZE];
    int bubbleQuantidade = TESTS_AMMOUNT / 4;
    
    for (i = 0; i < bubbleQuantidade; i++) {
        x = generateRandomNumberOnMax();
        fillArrayWithRandomNumbers(array);
        
        clock_t sortingBegin = clock();
        bubbleSort(array);
        clock_t sortingEnd = clock();
        
        clock_t searchBegin = clock();
        searchElementWithBinarySearch(array, x);
        clock_t searchEnd = clock();
        
        sortTime += (double)(sortingEnd - sortingBegin) / CLOCKS_PER_MS;
        searchTime += (double)(searchEnd - searchBegin) / CLOCKS_PER_MS;
    }
    sortTime = (sortTime / bubbleQuantidade);
    searchTime = (searchTime / bubbleQuantidade);
    
    printf("\n******* TESTE BUBBLESORT *******\n");
    printf("\t- Ordenação: %lf ms\n", sortTime);
    printf("\t- Pesquisa: %lf ms\n", searchTime);
    printf("******* FIM BUBBLESORT *******\n");
}
