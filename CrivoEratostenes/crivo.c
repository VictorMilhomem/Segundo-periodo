#include <stdio.h>
#define NMAX 1000000 // valor máximo para o valor máximo

int main() {
    int i, j, vetor[NMAX];
    int valorMaximo;

    scanf("%d", &valorMaximo);


    for (i=2; i<=valorMaximo; i++) {
        vetor[i]=i;
    }

    for (i=2; i<=valorMaximo; i++) {
        if (vetor[i]==i) {
            printf("%d\n", i);
            for (j=i+i; j<=valorMaximo; j+=i) {
                vetor[j]=0; // removendo da lista
            }
        }
    }

    return 0;
}