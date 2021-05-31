#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char palavra[256];

typedef struct No{
    int chave;
    struct No* prox;
}No;


void ler(char*);

int main()
{
    int n = 0;
    char str;
    char* arquivo = malloc(n * sizeof(char));

    fgets(palavra, 256, stdin);
    palavra[strlen(palavra)] = '\0';

    while ((str = getchar()) != '\n' && str != EOF)
    {
        n++;
        arquivo[n-1] = str;
    }
    arquivo[n] = '\0';
    ler(arquivo);

    free(arquivo);
    return 0;
}


void ler(char* arq)
{
    int contLin = 0;
    char c; char *tmp;

    size_t MAXLINE = 10001;
    tmp = malloc(MAXLINE * sizeof(tmp));
    No lista;

    FILE *fp;
    if ((fp = fopen(arq, "r")) == NULL)
    {
        fprintf(stderr,  "Erro no arquivo %s\n", arq);
        exit(1);
    }
    else
    {
        fp = fopen(arq, "r");
        while (getline(&tmp, &MAXLINE, fp) > 0)
        {

            if (strstr(tmp, palavra) == 0)
            {
                // adicionar a lista encadeada o numero da linha
                printf("%d\n", contLin);
                //printf("Achei");
                contLin++;
            }

            
        }

    }
}

void procura(char *palavra)
{

}