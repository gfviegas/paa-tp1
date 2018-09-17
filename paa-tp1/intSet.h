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
#include <time.h>
#define MAXRANDOM 15
#define TAMVETOR 50

int comparador(const void * a, const void * b);

void preencheVetor(int *vetor, int N);

void imprimeVetor(int *vetor, int n);

void bsort(int *vetor, int n);

int buscaBinaria(int *vetor, int esq, int dir, int x);

int procuraX(int *vetor, int x);
#endif /* intSet_h */
