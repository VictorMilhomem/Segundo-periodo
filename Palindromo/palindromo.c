#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 256;
    char* palavra;
    palavra = malloc(n * sizeof(char));

    fgets(palavra, n, stdin);
    int tamanho = strlen(palavra);

    char invertida[tamanho-1];
    strcpy(invertida,palavra);


    for(int i = 0; i < (tamanho)/2; i++)
    {
        char tmp = invertida[i]; //armazena o character inicial
        invertida[i] = invertida[tamanho - i - 1]; //Troca o character da ponta oposta
        invertida[tamanho - i - 1] = tmp; //Armazena o character inicial no buffer
    }

    int comp = 0;
    for(int i = 0; i < (tamanho)/2; i++)
    {
        if (palavra[i] == invertida[i+1])
            comp++;
    }
    
    if(comp == tamanho/2)
        printf("SIM\n");
    else
        printf("NAO\n");

    return 0;
}

