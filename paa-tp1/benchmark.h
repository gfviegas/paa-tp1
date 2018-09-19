//
//  benchmark.h
//  paa-tp1
//
//  Created by Gustavo Viegas on 19/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#ifndef benchmark_h
#define benchmark_h

#include <stdio.h>
#include "intSet.h"
#include "hash.h"
#include "random.h"

#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)
#define CLOCKS_PER_US (CLOCKS_PER_MS / 1000)
#define TESTS_AMMOUNT 200

/**
 Executa uma bateria de {TESTS_AMMOUNT} testes, com vetores e valores de x aleatórios, utilizando a solução de tabela hash e calculando o valor médio de microsegundos gastos para encontrar dois elementos cuja soma seja um x aleátorio
 */
void hashSolutionBenchmark(void);


/**
 Executa uma bateria de {TESTS_AMMOUNT} testes, com vetores e valores de x aleatórios, utilizando a solução de ordenar o vetor com QuickSort e calculando o valor médio de milisegundos gastos para encontrar dois elementos cuja soma seja um x aleátorio com busca binária e para ordenar o vetor
 */
void quickSortSolutionBenchmark(void);


/**
 Executa uma bateria de {TESTS_AMMOUNT / 4} testes, com vetores e valores de x aleatórios, utilizando a solução de ordenar o vetor com BubbleSort e calculando o valor médio de milisegundos gastos para encontrar dois elementos cuja soma seja um x aleátorio com busca binária e para ordenar o vetor
 */
void bubbleSortSolutionBenchmark(void);


#endif /* benchmark_h */
