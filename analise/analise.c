#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ler(char*);

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
    return 0;
}


void ler(char* arq)
{
    int contChar = 0; int contLin = 0; int contImp = 0;
    char c;

    FILE *fp;
    if ((fp = fopen(arq, "r")) == NULL)
    {
        fprintf(stderr,  "Erro no arquivo %s\n", arq);
        exit(1);
    }
    else
    {
        fp = fopen(arq, "r");
        while (!feof(fp))
        {
            c = getc(fp);
            contChar++;

            if (c == '\n')
            {
                contLin++;
                contChar++;
            }
            
            if (c >= 32 && c <= 255) // primeiro e ultimo na tabela ascii imprimiveis
                contImp++;
        }

        printf("%d\n%d\n%d\n", contChar, contImp, contLin);

    }
}



