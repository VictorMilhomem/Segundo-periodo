#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "floodfill.h"

int main()
{
    int n = 0;
    char str;
    char* arquivo = malloc(n * sizeof(char));

    while ((str = getchar()) != '\n' && str != EOF)
    {
        n++;
        arquivo[n-1] = str;
    }
    arquivo[n] = '\0';
    ler(arquivo);
    aplica();
    
    return 0;
}

