#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"


int main()
{
    char *arq = nome_arquivo();
    char *arq2 = nome_arquivo();

    double prod = ler(arq, arq2);

    free(arq);
    free(arq2);

    printf("%.3lf\n", prod);
   

    return 0;
}