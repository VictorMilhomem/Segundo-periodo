#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalar.h"

double ler(char* arq, char* arq2)
{
    double c, c2;
    int n_vetor, n_vetor2;
    double prod;

    FILE *fp;
    FILE *fp2;
    if ((fp = fopen(arq, "r")) == NULL)
    {
        fprintf(stderr,  "Erro: arquivo do vetor 1 não foi encontrado\n");
        exit(1);
    }
    else if ((fp2 = fopen(arq2, "r")) == NULL)
    {
        fprintf(stderr, "Erro: arquivo do vetor 2 não foi encontrado\n");
        exit(1);
    }
    else
    {
        fp = fopen(arq, "r");
        fp2 = fopen(arq2, "r");
        
        int i = 0;
        double* vetor = malloc(50 * sizeof(vetor));
        double* vetor2 = malloc(50 * sizeof(vetor2));
        while (!feof(fp) && !feof(fp2))
        {
            
            fscanf(fp, "%lf\n", &c);
            fscanf(fp2, "%lf\n", &c2);

            *(vetor+i) = c;
            *(vetor2+i) = c2;
           
            i++;
        }

        n_vetor = vetor[0];
        n_vetor2 = vetor2[0];
        
        if (n_vetor != n_vetor2)
        {
            fprintf(stderr,  "Erro: os vetores possuem comprimentos distintos\n");
            exit(1);
        }
        else{
            prod = produto_escalar(vetor, vetor2, n_vetor);
            free(vetor); free(vetor2);
            vetor = vetor2 = NULL;
            
        }
    }
    fclose(fp);
    fclose(fp2);

    return prod;  

}

// modificar para retornar o nome do arquivo
char* nome_arquivo()
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

    return arquivo;
}