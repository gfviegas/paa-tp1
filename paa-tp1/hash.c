//
//  hash.c
//  paa-tp1
//
//  Created by Gustavo Viegas on 19/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include "hash.h"

// Calcula o hash de um elemento para a tabela de tamanho ARRAY_SIZE
int hashCode(int value) {
    return abs(value % ARRAY_SIZE);
}

// Inicializa uma tabela hash, iniciando todos os elementos com o menor inteiro possível, simulando um valor nulo
void initHashTable(int* hashTable) {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        hashTable[i] = INT_MIN;
    }
}

// Insere um elemento na tabela hash
void insertInHashTable(int* hashTable, int value) {
    hashTable[hashCode(value)] = value;
}

// Realiza a verificação, com tabela hash, se existe dois elementos cuja soma seja x
int searchElementWithHash(int* hashTable, int* array, int x) {
    int i, currentValue, targetValue;
    
    for (i = 0; i < ARRAY_SIZE; i++) {
        currentValue = array[i];
        targetValue = hashTable[hashCode(x - currentValue)];
        
        if (targetValue != INT_MIN && (targetValue + currentValue) == x) return 1;
        insertInHashTable(hashTable, currentValue);
    }
    
    return 0;
}
