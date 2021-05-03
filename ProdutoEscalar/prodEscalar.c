#include <stdio.h>
#include <stdlib.h>

int prod(int);

int main()
{
    int n, prodEscalar;
    scanf("%d", &n);
    prodEscalar = prod(n);

    printf("%d\n", prodEscalar);
    return 0;
}


int prod(int n)
{
    int produto_escalar = 0;
    int *vetor1;
    int *vetor2;
    vetor1 = malloc(n * sizeof(int));
    vetor2 = malloc(n * sizeof(int));

    for(int k = 0; k < n; k++)
        scanf("%d", &vetor1[k]);
    for(int w = 0; w < n; w++)
        scanf("%d", &vetor2[w]);

    for (int i = 0 ; i < n; i++)
    {
        produto_escalar += vetor1[i]*vetor2[i];
    }
    return produto_escalar;    
}