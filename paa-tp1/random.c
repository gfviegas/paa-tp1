//
//  random.c
//  paa-tp1
//
//  Created by Gustavo Viegas on 19/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include "random.h"

// Define a "aleatoriedade" da funcao random, usando a hora atual como base para semente
void seedRandomness(void) {
    struct timespec spec;
    
    clock_gettime(CLOCK_REALTIME, &spec);
    srandom((unsigned int)(spec.tv_nsec ^ spec.tv_sec));
}

// Gera um inteiro aleátorio
int generateRandomInt() {
    return (int)random();
}

// Gera um inteiro aleátorio entre dois números especificados
int generateRandomIntBetween(int min, int max) {
    int randomInt = generateRandomInt();
    
    return (randomInt % (max + 1)) + min;
}

// Gera um número aleatório entre 0 e MAX_RANDOM
int generateRandomNumberOnMax(void) {
    return generateRandomIntBetween(0, MAX_RANDOM);
}
