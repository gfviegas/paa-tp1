//
//  intSet.c
//  paa-tp1
//
//  Created by Gustavo Viegas on 17/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include "intSet.h"

int comparador(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void preencheVetor(int *vetor, int n){
    int i;
    for(i=0;i<n;i++){
        vetor[i] = (rand() % MAXRANDOM) + 1; //Exclui o caso 0
    }
    return;
}

void imprimeVetor(int *vetor, int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",vetor[i]);
    printf("\n\n");
}

void bsort(int *vetor, int n){
    int i, j, troca;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(vetor[i] > vetor[j]){
                troca = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = troca;
            }
        }
    }
}

int procuraX(int *vetor, int x){
    int i;
    return x;
}

int buscaBinaria(int *vetor, int esq, int dir, int x){
    int i = (esq + dir) / 2;
    if(vetor[i] == x)
        return i;
    if(esq>=dir)
        return -1;
    if(vetor[i] < x)
        return buscaBinaria(vetor, i, dir, x);
    else
        return buscaBinaria(vetor,esq, i, x);
}


// HASHING
int hashCode(int valor) {
    return abs(valor % TAMVETOR);
}
void initHash(int* hashTable) {
    int i;
    for (i = 0; i < TAMVETOR; i++) {
        hashTable[i] = INT8_MIN;
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

        if (valorBuscado != INT8_MIN && (valorBuscado + valorAtual) == X) {
            printf("Par %d e %d dá o valor %d \n", valorBuscado, valorAtual, X);
            return 1;
        }
        
        insertHash(hashTable, valorAtual);
    }
    
    printf("Não foi encontrado nenhum par \n");
    return 0;
}
