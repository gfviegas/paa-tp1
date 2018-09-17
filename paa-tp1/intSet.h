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
#define N 10

int hashCode(int valor);
void initHash(int* hashTable);
void insertHash(int* hashTable, int valor);
void imprimeHash(int* hashTable);
int verificarHash(int* hashTable, int* vetor, int X);

#endif /* intSet_h */
