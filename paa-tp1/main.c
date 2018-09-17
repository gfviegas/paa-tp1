//
//  main.c
//  paa-tp1
//
//  Created by Gustavo Viegas on 17/09/18.
//  Copyright © 2018 UFV Florestal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "intSet.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    srand((unsigned)time(NULL));
    //variaveis
    int vetor[TAMVETOR];
    int x;
    preencheVetor(&vetor[0], TAMVETOR);
    //qsort(&vetor[0], TAMVETOR, sizeof(int), comparador);
    bsort(&vetor[0], TAMVETOR);
    printf("Vetor ordenado de tamanho %d\n", TAMVETOR);
    imprimeVetor(&vetor[0], TAMVETOR);
    printf("Digite o x\n\n");
    scanf("%d", &x);
    printf("\n\n\n============================ TESTANDO A PESQUISA BINARIA===========\n\n\n %d encontrado no indice %d\n\n\n\n", x, buscaBinaria(&vetor[0], 0, TAMVETOR-1, x));
    printf("o x digitado foi %d\n\n", x);
    procuraX(&vetor[0], x);

    return 0;
}
