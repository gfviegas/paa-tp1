//
//  main.c
//  paa-tp1
//
//  Created by Gustavo Viegas on 17/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "benchmark.h"
#include "intSet.h"

int main(int argc, const char * argv[]) {
    seedRandomness();
    
    printf("\t Fazendo os testes para N = %d. \n", ARRAY_SIZE);
    
    hashSolutionBenchmark();
    quickSortSolutionBenchmark();
    bubbleSortSolutionBenchmark();
    
    return 0;
}
