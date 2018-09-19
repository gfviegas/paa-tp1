//
//  intSet.c
//  paa-tp1
//
//  Created by Gustavo Viegas on 17/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include "intSet.h"

// Preenche um vetor fornecido com números aleatórios
void fillArrayWithRandomNumbers(int *array){
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = generateRandomNumberOnMax();
    }
    
    return;
}

// Método a ser utilizado como comparador pelo QuickSort
int quickSortComparator(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Ordena um vetor utilizando o BubbleSort
void bubbleSort(int *array) {
    int i, j, temp;

    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = i; j < ARRAY_SIZE; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

// Realiza a busca binária de um elemento X em um vetor ordenado
int binarySearch(int *array, int left, int right, int element){
    int i = (left + right) / 2;
    if (array[i] == element) return i;
    if (left >= right) return -1;
    if (array[i] < element) return binarySearch(array, i + 1, right, element);
    return binarySearch(array, left, i - 1, element);
}

// Realiza a verificação, com busca binária, se existe dois elementos cuja soma seja x
void searchElementWithBinarySearch(int *array, int x) {
    int i, index;

    for (i = 0; i < ARRAY_SIZE; i++) {
        index = binarySearch(array, i + 1, ARRAY_SIZE - 1, x - array[i]);
        if (index > 0) return;
    }
}

