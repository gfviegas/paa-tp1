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
#include "random.h"

/**
 * Tamanho do array a ser manipulado
 */
#define ARRAY_SIZE 50

// Algoritmos de inicialização
/**
 Preenche um vetor fornecido com números aleatórios

 @param array Vetor a ser manipulado
 */
void fillArrayWithRandomNumbers(int *array);


// Algoritmos de ordenação
/**
 Método a ser utilizado como comparador pelo QuickSort

 @param a Primeiro elemento de comparação
 @param b Segundo elemento de comparação
 @return Valor booleano que determina se a é menor que b, para ord. cresc.
 */
int quickSortComparator(const void * a, const void * b);

/**
 Ordena um vetor utilizando o BubbleSort

 @param array Vetor a ser ordenado
 */
void bubbleSort(int *array);

// Algoritmos de Busca Binária
/**
 Realiza a busca binária de um elemento X em um vetor ordenado

 @param array Vetor a ser manipulado
 @param left Limite inferior do vetor
 @param right Limite superior do vetor
 @param x Valor a ser buscado
 @return Valor representando se encontrou (indice) ou não (-1) o elemento
 */
int binarySearch(int *array, int left, int right, int x);

/**
 Realiza a verificação, com busca binária, se existe dois elementos cuja soma seja x

 @param array Vetor ordenado a ser manipulado
 @param x Valor cuja soma de dois elementos deseja ser encontrada
 */
void searchElementWithBinarySearch(int *array, int x);


#endif /* intSet_h */
