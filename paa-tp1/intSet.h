//
//  intSet.h
//  paa-tp1
//
//  Created by Gustavo Viegas on 17/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#ifndef intSet_h
#define intSet_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define MAXRANDOM 15000
#define TAMVETOR 50000

int comparador(const void * a, const void * b);
void preencheVetor(int *vetor, int N);
void imprimeVetor(int *vetor, int n);
void bsort(int *vetor, int n);
int buscaBinaria(int *vetor, int esq, int dir, int x);
void procuraX(int *vetor, int x);

// HASHING
int hashCode(int valor);
void initHash(int* hashTable);
void insertHash(int* hashTable, int valor);
int verificarHash(int* hashTable, int* vetor, int X);

#endif /* intSet_h */
