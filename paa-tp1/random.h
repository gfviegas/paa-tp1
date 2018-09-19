//
//  random.h
//  paa-tp1
//
//  Created by Gustavo Viegas on 19/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#ifndef random_h
#define random_h

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * Tamanho máximo de um número aleátorio
 */
#define MAX_RANDOM 15000

/**
 Define a "aleatoriedade" da funcao random, usando a hora atual como base para semente
 */
void seedRandomness(void);


/**
 Gera um inteiro aleátorio
 
 @return Inteiro aleátorio
 */
int generateRandomInt(void);


/**
 Gera um inteiro aleátorio entre dois números especificados
 
 @param min Valor mínimo do inteiro aleátorio desejado
 @param max Valor máximo do inteiro aleátorio desejado
 @return Inteiro aleátorio no intervalo
 */
int generateRandomIntBetween(int min, int max);

/**
 Gera um número aleatório entre 0 e MAX_RANDOM
 
 @return Inteiro entre (0, MAX_RANDOM)
 */
int generateRandomNumberOnMax(void);

#endif /* random_h */
