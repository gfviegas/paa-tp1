//
//  hash.h
//  paa-tp1
//
//  Created by Gustavo Viegas on 19/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#ifndef hash_h
#define hash_h

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "intSet.h"

/**
 Calcula o hash de um elemento para a tabela de tamanho ARRAY_SIZE
 
 @param value Valor do elemento a ser calculado
 @return Valor hash do elemento
 */
int hashCode(int value);

/**
 Inicializa uma tabela hash, iniciando todos os elementos com o menor inteiro possível, simulando um valor nulo
 
 @param hashTable Vetor da tabela hash a ser manipulada
 */
void initHashTable(int* hashTable);

/**
 Insere um elemento na tabela hash
 
 @param hashTable Vetor da tabela hash a ser manipulada
 @param value Valor do elemento a ser inserido na tabela
 */
void insertInHashTable(int* hashTable, int value);

/**
 Realiza a verificação, com tabela hash, se existe dois elementos cuja soma seja x
 
 @param hashTable Vetor da tabela hash a ser manipulada
 @param array Vetor dos elementos a serem buscados
 @param x Valor cuja soma de dois elementos deseja ser encontrada
 @return Valor booleano representando se encontrou (1) ou não (0) dois elementos cuja soma seja x
 */
int searchElementWithHash(int* hashTable, int* array, int x);


#endif /* hash_h */
