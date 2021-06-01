#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10001


// lista encadeada
typedef struct No{
    int chave;
    int valor;
    struct No* prox;
}No;

// listas encadeadas
No *cabeca = NULL;


// prototipos das funções
void ler(char* arq, char *palavra);
void procura(FILE *arq, char *palavra);

int main()
{
    int n = 0;
    char str;
    char* arquivo = malloc(n * sizeof(char));
    char* palavra;
    char *ptr;


    //fgets(palavra, 256, stdin);
    //palavra[strlen(palavra)] = '\0';

    while ((str = getchar()) != '\n' && str != EOF)
    {
        n++;
        arquivo[n-1] = str;
    }
    arquivo[n] = '\0';

    palavra = strtok(arquivo, " ");
    ptr = strtok(NULL, " ");

    //printf("%s %s\n", palavra, ptr);

    ler(ptr, palavra);

    free(arquivo);
    return 0;
}


void ler(char* arq, char *palavra)
{

    FILE *fp;
    if ((fp = fopen(arq, "r")) == NULL)
    {
        fprintf(stderr,  "Erro no arquivo %s\n", arq);
        exit(1);
    }
    else
    {
        fp = fopen(arq, "r");
        procura(fp, palavra);
    }
    fclose(fp);
}

void inserir(int chave, int valor)
{
    No *temp = malloc(sizeof(temp));

    temp->chave = chave;
    temp->valor = valor;

    temp->prox = cabeca;
    cabeca = temp;
}

No *deletar()
{
    No *temp = cabeca;

    cabeca = cabeca->prox;

    return temp;
}

int listaVazia()
{
    return cabeca == NULL;
}

void imprimeLista()
{
    No *pont = cabeca;
    while(pont != NULL)
    {
        printf("%d\n", pont->valor);
        pont = pont->prox;
    }
}


void procura(FILE *arq, char *palavra)
{
    int contLin = 0;
    char c; char str[MAX]; char *pos;
    int chave = 0;

    while (fgets(str, MAX, arq) != NULL)
    {
        contLin += 1;
        pos = strstr(str, palavra);
        if (pos != NULL)
        {
            // adicionar a lista encadeada o numero da linha
            inserir(chave, contLin);

            chave++;
            //printf("%d\n", contLin);
            //printf("Achei");
        }
        
    }
    imprimeLista();

    while(!listaVazia())
    {
        No *temp = deletar();
    }

}
