//
//  intSet.c
//  paa-tp1
//
//  Created by Gustavo Viegas on 17/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include "intSet.h"

int geraAleatorio(void) {
    return (rand() % MAXRANDOM) + 1; //Exclui o caso 0
}

int comparador(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void preencheVetor(int *vetor, int n){
    int i;
    for (i = 0; i < n; i++) {
        vetor[i] = geraAleatorio();
    }

    return;
}

void bsort(int *vetor){
    int i, j, troca;
    for(i=0;i<TAMVETOR;i++){
        for(j=i;j<TAMVETOR;j++){
            if(vetor[i] > vetor[j]){
                troca = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = troca;
            }
        }
    }
}

void procuraX(int *vetor, int x){
    int i, indice;
    for(i=0;i<TAMVETOR;i++){
        indice = buscaBinaria(vetor, i+1, TAMVETOR-1, (x-vetor[i]));

        if (indice > 0) return;
    }
}

int buscaBinaria(int *vetor, int esq, int dir, int elemento){
    int i = (esq + dir) / 2;
    if(vetor[i] == elemento)
        return i;
    if(esq>=dir)
        return -1;
    else
        if (vetor[i] < elemento)
            return buscaBinaria(vetor, i+1, dir, elemento);
        else
        return buscaBinaria(vetor,esq, i-1, elemento);
}


// HASHING
int hashCode(int valor) {
    return abs(valor % TAMVETOR);
}
void initHash(int* hashTable) {
    int i;
    for (i = 0; i < TAMVETOR; i++) {
        hashTable[i] = INT_MIN;
    }
}
void insertHash(int* hashTable, int valor) {
    hashTable[hashCode(valor)] = valor;
}
int verificarHash(int* hashTable, int* vetor, int X) {
    int i, valorAtual, valorBuscado;

    for (i = 0; i < TAMVETOR; i++) {
        valorAtual = vetor[i];
        valorBuscado = hashTable[hashCode(X - valorAtual)];

        if (valorBuscado != INT_MIN && (valorBuscado + valorAtual) == X) return 1;
        insertHash(hashTable, valorAtual);
    }
    return 0;
}
