//
//  intSet.c
//  paa-tp1
//
//  Created by Gustavo Viegas on 17/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include "intSet.h"

int hashCode(int valor) {
    return abs(valor % N);
}

void initHash(int* hashTable) {
    int i;
    for (i = 0; i < N; i++) {
        hashTable[i] = INT8_MIN;
    }
}

void insertHash(int* hashTable, int valor) {
    hashTable[hashCode(valor)] = valor;
}

int verificarHash(int* hashTable, int* vetor, int X) {
    int i, valorAtual, valorBuscado;
    
    for (i = 0; i < N; i++) {
        valorAtual = vetor[i];
        valorBuscado = hashTable[hashCode(X - valorAtual)];
        insertHash(hashTable, valorAtual);
        
        if (valorBuscado != INT8_MIN && (valorBuscado + valorAtual) == X) {
            printf("Par %d e %d dá o valor %d \n", valorBuscado, valorAtual, X);
            return 1;
        }
    }
    
    printf("Não foi encontrado nenhum par \n");
    return 0;
}
