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

void procuraX(int *vetor, int x){
    int i, indice;
    for(i=0;i<TAMVETOR;i++){
        indice = buscaBinaria(vetor, i+1, TAMVETOR-1, (x-vetor[i]));

        if (indice > 0) {
            printf("Soma encontrada, %d no indice %d com %d no indice %d", vetor[indice], indice, vetor[i], i);
            return;
        }
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
