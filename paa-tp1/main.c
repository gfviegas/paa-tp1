//
//  main.c
//  paa-tp1
//
//  Created by Gustavo Viegas on 17/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include <stdio.h>
#include "intSet.h"

int main(int argc, const char * argv[]) {
    
    int vetor[N] = {1, 2, 3, -4, 25, 16, 20, 33, 40, -20};
    int hashTable[N];
    
    initHash(hashTable);
    verificarHash(hashTable, vetor, 20);

    return 0;
}
