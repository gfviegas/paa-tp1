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

#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)
#define QTD_VARIAS_EXECUCOES 20

void testaHash(int x) {
    int i;
    double totalMilisegundos = 0;
    int vetor[TAMVETOR];
    int hashTable[TAMVETOR];
    
    preencheVetor(vetor, TAMVETOR);
    initHash(hashTable);
    
    for (i = 0; i < QTD_VARIAS_EXECUCOES; i++) {
        clock_t begin = clock();
        verificarHash(hashTable, vetor, x);
        clock_t end = clock();
        totalMilisegundos += (double)(end - begin) / CLOCKS_PER_MS;
    }
    
    printf("Tempo médio gasto com HASH: %lf ms\n", totalMilisegundos / QTD_VARIAS_EXECUCOES);
}

void ordenaQuick(int* vetor) {
    double totalMilisegundos = 0;
    clock_t begin = clock();
    qsort(vetor, TAMVETOR, sizeof(int), comparador);
    clock_t end = clock();
    totalMilisegundos = (double)(end - begin) / CLOCKS_PER_MS;
    printf("Tempo gasto para ordenar com quick: %lf ms\n", totalMilisegundos);
}

void testaComQuick(int x) {
    double totalMilisegundos = 0;
    int i;
    int vetor[TAMVETOR];
    
    preencheVetor(vetor, TAMVETOR);
    ordenaQuick(vetor);
    
    for (i = 0; i < QTD_VARIAS_EXECUCOES; i++) {
        clock_t begin = clock();
        procuraX(vetor, x);
        clock_t end = clock();
        totalMilisegundos += (double)(end - begin) / CLOCKS_PER_MS;
    }
    printf("Tempo medio gasto para buscar apos ordenar com quick: %lf ms\n", totalMilisegundos / QTD_VARIAS_EXECUCOES);
}

void ordenaBubble(int* vetor) {
    double totalMilisegundos = 0;
    clock_t begin = clock();
    bsort(vetor);
    clock_t end = clock();
    totalMilisegundos = (double)(end - begin) / CLOCKS_PER_MS;
    printf("Tempo gasto para ordenar com bubble: %lf ms\n", totalMilisegundos / QTD_VARIAS_EXECUCOES);
}

void testaComBubble(int x) {
    double totalMilisegundos = 0;
    int i;
    int vetor[TAMVETOR];
    
    preencheVetor(vetor, TAMVETOR);
    ordenaBubble(vetor);
    
    for (i = 0; i < QTD_VARIAS_EXECUCOES; i++) {
        clock_t begin = clock();
        procuraX(vetor, x);
        clock_t end = clock();
        totalMilisegundos += (double)(end - begin) / CLOCKS_PER_MS;
    }
    printf("Tempo medio gasto para buscar apos ordenar com bubble: %lf ms\n", totalMilisegundos / QTD_VARIAS_EXECUCOES);
}

//    bsort(&vetor[0], TAMVETOR);

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    int x = geraAleatorio();
    
    testaHash(x);
    testaComQuick(x);
    testaComBubble(x);
    
    return 0;
}
