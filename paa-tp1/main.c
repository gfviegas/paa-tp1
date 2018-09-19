//
//  main.c
//  paa-tp1
//
//  Created by Gustavo Viegas on 17/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "intSet.h"
#include "hash.h"
#include "random.h"

#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)
#define QTD_VARIAS_EXECUCOES 20

void testaHash(int x) {
    int i;
    double totalMilisegundos = 0;
    int array[ARRAY_SIZE];
    int hashTable[ARRAY_SIZE];
    
    fillArrayWithRandomNumbers(array);
    initHashTable(hashTable);
    
    for (i = 0; i < QTD_VARIAS_EXECUCOES; i++) {
        clock_t begin = clock();
        searchElementWithHash(hashTable, array, x);
        clock_t end = clock();
        totalMilisegundos += (double)(end - begin) / CLOCKS_PER_MS;
    }
    
    printf("Tempo médio gasto com HASH: %lf ms\n", totalMilisegundos / QTD_VARIAS_EXECUCOES);
}

void ordenaQuick(int* array) {
    double totalMilisegundos = 0;
    clock_t begin = clock();
    qsort(array, ARRAY_SIZE, sizeof(int), quickSortComparator);
    clock_t end = clock();
    totalMilisegundos = (double)(end - begin) / CLOCKS_PER_MS;
    printf("Tempo gasto para ordenar com quick: %lf ms\n", totalMilisegundos);
}

void testaComQuick(int x) {
    double totalMilisegundos = 0;
    int i;
    int array[ARRAY_SIZE];
    
    fillArrayWithRandomNumbers(array);
    ordenaQuick(array);
    
    for (i = 0; i < QTD_VARIAS_EXECUCOES; i++) {
        clock_t begin = clock();
        searchElementWithBinarySearch(array, x);
        clock_t end = clock();
        totalMilisegundos += (double)(end - begin) / CLOCKS_PER_MS;
    }
    printf("Tempo medio gasto para buscar apos ordenar com quick: %lf ms\n", totalMilisegundos / QTD_VARIAS_EXECUCOES);
}

void ordenaBubble(int* array) {
    double totalMilisegundos = 0;
    clock_t begin = clock();
    bubbleSort(array);
    clock_t end = clock();
    totalMilisegundos = (double)(end - begin) / CLOCKS_PER_MS;
    printf("Tempo gasto para ordenar com bubble: %lf ms\n", totalMilisegundos / QTD_VARIAS_EXECUCOES);
}

void testaComBubble(int x) {
    double totalMilisegundos = 0;
    int i;
    int array[ARRAY_SIZE];
    
    fillArrayWithRandomNumbers(array);
    ordenaBubble(array);
    
    for (i = 0; i < QTD_VARIAS_EXECUCOES; i++) {
        clock_t begin = clock();
        searchElementWithBinarySearch(array, x);
        clock_t end = clock();
        totalMilisegundos += (double)(end - begin) / CLOCKS_PER_MS;
    }
    printf("Tempo medio gasto para buscar apos ordenar com bubble: %lf ms\n", totalMilisegundos / QTD_VARIAS_EXECUCOES);
}

//    bubbleSort(&array[0], ARRAY_SIZE);

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    int x = generateRandomNumberOnMax();
    
    testaHash(x);
    testaComQuick(x);
    testaComBubble(x);
    
    return 0;
}
