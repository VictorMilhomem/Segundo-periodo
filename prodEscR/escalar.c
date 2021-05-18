#include <stdio.h>
#include <stdlib.h>

#include "vetor.h"


double produto_escalar(double *vetor, double *vetor2, int n)
{
    if (n > 0) {
        double prod = (vetor[n] * vetor2[n]);
        return prod + produto_escalar(vetor, vetor2, --n);
    }
    else return 0;
}
