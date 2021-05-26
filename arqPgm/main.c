#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 1020

int matriz[MAX][MAX];
int n, m, max;

void ler(char* arq);
void converte();

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
    converte();
    return 0;
}

void ler(char* arq)
{
    char c[128]; int cont = 0;
    char comentario[500];

    FILE *fp;
    if ((fp = fopen(arq, "r")) == NULL)
    {
        fprintf(stderr,  "Erro: arquivo inexistente\n");
        exit(1);
    }
    else
    {
        fp = fopen(arq, "r");
        
        fscanf(fp, "%s", c) ;
        //fscanf(fp, "%s", comentario);
        if(strcmp(c,"P2") != 0) {
            printf("Arquivo nao e um PGM\n") ;
            fclose(fp) ;
            exit(2);
        }

        while(getc(fp) != '\n');          
        while (getc(fp) == '#')              
        {
          while (getc(fp) != '\n');          
        }

        fseek(fp, -1, SEEK_CUR);
        fscanf(fp, "%d %d %d", &m, &n, &max) ;
        for(int i=0; i<=n-1; i++)
            for(int j=0;j<=m-1;j++)
                fscanf(fp, " %d ", &matriz[i][j]);

    }
    fclose(fp);
    // debug
    //printf("%d\n ", matriz[1][2]);
    //printf("%d %d\n", m, n);
    //printf("%d\n", max);
}

void converte()
{
    for(int i=0; i<=n-1; i++)
    {
        for(int j=0;j<=m-1;j++)
            printf("%X", matriz[i][j]);
        printf("\n");
    }
}

