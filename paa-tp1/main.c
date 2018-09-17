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

#define QTD_VARIAS_EXECUCOES 200

void testaHash(int* vetor, int* hashTable, int x) {
    int i;
    double totalMilisegundos = 0;
    initHash(hashTable);
    
    for (i = 0; i < QTD_VARIAS_EXECUCOES; i++) {
        clock_t begin = clock();
        verificarHash(hashTable, vetor, x);
        clock_t end = clock();
        totalMilisegundos += (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
    }
    
    printf("Tempo médio gasto com HASH: %lf ms\n", totalMilisegundos / QTD_VARIAS_EXECUCOES);
}

void ordenaQuick(int* vetor) {
    double totalMilisegundos = 0;
    clock_t begin = clock();
    qsort(vetor, TAMVETOR, sizeof(int), comparador);
    clock_t end = clock();
    printf("Tempo gasto para ordenar com quick: %lf ms\n", totalMilisegundos);
}

void testaComQuick(int* vetor, int x) {
    ordenaQuick(vetor);
}

//    bsort(&vetor[0], TAMVETOR);

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    int vetor[TAMVETOR];
    int hashTable[TAMVETOR];
    int x = 90;
    
    preencheVetor(&vetor[0], TAMVETOR);
    testaHash(vetor, hashTable, x);
    testaComQuick(vetor, x);
    
    //    procuraX(&vetor[0], x);
    
    
    return 0;
}
